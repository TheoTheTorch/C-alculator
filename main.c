#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lexer.h"

int main(int argc, char **argv) {
    
    assert(argc == 2 && "Must provide (exactly one) mathematical expression as argument.");
    char expression[] = (char*) argv[1];

    tokenize(expression);
    tokenize("3.5 + 999 - 1 / 1 * 2 % 2");
    
    return 0;
}