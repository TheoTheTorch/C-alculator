#ifndef PARSER_H
#define PARSER_H

#include <string.h>
#include <stdlib.h>
#include "lexer.h"
#include "types.h"

typedef struct Parser
{
    Token *start;
    Token *current;
} Parser;

void parser_initialize(Parser *parser, Token *start);

void parser_advance(Parser *parser);

Node *parser_parse_terminal_expression(Parser *parser);

Node *parser_parse_infix_expression(Parser *parser, Token operator, Node *left);

Node *parser_parse_expression(Parser *parser, Precedence previous_precedence);

#endif