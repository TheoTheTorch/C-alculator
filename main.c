#include <stdio.h>
#include <string.h>
#include "pipeline.h"

int main(int argc, char **argv)
{
    int print_tokens_flag = 0;
    int print_ast_flag = 0;
    char *expression = NULL;

    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "--print-tokens") || !strcmp(argv[i], "-t"))
            { print_tokens_flag = 1; }
        else if (!strcmp(argv[i], "--print-ast") || !strcmp(argv[i], "-a"))
            { print_ast_flag = 1; }
        else { expression = argv[i]; }
    }

    if (!expression)
    {
        fprintf(stderr,
            "Usage: %s [--print-tokens|-t] [--print-ast|-a] \"expression\"\n"
            "  --print-tokens, -t   Print tokens as they are parsed\n"
            "  --print-ast,    -a   Print the AST structure\n",
            argv[0]);
        return 1;
    }

    printf("%lf\n", evaluate_expression(expression, print_tokens_flag, print_ast_flag));
    return 0;
}