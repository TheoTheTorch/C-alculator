#include "pipeline.h"

Token *tokenize(char *expression)
{
    if (strlen(expression) == 0) return NULL;
    
    Lexer lexer;
    lexer_initialize(&lexer, &expression[0]);

    // allocate the theoretical maximum amount of tokens + \0
    Token *tokens = (Token*) malloc((strlen(expression) + 1) * sizeof(Token));

    for (int i = 0; 1; i++)
    {
        tokens[i] = lexer_next_token(&lexer);

        if (tokens[i].type == TokenType_EOF)
        {
            tokens = (Token*) realloc(tokens, (i + 1) * sizeof(Token));
            break;
        }
    }

    return tokens;
}

void free_tokens(Token *tokens)
{
    for (int i = 0; 1; i++)
    {
        free(tokens[i].lexeme);

        if (tokens[i].type == TokenType_EOF) break;
    }
    free(tokens);
}

void print_tokens(Token *tokens)
{
    for (int i = 0; 1; i++)
    {
        printf("token %s | type %d\n", tokens[i].lexeme, tokens[i].type);

        if (tokens[i].type == TokenType_EOF) break;
    }
}

Node *parse(Token *tokens)
{
    if (tokens[0].type == TokenType_EOF || tokens[0].type == TokenType_Error)
    {
        Node *to_return = (Node*) malloc(sizeof(Node));
        Node temp = { .type = NodeType_Error };
        to_return = &temp;
        return to_return;
    }

    Parser parser;
    parser_initialize(&parser, tokens);

    Node *to_return = parser_parse_expression(&parser, Precedence_Min); 
    
    return to_return;
}

void free_nodes(Node *node_pointer)
{
    if (node_pointer == NULL) return;

    if ( node_pointer->type == NodeType_Positive || node_pointer->type == NodeType_Negative )
    {
        free_nodes(node_pointer->unary.operand);
    } else if ( node_pointer->type != NodeType_Number )
    {
        free_nodes(node_pointer->binary.left);
        free_nodes(node_pointer->binary.right);
    }

    free(node_pointer);
}

void print_nodes(Node *node_pointer, int depth)
{
    if (node_pointer == NULL) return;

    switch (node_pointer->type)
    {
        case NodeType_Error: printf("NaN"); break;
        case NodeType_Number: printf("%f", node_pointer->value); break;
        // Unaries
        case NodeType_Positive: printf("(+)"); break;
        case NodeType_Negative: printf("(-)"); break;
        // Binaries
        case NodeType_Add: printf("(+)"); break;
        case NodeType_Subtract: printf("(-)"); break;
        case NodeType_Multiply: printf("(*)"); break;
        case NodeType_Divide: printf("(/)"); break;
        case NodeType_Modulo: printf("(%%)"); break;
        case NodeType_Power: printf("(+)"); break;
    }

    if ( node_pointer->type == NodeType_Positive || node_pointer->type == NodeType_Negative )
    {
        printf("--");
        print_nodes(node_pointer->unary.operand, depth + 1);
    } else if ( node_pointer->type != NodeType_Number )
    {
        printf("----");
        print_nodes(node_pointer->binary.left, depth + 1);
        printf("\n");
        for (int i = 0; i < depth; i++) printf("       ");
        printf("   ~~~~");
        print_nodes(node_pointer->binary.right, depth + 1);
    }
}

double evaluate_expression(char *expression)
{
    Token *tokens = tokenize(expression);

    print_tokens(tokens);

    Node *root_node = parse(tokens);

    print_nodes(root_node, 0);
    printf("\n");
    
    double result = evaluate(root_node);
    
    free_tokens(tokens);
    free_nodes(root_node);

    return result;
}
