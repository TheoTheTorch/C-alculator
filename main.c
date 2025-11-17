#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pipeline.h"

int main(int argc, char* *argv)
{    
    assert(argc == 2 && "Must provide (exactly one) mathematical expression as argument.");
    char* expression = (char*) argv[1];

    // Token* tokens1 = tokenize(expression);
    // Token* tokens2 = tokenize("3.5 + 999 - 1 / 1*  2 % 2");
    // Token* tokens3 = tokenize(" ");

    // Node* first_node = parse(tokens1);



    // print_tokens(tokens1);
    // print_tokens(tokens2);
    // print_tokens(tokens3);

    // free_tokens(tokens1);
    // free_tokens(tokens2);
    // free_tokens(tokens3);

    printf("%lf", evaluate_expression(expression));

    return 0;
}