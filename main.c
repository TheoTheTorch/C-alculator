#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

int main(int argc, char **argv) {
    char example_input[] = "129.45       + - * / % 34.995\n";
    // int token_count;
    // Token *tokens = lexer(example_input, &token_count);

    // for (int i = 0; i < token_count; i++)
    // {
    //     printf("Value: %s\n", tokens[i].lexeme);
    // }

    // free(tokens);

    Lexer lexer;
    lexer_initialize(&lexer, &example_input[0]);

    lexer_next_token(&lexer);
    
    return 0;
}