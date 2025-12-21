#ifndef LEXER_H
#define LEXER_H

#include <ctype.h>
#include "types.h"

typedef struct Lexer
{
    char *start;
    char *current;
} Lexer;

void lexer_initialize(Lexer *lexer, char *expression);

Token lexer_next_token(Lexer *lexer);

#endif