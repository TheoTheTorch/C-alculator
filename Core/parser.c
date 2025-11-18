#include "parser.h"
#include <string.h>
#include <stdlib.h>

static Precedence precedence_lookup[TokenType_Max] = {
    [TokenType_Plus] = Precedence_Term,
    [TokenType_Minus] = Precedence_Term,
    [TokenType_Star] = Precedence_Factor,
    [TokenType_Slash] = Precedence_Factor,
    [TokenType_Percent] = Precedence_Factor,
    [TokenType_Caret] = Precedence_Power,
};

void parser_initialize(Parser* parser, Token* start)
{
    parser->start = start;
    parser->current = start;
}

void parser_advance(Parser *parser)
{
    parser->current += 1;
}

Node *parser_parse_terminal_expression(Parser *parser)
{
    Node* to_return = nullptr;
    switch (parser->current->type)
    {
        case TokenType_Number: 
            to_return = (Node*) malloc(sizeof(Node));
            to_return->type = NodeType_Number;
            to_return->value = atof(parser->current->lexeme);
            parser_advance(parser);
            break;
        case TokenType_OpenParenthesis:
            parser_advance(parser);
            to_return = parser_parse_expression(parser, Precedence_Min);
            if (parser->current->type == TokenType_CloseParenthesis)
            {
                parser_advance(parser);
            }
            break;
        case TokenType_Plus:
            parser_advance(parser);
            to_return = (Node*) malloc(sizeof(Node));
            to_return->type = NodeType_Positive;
            to_return->unary.operand = (int*) parser_parse_terminal_expression(parser);
            break;
        case TokenType_Minus:
            parser_advance(parser);
            to_return = (Node*) malloc(sizeof(Node));
            to_return->type = NodeType_Negative;
            to_return->unary.operand = (int*) parser_parse_terminal_expression(parser);
            break;
        default: break;
    }
    return to_return;
}

Node* parser_parse_infix_expression(Parser* parser, Token operator, Node* left)
{
    Node* to_return = (Node*) malloc(sizeof(Node));
    switch (operator.type)
    {
        case TokenType_Plus: to_return->type = NodeType_Add; break;
        case TokenType_Minus: to_return->type = NodeType_Subtract; break;
        case TokenType_Star: to_return->type = NodeType_Multiply; break;
        case TokenType_Slash: to_return->type = NodeType_Divide; break;
        case TokenType_Percent: to_return->type = NodeType_Modulo; break;
        case TokenType_Caret: to_return->type = NodeType_Power; break;
        default: break;
    }
    to_return->binary.left = (int*) left;
    to_return->binary.right = (int*) parser_parse_expression(parser, precedence_lookup[operator.type]);
    
    return to_return;
}

Node* parser_parse_expression(Parser* parser, Precedence previous_precedence)
{
    Node *left = parser_parse_terminal_expression(parser);
    Token current_operator = *(parser->current);
    Precedence current_precedence = precedence_lookup[current_operator.type];

    // All tokens with no precedence assigned to them will become Precedence_Min
    // This includes the token with type TokenType_EndOfLine, therefore we exit there automatically
    int is_current_operator_valid = current_precedence != Precedence_Min;
    while (is_current_operator_valid)
    {
        if (previous_precedence >= current_precedence)
        {
            break;
        } else {
            parser_advance(parser);
            left = parser_parse_infix_expression(parser, current_operator, left);
            current_operator = *(parser->current);
            current_precedence = precedence_lookup[current_operator.type];
        }
    }

    return left;
}
