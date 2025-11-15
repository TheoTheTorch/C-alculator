#include <string.h>

#ifndef TYPES_H
#define TYPES_H

typedef enum {
    TokenType_Error,
    TokenType_EndOfLine,

    TokenType_Number,

    TokenType_Plus,
    TokenType_Minus,
    TokenType_Percent,
    TokenType_Star,
    TokenType_Slash,
    TokenType_Caret,

    // TokenType_OpenParenthesis,
    // TokenType_CloseParenthesis,
} TokenType;

typedef enum {
    NodeType_Error,
    NodeType_Number,

    // Unaries
    NodeType_Positive,
    NodeType_Negative,

    // Binaries
    NodeType_Add,
    NodeType_Subtract,
    NodeType_Multiply,
    NodeType_Divide,
    NodeType_Power,
    NodeType_Modulo,
} NodeType;

typedef struct {
    TokenType type;
    char* lexeme;
} Token;

typedef struct {
    NodeType type;
    
    union {
        double value;
        struct { int* operation; } unary;
        struct { int* left; int* right; } binary;
    };
} Node;

#endif