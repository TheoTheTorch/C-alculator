#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenize.h"
#include "lexer.h"

Token *tokenize(char *expression)
{
    if (strlen(expression) == 0)
        return (Token*) { };
    
    Lexer lexer;
    lexer_initialize(&lexer, &expression[0]);

    // allocate the theoretical maximum amount of tokens + \0
    Token *tokens = (Token*) malloc(strlen(expression) * sizeof(Token) + 1);
    int i = 0;

    while (1)
    {
        tokens[i] = lexer_next_token(&lexer);

        if (tokens[i].type == TokenType_EndOfLine)
            break;
        i += 1;
    }

    return tokens;
}

void free_tokens(Token* tokens)
{   
    int i = 0;
    while (1)
    {
        free(tokens[i].lexeme);

        if (tokens[i].type == TokenType_EndOfLine)
            break;
        i += 1;
    }
    free(tokens);
}

void print_tokens(Token* tokens)
{
    int i = 0;
    while (1)
    {
        printf("token %s | type %d\n", tokens[i].lexeme, tokens[i].type);

        if (tokens[i].type == TokenType_EndOfLine)
            break;
        i += 1;
    }
}