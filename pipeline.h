#ifndef PIPELINE_H
#define PIPELINE_H
#include "Core/types.h"
#include "Core/lexer.h"
#include "Core/parser.h"
#include "Core/eval.h"

// Lexer
// ------------
Token* tokenize(char* expression);

int count_tokens(Token* tokens);

void free_tokens(Token* token);

void print_tokens(Token* tokens);
// ------------

// Parser
// ------------
Node* parse(Token* tokens);

void free_nodes(Node* first_node);
// ------------

// Eval
// ------------
double evaluate_expression(char* expression);
// ------------
#endif