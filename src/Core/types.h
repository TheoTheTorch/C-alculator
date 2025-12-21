#ifndef TYPES_H
#define TYPES_H

typedef enum TokenType {
    TokenType_Error,
    TokenType_EOF,

    TokenType_Number,

    TokenType_Plus,
    TokenType_Minus,
    TokenType_Percent,
    TokenType_Star,
    TokenType_Slash,
    TokenType_Caret,

    TokenType_OpenParenthesis,
    TokenType_CloseParenthesis,
} TokenType;

typedef enum NodeType {
    NodeType_Error,
    
    NodeType_Number,

    NodeType_Positive,
    NodeType_Negative,

    NodeType_Add,
    NodeType_Subtract,
    NodeType_Multiply,
    NodeType_Divide,
    NodeType_Power,
    NodeType_Modulo,
} NodeType;

typedef enum Precedence {
    Precedence_Min,

    Precedence_Term,
    Precedence_Factor,
    Precedence_Power,

    Precedence_Max,
} Precedence;

typedef struct Token {
    TokenType type;
    char *start;
    char *end;
} Token;

typedef struct Node {
    NodeType type;
    
    union {
        double value;
        struct { struct Node *operand; } unary;
        struct { struct Node *left; struct Node *right; } binary;
    };
} Node;

#endif