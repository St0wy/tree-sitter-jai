// Grammar heavily based on the one from Odin : https://github.com/tree-sitter-grammars/tree-sitter-odin
/// <reference types="tree-sitter-cli/dsl" />
// @ts-nocheck

const PREC = {
	PARENTHESES: -1,
	ASSIGNMENT: 1,
	TERNARY: 2,
	LOGICAL_OR: 3,
	LOGICAL_AND: 4,
	COMPARE: 5,
	EQUALITY: 6,
	BITWISE_OR: 7,
	BITWISE_XOR: 8,
	BITWISE_AND: 9,
	BITWISE_AND_NOT: 10,
	SHIFT: 11,
	ADD: 12,
	MULTIPLY: 13,
	CAST: 14,
	IN: 15,
	UNARY: 16,
	CALL: 17,
	MEMBER: 18,
	MATRIX: 19,
	VARIADIC: 20,
};

module.exports = grammar({
	name: "jai",

	conflicts: $ => [
		[$.type, $.expression],
	],

	externals: $ => [
		$._newline,
		$._backslash,
		$._nl_comma,
		$.float,
		$.block_comment,
		'{',
		'"',
	],

	extras: $ => [
		$.comment,
		$.block_comment,
		/\s/,
		$._backslash,
	],

	supertypes: $ => [
		$.declaration,
		$.expression,
		$.literal,
		$.statement,
	],

	word: $ => $.identifier,

	rules: {
		source_file: $ => seq(repeat(seq($.declaration, $._separator)), optional($.declaration)),

		declaration: $ => choice(
			$.procedure_declaration,
			$.struct_declaration,
			$.variable_declaration,
			$.var_declaration,
			$.const_declaration,
			$.expression
		),

		procedure_declaration: $ => seq(
			$.identifier,
			'::',
			$.procedure,
		),

		procedure: $ => prec.right(seq(
			$.parameters,
			optional(seq(
				'->',
				choice(
					seq('(', commaSep1(choice($.type, $.named_type)), ')'),
					commaSep1(choice($.type, $.named_type)),
				)

			)),
			optional($.block),
		)),

		block: $ => prec(2, seq(
			'{',
			sep($.statement, ';'),
			'}',
		)),

		parameters: $ => seq(
			'(',
			optional(seq(
				commaSep1(choice($.parameter, $.default_parameter)),
				optional(','),
			)),
			')',
		),
		parameter: $ => prec.right(seq(
			seq(
				choice(
					$.identifier,
					// $.variadic_type,
					// $.array_type,
					// $.pointer_type,
					// $.field_type,
					// $._procedure_type,
				),
				':',
				$.type,
				optional(seq('=', $.expression))
			),
		)),
		default_parameter: $ => seq(
			$.identifier,
			':=',
			$.expression,
		),

		struct_declaration: $ => seq(
			$.identifier,
			'::',
			'struct',
			'{',
			optional(repeat(
				seq(choice($.field, $.default_value_assignment, $.const_declaration), ';'),
			)),
			'}',
		),
		field: $ => prec(2, prec.right(choice(
			// Field is either `identifier : type [: or =] something;` ...
			seq(commaSep1($.identifier), ':', seq($.type, optional(seq(choice('=', ':'), commaSep1($.expression))))),
			// ...or `identifier := something`.
			seq(commaSep1($.identifier), ':=', commaSep1($.expression), optional(','))
		))),
		default_value_assignment: $ => seq(
			commaSep1($.identifier),
			'=',
			commaSep1($.expression),
		),

		var_declaration: $ => prec.left(seq(
			commaSep1($.identifier),
			":",
			seq($.type, optional(seq(choice('=', ':'), commaSep1($.expression)))),
		)),

		variable_declaration: $ => prec.left(seq(
			commaSep1($.identifier),
			':=',
			commaSep1($.expression),
			optional(','),
		)),

		expression: $ => prec.left(choice(
			$.unary_expression,
			$.binary_expression,
			// $.ternary_expression,
			$.call_expression,
			// $.selector_call_expression,
			$.member_expression,
			$.index_expression,
			// $.slice_expression,
			// $.range_expression,
			// $.cast_expression,
			$.if_expression,
			$.parenthesized_expression,
			// $.in_expression,
			// $.variadic_expression,
			// $.or_return_expression,
			// $.or_continue_expression,
			// $.or_break_expression,
			$.identifier,
			$.address,
			// $.map_type,
			// $.distinct_type,
			// $.matrix_type,
			$.literal
		)),

		unary_expression: $ => prec.right(PREC.UNARY, seq(
			field('operator', choice('+', '-', '~', '!', '&')),
			field('argument', $.expression),
		)),

		binary_expression: $ => {
			const table = [
				['||', PREC.LOGICAL_OR],
				['or_else', PREC.LOGICAL_OR],
				['&&', PREC.LOGICAL_AND],
				['>', PREC.COMPARE],
				['>=', PREC.COMPARE],
				['<=', PREC.COMPARE],
				['<', PREC.COMPARE],
				['==', PREC.EQUALITY],
				['!=', PREC.EQUALITY],
				['~=', PREC.EQUALITY],
				['|', PREC.BITWISE_OR],
				['~', PREC.BITWISE_XOR],
				['&', PREC.BITWISE_AND],
				['&~', PREC.BITWISE_AND_NOT],
				['<<', PREC.SHIFT],
				['>>', PREC.SHIFT],
				['+', PREC.ADD],
				['-', PREC.ADD],
				['*', PREC.MULTIPLY],
				['/', PREC.MULTIPLY],
				['%', PREC.MULTIPLY],
				['%%', PREC.MULTIPLY],
			];

			return choice(...table.map(([operator, precedence]) => {
				return prec.left(precedence, seq(
					field('left', $.expression),
					// @ts-ignore
					field('operator', operator),
					field('right', $.expression),
				));
			}));
		},

		parenthesized_expression: $ => seq('(', $.expression, ')'),

		call_expression: $ => prec.left(PREC.CALL, seq(
			field('function', $.identifier),
			'(',
			optional(seq(
				commaSep1(seq(
					field('argument', choice($.expression, $.array_type/*, $.struct_type, $.pointer_type*/, $.procedure)),
					optional(seq('=', choice($.expression))),
				)),
				optional(','),
			)),
			')',
		)),

		member_expression: $ => prec.left(PREC.MEMBER, seq(
			optional($.identifier),
			'.',
			$.identifier,
		)),

		index_expression: $ => prec.left(PREC.MEMBER, seq(
			$.expression,
			'[',
			$.expression,
			// optional(seq(',', $.expression)), not sure if jai has that
			']',
		)),

		if_expression: $ => prec.right(seq(
			'ifx',
			field('condition', $.expression),
			optional('then'),
			field('consequence', $.statement),
			optional(field('alternative', $.else_clause)),
		)),

		statement: $ => prec(1, choice(
			$.procedure_declaration,
			// $.overloaded_procedure_declaration,
			$.struct_declaration,
			// $.enum_declaration,
			// $.union_declaration,
			// $.bit_field_declaration,
			$.const_declaration,
			// $.import_declaration,
			$.assignment_statement,
			$.update_statement,
			$.if_statement,
			$.while_statement,
			$.for_statement,
			$.if_case_statement,
			$.defer_statement,
			$.break_statement,
			// $.continue_statement,
			// $.fallthrough_statement,
			// $.label_statement,
			// $.using_statement,
			$.return_statement,
			$.expression,
			$.var_declaration,
			$.variable_declaration,
			// $.foreign_block,
			// $.tagged_block,
			$.block,
		)),

		assignment_statement: $ => prec.left(PREC.ASSIGNMENT, seq(
			commaSep1($.identifier),
			'=',
			commaSep1(choice($.expression, $.procedure)),
		)),

		update_statement: $ => prec.left(seq(
			commaSep1($.identifier),
			choice('+=', '-=', '*=', '/=', '%=', '&=', '|=', '^=', '<<=', '>>=', '||=', '&&=', '&~='),
			commaSep1($.expression),
		)),

		if_statement: $ => prec.right(seq(
			'if',
			field('condition', $.expression),
			optional('then'),
			field('consequence', $.statement),
			optional(field('alternative', $.else_clause)),
		)),
		else_clause: $ => seq('else', $.statement),

		if_case_statement: $ => seq(
			'if',
			$.expression,
			'==',
			'{',
			repeat($.switch_case),
			'}',
		),
		switch_case: $ => seq(
			'case',
			optional(field('condition', $.expression)),
			';',
			choice(
				$.through_statement,
				$.statement,
			),
			';'
		),

		while_statement: $ => seq(
			'while',
			optional(field('name', seq(
				$.identifier,
				':='
			))),
			field('condition', $.expression),
			field('body', $.statement),
		),

		for_statement: $ => seq(
			'for',
			optional('<'),
			optional('*'),
			optional(seq($.identifier, ':')),
			choice(
				$.range,
				$.identifier,
			),
			field('body', $.statement),
		),

		range: $ => prec.left(PREC.MEMBER, seq(
			$.expression,
			'..',
			$.expression,
		)),

		break_statement: $ => prec.right(seq('break', optional($.identifier))),

		continue_statement: $ => seq('continue', optional($.identifier)),

		defer_statement: $ => seq('defer', $.statement),

		through_statement: $ => '#through',

		return_statement: $ => prec.right(1, seq(
			'return',
			optional(commaSep1($.expression /*choice( , $._procedure_type )*/)),
		)),

		literal: $ => prec.right(choice(
			$.struct,
			$.float,
			$.number,
			$.string,
			$.array_litteral,
			// $.character,
			$.boolean,
			$.null,
			$.uninitialized,
		)),

		struct: $ => seq(
			optional(
				choice(
					seq('(', $.type, ')'),
					$.type,
				),
			),
			'.',
			'{',
			optional(seq(
				commaSep1($.struct_field),
				optional(','),
			)),
			'}',
		),
		struct_field: $ => prec.right(seq(
			$.expression,
			optional(seq(
				'=',
				choice($.expression/*, $._procedure_type*/),
			)),
		)),

		array_litteral: $ => seq(
			optional(
				choice(
					seq('(', $.type, ')'),
					$.type,
				),
			),
			'.',
			'[',
			optional(seq(
				commaSep1($.expression),
				optional(','),
			)),
			']',
		),

		string: $ => $._string_literal,

		_string_literal: $ => seq(
			'"',
			repeat(choice(
				$.string_content,
				$.escape_sequence,
			)),
			'"',
		),

		string_content: _ => token.immediate(prec(1, /[^"\\]+/)),

		escape_sequence: _ => token.immediate(seq(
			'\\',
			choice(
				/[^xu0-7]/,
				/[0-7]{1,3}/,
				/x[0-9a-fA-F]{2}/,
				/u[0-9a-fA-F]{4}/,
				/u\{[0-9a-fA-F]+\}/,
				/U[0-9a-fA-F]{8}/,
			),
		)),

		boolean: _ => choice('true', 'false'),

		null: _ => 'null',

		uninitialized: _ => '---',

		// TODO : Differentiate between taking the address of a variable and pointer types
		address: $ => seq('*', $.expression),

		type: $ => prec.right(choice(
			"bool",
            "string",
            "int",
            "float",
            "float64",
            "float32",
            "s64",
            "s32",
            "s16",
            "s8",
            "u64",
            "u32",
            "u16",
            "u8",
			$.identifier,
			$.pointer_type,
			// $.variadic_type,
			$.array_type,
			// $.map_type,
			// $.union_type,
			// $.bit_set_type,
			// $.matrix_type,
			// $.field_type,
			// $.tuple_type,
			// $.struct_type,
			// $.enum_type,
			// $.bit_field_type,
			// $.constant_type,
			// $.specialized_type,
			// $._procedure_type,
			// $.distinct_type,
			// $.empty_type,
			// $.polymorphic_type,
			// $.conditional_type,
			// '...',
		)),

		pointer_type: $ => prec.left(seq('*', $.type)),

		array_type: $ => prec.right(1, seq(
			'[',
			optional(seq(choice('..', $.expression))),
			']',
			optional($.type),
		)),

		named_type: $ => prec.right(seq($.identifier, ':', $.type, optional(seq('=', $.literal)))),

		const_declaration: $ => prec.right(seq(
			commaSep1($.identifier),
			'::',
			// optional($.tag),
			commaSep1(
				$.expression
			),
		)),

		identifier: _ => /[_\p{XID_Start}][_\p{XID_Continue}]*/,
		number: _ => {
			const decimal = /[0-9][0-9_]?/;
			const hex = /0[xh][0-9a-fA-F_]?/;
			const octal = /0o[0-7][0-7]?/;
			const binary = /0b[01][01_]?/;
			// no float

			return token(choice(
				seq(optional('-'), decimal),
				seq(optional('-'), hex),
				seq(optional('-'), octal),
				seq(optional('-'), binary),
			));
		},

		_separator: $ => choice(
			$._newline,
			';',
		),

		comment: _ => token(seq('//', /[^\r\n]*/)),
	}
});

/**
 * Creates a rule to match one or more of the rules separated by a comma
 *
 * @param {Rule} rule
 *
 * @return {SeqRule}
 *
 */
function commaSep1(rule) {
	return sep1(rule, ',');
}

/**
 * Creates a rule to match one or more of the rules separated by a comma
 *
 * @param {Rule} rule
 *
 * @param {GrammarSymbols<any>} $
 *
 * @return {SeqRule}
 *
 */
function commaExternalSep1(rule, $) {
	return sep1(rule, choice(',', alias($._nl_comma, ',')));
}

/**
 * Creates a rule to match zero or more occurrences of `rule` separated by `sep`
 *
 * @param {RegExp|Rule|String} rule
 *
 * @param {RegExp|Rule|String} sep
 *
 * @return {ChoiceRule}
 *
 */
function sep(rule, sep) {
	return optional(seq(rule, repeat(seq(sep, optional(rule)))));
}

/**
 * Creates a rule to match one or more occurrences of `rule` separated by `sep`
 *
 * @param {RegExp|Rule|String} rule
 *
 * @param {RegExp|Rule|String} sep
 *
 * @return {SeqRule}
 *
 */
function sep1(rule, sep) {
	return seq(rule, repeat(seq(sep, rule)));
}
