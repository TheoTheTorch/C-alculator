#include <stdio.h>
#include <assert.h>
#include "pipeline.h"

int main(int argc, char **argv)
{    
    assert(argc == 2 && "Must provide (exactly one) mathematical expression as argument.");
    char *expression = (char*) argv[1];

    printf("%lf\n", evaluate_expression(expression, 1, 1));

    return 0;
}