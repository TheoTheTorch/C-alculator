#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lexer.h"

int main(int argc, char **argv) {
    
    assert(argc == 2 && "Must provide (exactly one) mathematical expression as argument.");
    char* expression = (char*) argv[1];

    Lexer lexer;
    lexer_initialize(&lexer, &expression[0]);

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