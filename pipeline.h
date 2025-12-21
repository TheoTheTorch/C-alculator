#ifndef PIPELINE_H
#define PIPELINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Core/types.h"
#include "Core/lexer.h"
#include "Core/parser.h"
#include "Core/eval.h"

typedef struct {
    Lexer *lexer;
    int print_tokens_flag;
} LexerContext;

void print_ast(Node *root);

void free_ast(Node* root);

double evaluate_expression(char *expression, int print_tokens_flag, int print_ast_flag);

#endif