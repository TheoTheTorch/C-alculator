#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pipeline.h"

Token* tokenize(char* expression)
{
    if (strlen(expression) == 0)
        return (Token*) { };
    
    Lexer lexer;
    lexer_initialize(&lexer, &expression[0]);

    // allocate the theoretical maximum amount of tokens + \0
    Token* tokens = (Token*) malloc(strlen(expression)*  sizeof(Token) + 1);
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

int count_tokens(Token* tokens)
{
    int i = 0;
    while (1)
    {
        if (tokens[i].type == TokenType_EndOfLine)
            break;
        i += 1;
    }

    return i;
}

void free_tokens(Token* tokens)
{   
    for (int i = 0; i < count_tokens(tokens); i++)
    {
        free(tokens[i].lexeme);
    }
    free(tokens);
}

void print_tokens(Token* tokens)
{
    for (int i = 0; i < count_tokens(tokens); i++)
    {
        printf("token %s | type %d\n", tokens[i].lexeme, tokens[i].type);
    }
}

Node *parse(Token *tokens)
{
    return nullptr;
}
