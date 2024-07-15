module.exports = grammar({
    name: "Jai",

    rules: {
        source_file: $ => repeat($._definition),

        directive: $ => seq(
            "#",
            $.identifier,
        ),

        importOrLoad: $ => seq(
            $.directive,
            "\"",
            /.+/,
            "\"",
            ";"
        ),

        comment: $ => token(choice(
            seq('//', /.*/),
            seq(
                '/*',
                /[^*]*\*+([^/*][^*]*\*+)*/,
                '/'
            )
        )),

        _definition: $ => choice(
            // $.importOrLoad,
            // $.function_definition,
            $.variable_definition,
            $.comment,
            // TODO: other kinds of definitions
        ),

        variable_definition: $ => seq(
            field("name", $.identifier),
            ":",
            choice(
                seq(
                    field("type", $._type),
                    "=",
                    field("value", $.simple_expression),
                ),
                seq(
                    "=",
                    field("value", $.simple_expression),
                ),
                field("type", $._type),
            ),
            ";"
        ),

        function_definition: $ => seq(
            $.identifier,
            "::",
            $.parameter_list,
            $.block
        ),

        parameter_list: $ => seq(
            "(",
            // TODO: parameters
            ")"
        ),

        _type: $ => choice(
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
            $.identifier
            // TODO: other kinds of types
        ),

        block: $ => seq(
            "{",
            repeat($._statement),
            "}"
        ),

        _statement: $ => choice(
            $.return_statement,
            $._definition
            // TODO: other kinds of statements
        ),

        return_statement: $ => seq(
            "return",
            $._expression,
            ";"
        ),

        _expression: $ => choice(
            $.identifier,
            $.number
            // TODO: other kinds of expressions
        ),


        simple_expression: $ => choice(
            $.identifier,
            $.number,
            $.float,
        ),

        identifier: $ => /[a-zA-Z_]+/,
        number: $ => /\d+/,
        float: $ => /\d+\.\d+/
    }
});