#ifndef TOKENIZE_H
#define TOKENIZE_H
#include "types.h"

Token* tokenize(char* expression);

int count_tokens(Token* tokens);

void free_tokens(Token* token);

void print_tokens(Token* tokens);

#endif