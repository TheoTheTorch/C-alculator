#include "lexer.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void lexer_initialize(Lexer* lexer, char *expression_start)
{
    lexer->start = expression_start;
    lexer->current = expression_start;
}

void lexer_advance(Lexer* lexer)
{
    lexer->current += 1;
}

void lexer_skip_whitespace(Lexer* lexer)
{
    while (isspace(*lexer->current))
    {
        lexer_advance(lexer);
    }
}

Token lexer_create_token(Lexer* lexer, TokenType type)
{
    int length = (lexer->current) - (lexer->start);
    char* lexeme = (char*) malloc(length * sizeof(char));

    for (int i = 0; i < length; i++)
    {
        lexeme[i] = *(lexer->start + i);
    }
    lexeme[length] = '\0';

    return (Token) {
        .type = type,
        .lexeme = lexeme,
    };
}

Token lexer_number(Lexer* lexer)
{
    while (isdigit(*lexer->current) || *lexer->current == '.')
    {
        lexer_advance(lexer);
    }
    return lexer_create_token(lexer, TokenType_Number);
}


Token lexer_next_token(Lexer* lexer)
{
    lexer_skip_whitespace(lexer);
    
    lexer_advance(lexer);
    lexer->start = lexer->current - 1;
    char current_character = *(lexer->current - 1);

    if (current_character == '\0')
    {
        return lexer_create_token(lexer, TokenType_EndOfLine);
    }

    switch (current_character)
    {
        case '\0': return lexer_create_token(lexer, TokenType_EndOfLine);
        case '+': return lexer_create_token(lexer, TokenType_Plus);
        case '-': return lexer_create_token(lexer, TokenType_Minus);
        case '*': return lexer_create_token(lexer, TokenType_Star);
        case '/': return lexer_create_token(lexer, TokenType_Slash);
        case '%': return lexer_create_token(lexer, TokenType_Percent);
        case '^': return lexer_create_token(lexer, TokenType_Caret);

        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':  case '.':
            return lexer_number(lexer);
        
        default:
            return lexer_create_token(lexer, TokenType_Error);
    };
}

Token *tokenize(char *expression)
{
    if (strlen(expression) == 0)
        return (Token*) { };
    
    Lexer lexer;
    lexer_initialize(&lexer, &expression[0]);

    // int reserved_space = 1;
    int i = 0;
    // allocate the theoretical maximum amount of tokens + \0
    Token *tokens = (Token*) malloc(strlen(expression) * sizeof(Token) + 1);

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