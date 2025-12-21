#ifndef PIPELINE_H
#define PIPELINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Core/types.h"
#include "Core/lexer.h"
#include "Core/parser.h"
#include "Core/eval.h"

Token *tokenize(char *expression);

void free_tokens(Token *tokens);

void print_tokens(Token *tokens);


Node *parse(Token *tokens);

void free_nodes(Node *root);

void print_nodes(Node *root);


double evaluate_expression(char *expression);

#endif