#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include "types.h"

typedef struct Parser
{
    void *context;
    Token (*advance) (void *context);
    Token current_token;
} Parser;

void parser_initialize(Parser *parser, void *context, Token (*advance) (void *context));

Node *parser_parse_expression(Parser *parser, Precedence previous_precedence);

#endif