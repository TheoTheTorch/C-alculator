#include "parser.h"

static const Precedence precedence[] = {
    [TokenType_Plus] = Precedence_Term,
    [TokenType_Minus] = Precedence_Term,
    [TokenType_Star] = Precedence_Factor,
    [TokenType_Slash] = Precedence_Factor,
    [TokenType_Percent] = Precedence_Factor,
    [TokenType_Caret] = Precedence_Power,
};

static const NodeType binary_operation_type[] = {
    [TokenType_Plus] = NodeType_Add,
    [TokenType_Minus] = NodeType_Subtract,
    [TokenType_Star] = NodeType_Multiply,
    [TokenType_Slash] = NodeType_Divide,
    [TokenType_Percent] = NodeType_Modulo,
    [TokenType_Caret] = NodeType_Power,
};

static const NodeType terminal_expression_type[] = {
    [TokenType_Number] = NodeType_Number,
    [TokenType_Plus] = NodeType_Positive,
    [TokenType_Minus] = NodeType_Negative,
};

void parser_initialize(Parser *parser, Token *start)
{
    parser->current_token = start;
}

static void parser_advance(Parser *parser)
{
    parser->current_token += 1;
}

static Node *parser_parse_terminal_expression(Parser *parser)
{
    Node *to_return = malloc(sizeof(Node));
    
    to_return->type = terminal_expression_type[parser->current_token->type];
    
    switch (parser->current_token->type)
    {
        case TokenType_Number:
            Token *token = parser->current_token;
            to_return->value = strtod(token->start, &token->end);
            parser_advance(parser);
            return to_return;
        case TokenType_OpenParenthesis:
            parser_advance(parser);
            to_return = parser_parse_expression(parser, Precedence_Min);
            if (parser->current_token->type == TokenType_CloseParenthesis) parser_advance(parser);
            return to_return;
        case TokenType_Plus:
            parser_advance(parser);
            to_return->unary.operand = parser_parse_terminal_expression(parser);
            return to_return;
        case TokenType_Minus:
            parser_advance(parser);
            to_return->unary.operand = parser_parse_terminal_expression(parser);
            return to_return;
        default:
            parser_advance(parser);
            return to_return;
    }
}

static Node *parser_parse_infix_expression(Parser *parser, Node *left)
{
    Node *to_return = malloc(sizeof(Node));
    
    to_return->type = binary_operation_type[parser->current_token->type];
    to_return->binary.left = left;
    parser_advance(parser);
    to_return->binary.right = parser_parse_expression(parser, precedence[(parser->current_token - 1)->type]);

    return to_return;
}

Node *parser_parse_expression(Parser *parser, Precedence previous_precedence)
{
    Node *left = parser_parse_terminal_expression(parser);
    
    while (precedence[parser->current_token->type] > previous_precedence)
    {
        left = parser_parse_infix_expression(parser, left);
    }

    return left;
}
