#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include "lexer.h"
#include "types.h"

typedef struct Parser
{
    Lexer *lexer;
    Token current_token;
} Parser;

void parser_initialize(Parser *parser, Lexer *lexer);

Node *parser_parse_expression(Parser *parser, Precedence previous_precedence);

#endif