module.exports = grammar({
	name: "jai",

	rules: {
		source_file: $ => seq(repeat(seq($.declaration, $._separator)), optional($.declaration)),

		declaration: $ => choice(
			// $.variable_definition,
			$.var_declaration,
			// $.importOrLoad,
			// $.function_definition,
			// $.comment,
			// $._expression_no_tag,
		),

		var_declaration: $ => seq(
			commaSep1($.expression),
			":",
			seq($.type),
		),

		expression: $ => prec.left(choice(
			$._expression_no_tag,
			$.tag,
		)),

		_expression_no_tag: $ => choice(
			// $.unary_expression,
			// $.binary_expression,
			// $.ternary_expression,
			// $.call_expression,
			// $.selector_call_expression,
			// $.member_expression,
			// $.index_expression,
			// $.slice_expression,
			// $.range_expression,
			// $.cast_expression,
			// $.parenthesized_expression,
			// $.in_expression,
			// $.variadic_expression,
			// $.or_return_expression,
			// $.or_continue_expression,
			// $.or_break_expression,
			$.identifier,
			// $.address,
			// $.map_type,
			// $.distinct_type,
			// $.matrix_type,
			$.literal,
			'?',
		),

		literal: $ => prec.right(choice(
			// $.struct,
			$.float,
			$.number,
			$.string,
			// $.character,
			$.boolean,
			$.null,
			$.uninitialized,
		)),

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

		tag: _ => token(seq(/#[a-zA-Z_][a-zA-Z0-9_]*/, optional(seq('(', /\w*/, ')')))),

		type: $ => prec.right(choice(
			$.identifier,
			// $.pointer_type,
			// $.variadic_type,
			// $.array_type,
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

		identifier: _ => /[_\p{XID_Start}][_\p{XID_Continue}]*/,
		number: _ => {
			const decimal = /[0-9][0-9_]*[ijk]?/;
			const hex = /0[xh][0-9a-fA-F_]+[ijk]?/;
			const octal = /0o[0-7][0-7]*[ijk]?/;
			const binary = /0b[01][01_]*[ijk]?/;
			// no float

			return token(choice(
				seq(optional('-'), decimal),
				seq(optional('-'), hex),
				seq(optional('-'), octal),
				seq(optional('-'), binary),
			));
		},
		float: $ => /\d+\.\d+/,

		_separator: $ => choice(
			// $._newline,
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
