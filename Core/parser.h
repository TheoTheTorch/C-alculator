#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "types.h"

typedef struct Parser
{
    Token* start;
    Token* current;
} Parser;

typedef enum {
    Precedence_Min,

    Precedence_Term,
    Precedence_Factor,
    Precedence_Power,

    Precedence_Max,
} Precedence;

void parser_initialize(Parser* parser, Token* start);

void parser_advance(Parser* parser);

Node* parser_parse_number(Parser* parser);

Node* parser_parse_infix_expression(Parser parser, Token operator, Node* left);

Node* parser_parse_expression(Parser* parser, Precedence previous_precedence);

#endif