#include "lexer.h"

void lexer_initialize(Lexer *lexer, char *expression)
{
    lexer->start = expression;
    lexer->current = expression;
}

static void lexer_advance(Lexer *lexer)
{
    lexer->current += 1;
}

static Token lexer_create_token(Lexer *lexer, TokenType type)
{
    return (Token) {
        .type = type,
        .start = lexer->start,
        .end = lexer->current,
    };
}

static void lexer_skip_whitespace(Lexer *lexer)
{
    while (isspace(*lexer->current))
    {
        lexer_advance(lexer);
    }
}

static Token lexer_create_number(Lexer *lexer)
{
    while (isdigit(*lexer->current) || *lexer->current == '.')
    {
        lexer_advance(lexer);
    }
    return lexer_create_token(lexer, TokenType_Number);
}

Token lexer_next_token(Lexer *lexer)
{
    lexer_skip_whitespace(lexer);
    
    lexer->start = lexer->current;
    char current_character = *(lexer->current);
    lexer_advance(lexer);

    switch (current_character)
    {
        case '\0': return lexer_create_token(lexer, TokenType_EOF);
        case '+': return lexer_create_token(lexer, TokenType_Plus);
        case '-': return lexer_create_token(lexer, TokenType_Minus);
        case '*': return lexer_create_token(lexer, TokenType_Star);
        case '/': return lexer_create_token(lexer, TokenType_Slash);
        case '%': return lexer_create_token(lexer, TokenType_Percent);
        case '^': return lexer_create_token(lexer, TokenType_Caret);
        case '(': return lexer_create_token(lexer, TokenType_OpenParenthesis);
        case ')': return lexer_create_token(lexer, TokenType_CloseParenthesis);
        
        default:
            if (isdigit(current_character) || current_character == '.')
            {
                return lexer_create_number(lexer);
            }
            break;
    }
    return lexer_create_token(lexer, TokenType_Error);
}
