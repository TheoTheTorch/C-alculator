#ifndef PIPELINE_H
#define PIPELINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Core/types.h"
#include "Core/lexer.h"
#include "Core/parser.h"
#include "Core/eval.h"

Node *parse_expression(char *expression);

void free_nodes(Node *root);

void print_nodes(Node *root);

double evaluate_expression(char *expression);

#endif