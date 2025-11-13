#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

int main(int argc, char **argv) {
    int token_count;
    Token *tokens = lexer("129.45       + - * / % 34.995\n", &token_count);

    for (int i = 0; i < token_count; i++)
    {
        printf("%f %d Allooo???\n", tokens[i].data.numeric_value, tokens[i].data.operation);
    }

    free(tokens);
    return 0;
}