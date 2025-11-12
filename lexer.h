#ifndef LEXER_H
#define LEXER_H

#define MAX_NUMBER_DIGITS 32 // maximum number of characters we allow for parsing numbers

typedef enum {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MODULO,
} Operation;

typedef enum {
    NUMBER,
    OPERATION,
} NodeTypes;

typedef union {
    double numeric_value;
    char operation;
} Data;

typedef struct {
    NodeTypes type;
    Data data;
} Token;

Token *lexer(const char expression[], int *token_count);

#endif