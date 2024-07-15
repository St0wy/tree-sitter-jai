#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 16
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 36
#define ALIAS_COUNT 0
#define TOKEN_COUNT 30
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 4

enum ts_symbol_identifiers {
  anon_sym_POUND = 1,
  anon_sym_DQUOTE = 2,
  anon_sym_SEMI = 3,
  sym_comment = 4,
  anon_sym_COLON = 5,
  anon_sym_EQ = 6,
  anon_sym_COLON_COLON = 7,
  anon_sym_LPAREN = 8,
  anon_sym_RPAREN = 9,
  anon_sym_bool = 10,
  anon_sym_string = 11,
  anon_sym_int = 12,
  anon_sym_float = 13,
  anon_sym_float64 = 14,
  anon_sym_float32 = 15,
  anon_sym_s64 = 16,
  anon_sym_s32 = 17,
  anon_sym_s16 = 18,
  anon_sym_s8 = 19,
  anon_sym_u64 = 20,
  anon_sym_u32 = 21,
  anon_sym_u16 = 22,
  anon_sym_u8 = 23,
  anon_sym_LBRACE = 24,
  anon_sym_RBRACE = 25,
  anon_sym_return = 26,
  sym_identifier = 27,
  sym_number = 28,
  sym_float = 29,
  sym_source_file = 30,
  sym__definition = 31,
  sym_variable_definition = 32,
  sym__type = 33,
  sym_simple_expression = 34,
  aux_sym_source_file_repeat1 = 35,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_POUND] = "#",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SEMI] = ";",
  [sym_comment] = "comment",
  [anon_sym_COLON] = ":",
  [anon_sym_EQ] = "=",
  [anon_sym_COLON_COLON] = "::",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_bool] = "bool",
  [anon_sym_string] = "string",
  [anon_sym_int] = "int",
  [anon_sym_float] = "float",
  [anon_sym_float64] = "float64",
  [anon_sym_float32] = "float32",
  [anon_sym_s64] = "s64",
  [anon_sym_s32] = "s32",
  [anon_sym_s16] = "s16",
  [anon_sym_s8] = "s8",
  [anon_sym_u64] = "u64",
  [anon_sym_u32] = "u32",
  [anon_sym_u16] = "u16",
  [anon_sym_u8] = "u8",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_return] = "return",
  [sym_identifier] = "identifier",
  [sym_number] = "number",
  [sym_float] = "float",
  [sym_source_file] = "source_file",
  [sym__definition] = "_definition",
  [sym_variable_definition] = "variable_definition",
  [sym__type] = "_type",
  [sym_simple_expression] = "simple_expression",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [sym_comment] = sym_comment,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_COLON_COLON] = anon_sym_COLON_COLON,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_bool] = anon_sym_bool,
  [anon_sym_string] = anon_sym_string,
  [anon_sym_int] = anon_sym_int,
  [anon_sym_float] = anon_sym_float,
  [anon_sym_float64] = anon_sym_float64,
  [anon_sym_float32] = anon_sym_float32,
  [anon_sym_s64] = anon_sym_s64,
  [anon_sym_s32] = anon_sym_s32,
  [anon_sym_s16] = anon_sym_s16,
  [anon_sym_s8] = anon_sym_s8,
  [anon_sym_u64] = anon_sym_u64,
  [anon_sym_u32] = anon_sym_u32,
  [anon_sym_u16] = anon_sym_u16,
  [anon_sym_u8] = anon_sym_u8,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_return] = anon_sym_return,
  [sym_identifier] = sym_identifier,
  [sym_number] = sym_number,
  [sym_float] = sym_float,
  [sym_source_file] = sym_source_file,
  [sym__definition] = sym__definition,
  [sym_variable_definition] = sym_variable_definition,
  [sym__type] = sym__type,
  [sym_simple_expression] = sym_simple_expression,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bool] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_string] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_s64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_s32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_s16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_s8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_float] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__definition] = {
    .visible = false,
    .named = true,
  },
  [sym_variable_definition] = {
    .visible = true,
    .named = true,
  },
  [sym__type] = {
    .visible = false,
    .named = true,
  },
  [sym_simple_expression] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_name = 1,
  field_type = 2,
  field_value = 3,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_name] = "name",
  [field_type] = "type",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 2},
  [3] = {.index = 4, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 0},
    {field_type, 2},
  [2] =
    {field_name, 0},
    {field_value, 3},
  [4] =
    {field_name, 0},
    {field_type, 2},
    {field_value, 4},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(35);
      ADVANCE_MAP(
        '"', 37,
        '#', 36,
        '(', 45,
        ')', 46,
        '/', 1,
        ':', 42,
        ';', 38,
        '=', 43,
        'b', 25,
        'f', 20,
        'i', 21,
        'r', 16,
        's', 4,
        'u', 5,
        '{', 65,
        '}', 66,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      END_STATE();
    case 1:
      if (lookahead == '*') ADVANCE(3);
      if (lookahead == '/') ADVANCE(40);
      END_STATE();
    case 2:
      if (lookahead == '*') ADVANCE(2);
      if (lookahead == '/') ADVANCE(39);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(2);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '1') ADVANCE(12);
      if (lookahead == '3') ADVANCE(6);
      if (lookahead == '6') ADVANCE(9);
      if (lookahead == '8') ADVANCE(60);
      if (lookahead == 't') ADVANCE(27);
      END_STATE();
    case 5:
      if (lookahead == '1') ADVANCE(13);
      if (lookahead == '3') ADVANCE(7);
      if (lookahead == '6') ADVANCE(10);
      if (lookahead == '8') ADVANCE(64);
      END_STATE();
    case 6:
      if (lookahead == '2') ADVANCE(58);
      END_STATE();
    case 7:
      if (lookahead == '2') ADVANCE(62);
      END_STATE();
    case 8:
      if (lookahead == '2') ADVANCE(56);
      END_STATE();
    case 9:
      if (lookahead == '4') ADVANCE(57);
      END_STATE();
    case 10:
      if (lookahead == '4') ADVANCE(61);
      END_STATE();
    case 11:
      if (lookahead == '4') ADVANCE(55);
      END_STATE();
    case 12:
      if (lookahead == '6') ADVANCE(59);
      END_STATE();
    case 13:
      if (lookahead == '6') ADVANCE(63);
      END_STATE();
    case 14:
      if (lookahead == '=') ADVANCE(43);
      if (lookahead == 'b') ADVANCE(78);
      if (lookahead == 'f') ADVANCE(74);
      if (lookahead == 'i') ADVANCE(75);
      if (lookahead == 's') ADVANCE(68);
      if (lookahead == 'u') ADVANCE(69);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(31);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(30);
      END_STATE();
    case 17:
      if (lookahead == 'g') ADVANCE(49);
      END_STATE();
    case 18:
      if (lookahead == 'i') ADVANCE(22);
      END_STATE();
    case 19:
      if (lookahead == 'l') ADVANCE(47);
      END_STATE();
    case 20:
      if (lookahead == 'l') ADVANCE(24);
      END_STATE();
    case 21:
      if (lookahead == 'n') ADVANCE(29);
      END_STATE();
    case 22:
      if (lookahead == 'n') ADVANCE(17);
      END_STATE();
    case 23:
      if (lookahead == 'n') ADVANCE(67);
      END_STATE();
    case 24:
      if (lookahead == 'o') ADVANCE(15);
      END_STATE();
    case 25:
      if (lookahead == 'o') ADVANCE(26);
      END_STATE();
    case 26:
      if (lookahead == 'o') ADVANCE(19);
      END_STATE();
    case 27:
      if (lookahead == 'r') ADVANCE(18);
      END_STATE();
    case 28:
      if (lookahead == 'r') ADVANCE(23);
      END_STATE();
    case 29:
      if (lookahead == 't') ADVANCE(51);
      END_STATE();
    case 30:
      if (lookahead == 't') ADVANCE(32);
      END_STATE();
    case 31:
      if (lookahead == 't') ADVANCE(53);
      END_STATE();
    case 32:
      if (lookahead == 'u') ADVANCE(28);
      END_STATE();
    case 33:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(85);
      END_STATE();
    case 34:
      if (eof) ADVANCE(35);
      if (lookahead == '/') ADVANCE(1);
      if (lookahead == ':') ADVANCE(41);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(34);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(40);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(44);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_bool);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_string);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_int);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_float);
      if (lookahead == '3') ADVANCE(8);
      if (lookahead == '6') ADVANCE(11);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_float);
      if (lookahead == '3') ADVANCE(8);
      if (lookahead == '6') ADVANCE(11);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_float64);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_float32);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_s64);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_s32);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_s16);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_s8);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_u64);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_u32);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_u16);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_u8);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1') ADVANCE(12);
      if (lookahead == '3') ADVANCE(6);
      if (lookahead == '6') ADVANCE(9);
      if (lookahead == '8') ADVANCE(60);
      if (lookahead == 't') ADVANCE(80);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1') ADVANCE(13);
      if (lookahead == '3') ADVANCE(7);
      if (lookahead == '6') ADVANCE(10);
      if (lookahead == '8') ADVANCE(64);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(82);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(76);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(48);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(81);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(71);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(70);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(79);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(73);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(72);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(52);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_identifier);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(33);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_float);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(85);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 34},
  [2] = {.lex_state = 14},
  [3] = {.lex_state = 34},
  [4] = {.lex_state = 34},
  [5] = {.lex_state = 34},
  [6] = {.lex_state = 34},
  [7] = {.lex_state = 34},
  [8] = {.lex_state = 34},
  [9] = {.lex_state = 34},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 34},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_COLON_COLON] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_bool] = ACTIONS(1),
    [anon_sym_string] = ACTIONS(1),
    [anon_sym_int] = ACTIONS(1),
    [anon_sym_float] = ACTIONS(1),
    [anon_sym_float64] = ACTIONS(1),
    [anon_sym_float32] = ACTIONS(1),
    [anon_sym_s64] = ACTIONS(1),
    [anon_sym_s32] = ACTIONS(1),
    [anon_sym_s16] = ACTIONS(1),
    [anon_sym_s8] = ACTIONS(1),
    [anon_sym_u64] = ACTIONS(1),
    [anon_sym_u32] = ACTIONS(1),
    [anon_sym_u16] = ACTIONS(1),
    [anon_sym_u8] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [sym_float] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(12),
    [sym__definition] = STATE(3),
    [sym_variable_definition] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_comment] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(9), 1,
      anon_sym_EQ,
    STATE(10), 1,
      sym__type,
    ACTIONS(11), 5,
      anon_sym_bool,
      anon_sym_string,
      anon_sym_int,
      anon_sym_float,
      sym_identifier,
    ACTIONS(13), 10,
      anon_sym_float64,
      anon_sym_float32,
      anon_sym_s64,
      anon_sym_s32,
      anon_sym_s16,
      anon_sym_s8,
      anon_sym_u64,
      anon_sym_u32,
      anon_sym_u16,
      anon_sym_u8,
  [26] = 4,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(17), 1,
      sym_comment,
    STATE(4), 3,
      sym__definition,
      sym_variable_definition,
      aux_sym_source_file_repeat1,
  [41] = 4,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(21), 1,
      sym_comment,
    ACTIONS(24), 1,
      sym_identifier,
    STATE(4), 3,
      sym__definition,
      sym_variable_definition,
      aux_sym_source_file_repeat1,
  [56] = 3,
    ACTIONS(29), 1,
      sym_number,
    STATE(14), 1,
      sym_simple_expression,
    ACTIONS(27), 2,
      sym_identifier,
      sym_float,
  [67] = 3,
    ACTIONS(29), 1,
      sym_number,
    STATE(15), 1,
      sym_simple_expression,
    ACTIONS(27), 2,
      sym_identifier,
      sym_float,
  [78] = 1,
    ACTIONS(31), 3,
      ts_builtin_sym_end,
      sym_comment,
      sym_identifier,
  [84] = 1,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_comment,
      sym_identifier,
  [90] = 1,
    ACTIONS(35), 3,
      ts_builtin_sym_end,
      sym_comment,
      sym_identifier,
  [96] = 2,
    ACTIONS(37), 1,
      anon_sym_SEMI,
    ACTIONS(39), 1,
      anon_sym_EQ,
  [103] = 1,
    ACTIONS(41), 1,
      anon_sym_COLON,
  [107] = 1,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
  [111] = 1,
    ACTIONS(45), 1,
      anon_sym_SEMI,
  [115] = 1,
    ACTIONS(47), 1,
      anon_sym_SEMI,
  [119] = 1,
    ACTIONS(49), 1,
      anon_sym_SEMI,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 26,
  [SMALL_STATE(4)] = 41,
  [SMALL_STATE(5)] = 56,
  [SMALL_STATE(6)] = 67,
  [SMALL_STATE(7)] = 78,
  [SMALL_STATE(8)] = 84,
  [SMALL_STATE(9)] = 90,
  [SMALL_STATE(10)] = 96,
  [SMALL_STATE(11)] = 103,
  [SMALL_STATE(12)] = 107,
  [SMALL_STATE(13)] = 111,
  [SMALL_STATE(14)] = 115,
  [SMALL_STATE(15)] = 119,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [21] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [24] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_definition, 4, 0, 1),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_definition, 5, 0, 2),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_definition, 6, 0, 3),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [43] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_simple_expression, 1, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_Jai(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
