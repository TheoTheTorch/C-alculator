#include "parser.h"

static Precedence precedence[] = {
    [TokenType_Plus] = Precedence_Term,
    [TokenType_Minus] = Precedence_Term,
    [TokenType_Star] = Precedence_Factor,
    [TokenType_Slash] = Precedence_Factor,
    [TokenType_Percent] = Precedence_Factor,
    [TokenType_Caret] = Precedence_Power,
};

static NodeType binary_operation_type[] = {
    [TokenType_Plus] = NodeType_Add,
    [TokenType_Minus] = NodeType_Subtract,
    [TokenType_Star] = NodeType_Multiply,
    [TokenType_Slash] = NodeType_Divide,
    [TokenType_Percent] = NodeType_Modulo,
    [TokenType_Caret] = NodeType_Power,
};

void parser_initialize(Parser *parser, void *context, Token (*advance) (void *context))
{
    parser->context = context;
    parser->advance = advance;
    parser->current_token = parser->advance(parser->context);
}

static void parser_advance(Parser *parser)
{
    parser->current_token = parser->advance(parser->context);
}

static Node *create_node(NodeType type)
{
    Node *node = malloc(sizeof(Node));
    node->type = type;
    return node;
}

static Node *parser_parse_terminal_expression(Parser *parser)
{
    Token token = parser->current_token;
    parser_advance(parser);

    switch (token.type)
    {
        case TokenType_Number:
        {
            Node *node = create_node(NodeType_Number);
            node->value = strtod(token.start, &token.end);
            return node;
        }
        case TokenType_OpenParenthesis:
        {
            Node *node = parser_parse_expression(parser, Precedence_Min);
            if (parser->current_token.type == TokenType_CloseParenthesis)
            {
                parser_advance(parser);
            }
            return node;
        }
        case TokenType_Plus:
        case TokenType_Minus:
        {
            Node *node = create_node((token.type == TokenType_Plus) ? NodeType_Positive : NodeType_Negative);
            node->unary.operand = parser_parse_terminal_expression(parser);
            return node;
        }
        default:
            return create_node(NodeType_Error);
    }
}

static Node *parser_parse_infix_expression(Parser *parser, Node *left)
{
    Token token = parser->current_token;
    Node *node = create_node(binary_operation_type[token.type]);
    
    parser_advance(parser);

    if (node->type == NodeType_Error) return node;
    
    node->binary.left = left;
    node->binary.right = parser_parse_expression(parser, precedence[token.type]);

    return node;
}

Node *parser_parse_expression(Parser *parser, Precedence previous_precedence)
{
    Node *left = parser_parse_terminal_expression(parser);

    while (precedence[parser->current_token.type] > previous_precedence)
    {
        left = parser_parse_infix_expression(parser, left);
    }

    return left;
}

