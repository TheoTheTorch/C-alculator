#ifndef PIPELINE_H
#define PIPELINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Core/types.h"
#include "Core/lexer.h"
#include "Core/parser.h"
#include "Core/eval.h"

void print_ast(Node *root);

double evaluate_expression(char *expression);

#endif