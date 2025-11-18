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

Node* parse(Token* tokens)
{
    if (tokens[0].type == TokenType_EndOfLine || tokens[0].type == TokenType_Error)
    {
        Node* to_return = (Node*) malloc(sizeof(Node));
        Node temp = { .type = NodeType_Error };
        to_return = &temp;
        return to_return;
    }

    Parser parser;
    parser_initialize(&parser, tokens);

    Node* to_return = parser_parse_expression(&parser, Precedence_Min); 
    
    return to_return;
}

void free_nodes(Node *first_node)
{
    // Todo
}

void print_nodes(Node *first)
{
    // Todo
}

double evaluate_expression(char *expression)
{
    Token* tokens = tokenize(expression);

    print_tokens(tokens);

    Node* first_node = parse(tokens);

    print_nodes(first_node);
    
    double result = evaluate(first_node);
    
    free_tokens(tokens);
    free_nodes(first_node);

    return result;
}
