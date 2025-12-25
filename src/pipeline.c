#include "pipeline.h"

typedef struct {
    Lexer *lexer;
    int print_tokens_flag;
} LexerContext;

static const char *node_symbols[] = {
    [NodeType_Positive] = "(+)",
    [NodeType_Negative] = "(-)",
    [NodeType_Add] = "(+)",
    [NodeType_Subtract] = "(-)",
    [NodeType_Multiply] = "(*)",
    [NodeType_Divide] = "(/)",
    [NodeType_Modulo] = "(%)",
    [NodeType_Power] = "(^)"
};

static void print_token(Token token)
{
    int length = token.end - token.start;
    printf("token %.*s | type %d\n", length, token.start, token.type);
}

static Token lexer_next_token_with_print(void *context)
{
    LexerContext *ctx = context;
    Token token = lexer_next_token(ctx->lexer);
    
    if (ctx->print_tokens_flag) print_token(token);

    return token;
}

static Node *parse_expression(char *expression, int print_tokens_flag)
{
    Lexer lexer;
    lexer_initialize(&lexer, expression);

    LexerContext context = {
        .lexer = &lexer,
        .print_tokens_flag = print_tokens_flag,
    };

    Parser parser;
    parser_initialize(&parser, &context, &lexer_next_token_with_print);

    return parser_parse_expression(&parser, Precedence_Min);
}

static void print_nodes_recursively(Node *node, int depth)
{
    if (node == NULL) return;

    if (node->type == NodeType_Error)
    {
        printf("Err");
        return;
    }

    if (node->type == NodeType_Number) {
        printf("%f", node->value);
    } else {
        printf("%s", node_symbols[node->type]);
    }

    switch (node->type)
    {
        case NodeType_Number:
            break;
        case NodeType_Positive:
        case NodeType_Negative:
            printf(">>>>");
            print_nodes_recursively(node->unary.operand, depth + 1);
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

static void print_ast(Node *root)
{
    printf("\nAbstract syntax tree:\n");
    print_nodes_recursively(root, 0);
    printf("\n");
}

static void free_ast(Node *node)
{
    if (node == NULL) return;

    switch (node->type)
    {
        case NodeType_Error:
        case NodeType_Number:
            break;
        case NodeType_Positive:
        case NodeType_Negative:
            free_ast(node->unary.operand);
            break;
        default:
            free_ast(node->binary.left);
            free_ast(node->binary.right);
            break;
    }
    free(node);   
}

double evaluate_expression(char *expression, int print_tokens_flag, int print_ast_flag)
{
    if (print_tokens_flag) printf("Tokens:\n");

    Node *root_node = parse_expression(expression, print_tokens_flag);

    if (print_ast_flag) print_ast(root_node);
    
    double result = evaluate(root_node);
    
    free_ast(root_node);

    if (print_tokens_flag || print_ast_flag) printf("\nValue: ");

    return result;
}
