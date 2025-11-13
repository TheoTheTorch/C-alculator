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

Token lexer_create_token(Lexer* lexer, TokenType type)
{
    return (Token) {
        .type = type,
        .lexeme = NULL,
    };
}

Token lexer_advance(Lexer* lexer)
{
    lexer->current += 1;
}

void lexer_next_token(Lexer* lexer)
{
    if (*lexer->current == '\0')
    {
        return;
    }

    printf("char %c ", *lexer->current);

    lexer_advance(lexer);
    lexer_next_token(lexer);
    
    // return lexer_create_token(lexer, TokenType_Error);
}
// void clear_buffer(char **buffer, int* buffer_size)
// {
//     for (int i = 0; i < MAX_TOKEN_LENGTH; i++)
//     { 
//         *buffer[i] = '\0';
//     }
//     *buffer_size = 0;
// }



// Token *lexer(const char expression[], int *token_count)
// {
//     const int len = strlen(expression);
//     Token *tokens = (Token*) malloc(len * sizeof(Token));

//     char buffer[MAX_TOKEN_LENGTH] = "\0";
//     int buffer_size = 0;

//     *token_count = 0;

//     // for (int i = 0; i < len + 1; i++)
//     // {
//     //     char current_char = expression[i];
        
//     //     if ( isspace(current_char) )
//     //     {
//     //         continue;
//     //     }

//     //     buffer[buffer_size] = current_char;
//     //     buffer_size += 1;

//     //     // // Save each digit of a number
//     //     // if ( isdigit(current_char) || current_char == '.' )
//     //     // {
//     //     //     buffer[buffer_size] = current_char;
//     //     //     buffer_size += 1;
//     //     //     continue;
//     //     // }

//     //     // // Once we hit something that is not a digit,
//     //     // // save the number that was in the buffer
//     //     // // -----------------------------------
//     //     // if ( *buffer )
//     //     // {
//     //     //     Token number_token;
//     //     //     number_token.data.numeric_value = (double) atof( buffer );
//     //     //     tokens[*token_count] = number_token;

//     //     //     *token_count += 1;
            
//     //     //     // reset buffer
//     //     //     for (int i = 0; i < MAX_NUMBER_DIGITS; i++) { buffer[i] = '\0';}
//     //     //     buffer_size = 0;
//     //     // }
//     //     // // -----------------------------------

//     //     // if (current_char == '\0')
//     //     // {
//     //     //     continue;
//     //     // }
        
//     //     // // Assuming valid operation
//     //     // // Todo: Add type safety
//     //     // // ---------------------------
//     //     // Token operation_token;
        
//     //     // int type;
//     //     // switch (current_char)
//     //     // {
//     //     //     case '+':
//     //     //         type = ADD;
//     //     //         break;
//     //     //     case '-':
//     //     //         type = SUBTRACT;
//     //     //         break;
//     //     //     case '*':
//     //     //         type = MULTIPLY;
//     //     //         break;
//     //     //     case '/':
//     //     //         type = DIVIDE;
//     //     //         break;
//     //     //     case '%':  
//     //     //         type = MODULO;
//     //     //         break;
//     //     //     default:
//     //     //         type = ERROR;
//     //     //         break;
//     //     // }
//     //     // operation_token.data.operation = type;

//     //     // tokens[*token_count] = operation_token;
        
//     //     // *token_count += 1;
//     //     // // ---------------------------

//     //     // switch (current_char)
//     //     // {
//     //     // case '/0':
//     //     //     tokens[*token_count] = create_token(TokenType_EndOfLine, buffer);
//     //     //     clear_buffer(&buffer, &buffer_size);
//     //     //     break;
//     //     // case '+':
//     //     //     tokens[*token_count] = create_token(TokenType_EndOfLine, buffer);
//     //     //     clear_buffer(&buffer, &buffer_size);
//     //     //     break;
//     //     // case '-':
//     //     //     tokens[*token_count] = create_token(TokenType_EndOfLine, buffer);
//     //     //     clear_buffer(&buffer, &buffer_size);
//     //     //     break;
//     //     // case '*':
//     //     //     tokens[*token_count] = create_token(TokenType_EndOfLine, buffer);
//     //     //     clear_buffer(&buffer, &buffer_size);
//     //     //     break;
//     //     // case '/':
//     //     //     tokens[*token_count] = create_token(TokenType_EndOfLine, buffer);
//     //     //     clear_buffer(&buffer, &buffer_size);
//     //     //     break;
//     //     // case '%':  
//     //     //     tokens[*token_count] = create_token(TokenType_EndOfLine, buffer);
//     //     //     clear_buffer(&buffer, &buffer_size);
//     //     //     break;

//     //     // case '0': case '1': case '2': case '3': case '4':
//     //     // case '5': case '6': case '7': case '8': case '9':  case '.':
//     //     //     tokens[*token_count] = create_token(TokenType_EndOfLine, buffer);
//     //     //     clear_buffer(&buffer, &buffer_size);
//     //     //     break;

//     //     // default:
//     //     //     tokens[*token_count] = create_token(TokenType_Error, buffer);
//     //     //     clear_buffer(&buffer, &buffer_size);
//     //     //     break;
//     //     // }
        
//     // }

//     return tokens;
// }
