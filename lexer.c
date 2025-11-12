#include "lexer.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_NUMBER_DIGITS 32

Token *lexer(const char expression[], int *token_count)
{
    const int len = strlen(expression);
    Token *tokens_pointer = (Token*) malloc(len * sizeof(Token));

    char buffer[MAX_NUMBER_DIGITS] = "\0";
    int buffer_size = 0;

    *token_count = 0;

    for (int i = 0; i < len + 1; i++)
    {
        char current_char = expression[i];
        
        if ( isspace(current_char) )
        {
            continue;
        }

        // Save each digit of a number
        if ( isdigit(current_char) || current_char == '.' )
        {
            buffer[buffer_size] = current_char;
            buffer_size += 1;
            continue;
        }

        // Once we hit something that is not a digit,
        // save the number that was in the buffer
        // -----------------------------------
        Token number_token;
        number_token.data.numeric_value = (double) atof( buffer );
        tokens_pointer[*token_count] = number_token;

        *token_count += 1;
        
        // reset buffer
        for (int i = 0; i < MAX_NUMBER_DIGITS; i++) { buffer[i] = '\0';}
        buffer_size = 0;
        // -----------------------------------

        if (current_char == '\0')
        {
            continue;
        }

        // Assuming valid operation
        // Todo: Add type safety
        // ---------------------------
        Token operation_token;
        operation_token.data.operation = current_char;
        tokens_pointer[*token_count] = operation_token;
        
        *token_count += 1;
        // ---------------------------
    }

    return tokens_pointer;
}
