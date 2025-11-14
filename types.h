#include <string.h>

#ifndef TYPES_H
#define TYPES_H

#define Token_Max_Length 128

typedef enum {
    TokenType_Error,
    TokenType_EndOfLine,

    TokenType_Number,

    TokenType_Plus,
    TokenType_Minus,
    TokenType_Star,
    TokenType_Slash,
    TokenType_Percent,
    TokenType_Caret,

    TokenType_OpenParenthesis,
    TokenType_CloseParenthesis,
} TokenType;

typedef enum {
    NodeType_Error,
    NodeType_Number,
    // NodeType_Positive,
    // NodeType_Negative,
    NodeType_Add,
    NodeType_Subtract,
    NodeType_Multiply,
    NodeType_Divide,
    NodeType_Power,
    NodeType_Modulo,
} NodeType;

typedef struct {
    TokenType type;
    char *lexeme;
} Token;

typedef struct {
    NodeType type;
    int *left;
    int *right;
    
    union {
        // payload here
    };
} Node;

#endif