#ifndef PARSER_H
#define PARSER_H
#include "lexer.h"
#include "types.h"

typedef struct Parser
{
    Lexer *lexer;
    Token *token;
} Parser;

#endif