#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

int main(int argc, char **argv) {
    char example_input[] = "129.45       + - * / % 34.995\n\0";
    // int token_count;
    // Token *tokens = lexer(example_input, &token_count);

    // for (int i = 0; i < token_count; i++)
    // {
    //     printf("Value: %s\n", tokens[i].lexeme);
    // }

    // free(tokens);

    Lexer lexer;
    lexer_initialize(&lexer, &example_input[0]);

    Token tokens[128];
    int i = 0;

    while (1)
    {
        tokens[i] = lexer_next_token(&lexer);
        printf("token: %s of type %d\n", tokens[i].lexeme, tokens[i].type);
        
        if (tokens[i].type == TokenType_EndOfLine) break;
        i += 1;
    }
    
    return 0;
}