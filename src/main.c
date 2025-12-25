#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pipeline.h"

static void fatal_invalid_arguments()
{
    fprintf(stderr,
            "Usage: c-alculator [--print-tokens|-t] [--print-ast|-a] \"expression\"\n"
            "  --print-tokens, -t   Print tokens as they are parsed\n"
            "  --print-ast,    -a   Print the AST structure\n");
    exit(1);
}

int main(int argc, char **argv)
{
    int print_tokens_flag = 0;
    int print_ast_flag = 0;
    char *expression = NULL;

    if (argc < 2 || argc > 4) fatal_invalid_arguments();

    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "--print-tokens") || !strcmp(argv[i], "-t")) {
            print_tokens_flag = 1;
        }
        else if (!strcmp(argv[i], "--print-ast") || !strcmp(argv[i], "-a")) {
            print_ast_flag = 1;
        }
        else if (!expression) {
            expression = argv[i];
        }
        else {
            fatal_invalid_arguments();
        }
    }

    if (!expression) fatal_invalid_arguments();

    printf("%lf\n", evaluate_expression(expression, print_tokens_flag, print_ast_flag));
    return 0;
}