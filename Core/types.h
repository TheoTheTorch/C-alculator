#ifndef TYPES_H
#define TYPES_H

typedef enum {
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
    TokenType_Max,
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

typedef enum {
    Precedence_Min,

    Precedence_Term,
    Precedence_Factor,
    Precedence_Power,

    Precedence_Max,
} Precedence;

typedef struct {
    TokenType type;
    char *lexeme;
} Token;

typedef struct n {
    NodeType type;
    
    union {
        double value;
        struct { struct n *operand; } unary;
        struct { struct n *left; struct n *right; } binary;
    };
} Node;

#endif