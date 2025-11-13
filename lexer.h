#ifndef LEXER_H
#define LEXER_H
#include "types.h"

#define MAX_NUMBER_DIGITS 32 // maximum number of characters we allow for parsing numbers

Token *lexer(const char expression[], int *token_count);

#endif