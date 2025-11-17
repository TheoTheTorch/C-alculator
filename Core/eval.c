#include "eval.h"
#include <math.h>

#define unary_node evaluate( (Node*) node->unary.operation )
#define left_node evaluate( (Node*) node->binary.left )
#define right_node evaluate( (Node*) node->binary.right )

double evaluate(Node* node)
{
    switch (node->type)
    {
        case NodeType_Error: return NAN;
        case NodeType_Number: return node->value;
        // Unaries
        case NodeType_Positive: return + unary_node;
        case NodeType_Negative: return - unary_node;
        // Binaries
        case NodeType_Add: return left_node + right_node;
        case NodeType_Subtract: return left_node - right_node;
        case NodeType_Multiply: return left_node * right_node;
        case NodeType_Divide: return left_node / right_node;
        case NodeType_Modulo:return fmod(left_node, right_node);
        case NodeType_Power: return powf(left_node, right_node);

        default: break;
    }

    return NAN;
}
