#ifndef LEXER_H
#define LEXER_H
#include "types.h"

typedef struct Lexer
{
    char* start;
    char* current;
} Lexer;

void lexer_initialize(Lexer* lexer, char *expression_start);

Token lexer_advance(Lexer* lexer);

Token lexer_create_token(Lexer* lexer, TokenType type);

void lexer_next_token(Lexer* lexer);

#endif