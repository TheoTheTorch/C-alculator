#ifndef TOKENIZE_H
#define TOKENIZE_H
#include "types.h"

Token* tokenize(char* expression);

void free_tokens(Token* token);

void print_tokens(Token* tokens);

#endif