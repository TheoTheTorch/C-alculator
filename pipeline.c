#include "pipeline.h"

Node *parse_expression(char *expression)
{
    Lexer lexer;
    lexer_initialize(&lexer, expression);
    Parser parser;
    parser_initialize(&parser, &lexer, (Token (*)(void *))lexer_next_token);

    return parser_parse_expression(&parser, Precedence_Min);
}

void free_ast(Node *node)
{
    if (node == NULL) return;

    switch (node->type)
    {
        case NodeType_Positive:
        case NodeType_Negative:
            free_ast(node->unary.operand);
            break;
        case NodeType_Number:
            break;
        default:
            free_ast(node->binary.left);
            free_ast(node->binary.right);
            break;
    }

    free(node);   
}

static const char *node_symbols[] = {
    [NodeType_Error] = "NaN",
    [NodeType_Number] = NULL,
    [NodeType_Positive] = "(+)",
    [NodeType_Negative] = "(-)",
    [NodeType_Add] = "(+)",
    [NodeType_Subtract] = "(-)",
    [NodeType_Multiply] = "(*)",
    [NodeType_Divide] = "(/)",
    [NodeType_Modulo] = "(%)",
    [NodeType_Power] = "(^)"
};

static void print_nodes_recursively(Node *node, int depth)
{
    if (node == NULL) return;

    if (node->type == NodeType_Number)
    {
        printf("%f", node->value);
    } else {
        printf("%s", node_symbols[node->type]);
    }

    switch (node->type)
    {
        case NodeType_Positive:
        case NodeType_Negative:
            printf(">>>>");
            print_nodes_recursively(node->unary.operand, depth + 1);
            break;
        case NodeType_Number:
            break;
        default:
            printf("----");
            print_nodes_recursively(node->binary.right, depth + 1);
            printf("\n");
            for (int i = 0; i < depth; i++) printf("       ");
            printf("   ~~~~");
            print_nodes_recursively(node->binary.left, depth + 1);
            break;
    }
}

void print_ast(Node *root)
{
    print_nodes_recursively(root, 0);
    printf("\n");
}

double evaluate_expression(char *expression)
{
    Node *root_node = parse_expression(expression);

    print_ast(root_node);
    
    double result = evaluate(root_node);
    
    free_ast(root_node);

    return result;
}
