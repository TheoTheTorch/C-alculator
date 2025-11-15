#ifndef LEXER_H
#define LEXER_H
#include "types.h"

typedef struct Lexer
{
    char* start;
    char* current;
} Lexer;

// Lexer functions
// ---------------
void lexer_initialize(Lexer* lexer, char* expression_start);

void lexer_advance(Lexer* lexer);

void lexer_skip_whitespace(Lexer* lexer);

Token lexer_number(Lexer* lexer);

Token lexer_create_token(Lexer* lexer, TokenType type);

Token lexer_next_token(Lexer* lexer);
// ---------------

// Tokenizer utilities
// -------------------
Token* tokenize(char* expression);

void free_tokens(Token* token);

void print_tokens(Token* tokens);
// -------------------

#endif