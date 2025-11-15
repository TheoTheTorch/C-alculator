#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "types.h"

typedef struct Parser
{
    int token_count;
    Token* start;
    Token* current;
} Parser;

void parser_initialize(Parser* parser, char* expression_start);

void parser_advance(Parser* parser);

Token parser_number(Parser* parser);

Token parser_create_node(Parser* parser, TokenType type);

Token parser_next_node(Parser* parser);

#endif