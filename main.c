#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lexer.h"

int main(int argc, char **argv)
{    
    assert(argc == 2 && "Must provide (exactly one) mathematical expression as argument.");
    char* expression = (char*) argv[1];

    Token* tokens1 = tokenize(expression);
    Token* tokens2 = tokenize("3.5 + 999 - 1 / 1 * 2 % 2");
    
    free(tokens1);
    free(tokens2);

    return 0;
}