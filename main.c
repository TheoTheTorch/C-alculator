#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lexer.h"

int main(int argc, char **argv)
{    
    assert(argc == 2 && "Must provide (exactly one) mathematical expression as argument.");
    char* expression = (char*) argv[1];

    int count1;
    int count2;
    Token* tokens1 = tokenize(expression, &count1);
    Token* tokens2 = tokenize("3.5 + 999 - 1 / 1 * 2 % 2", &count2);
    
    free_tokens(tokens1, count1);
    free_tokens(tokens2, count2);

    return 0;
}