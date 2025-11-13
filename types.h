#ifndef TYPES_H
#define TYPES_H

typedef enum {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MODULO,
    UNKOWN,
} Operation;

typedef enum {
    NUMBER,
    OPERATION,
    UNARY,
} NodeTypes;

typedef union {
    double numeric_value;
    Operation operation;
} Data;

typedef struct {
    NodeTypes type;
    Data data;
} Token;


#endif