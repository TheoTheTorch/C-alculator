#include "eval.h"

#define unary_node evaluate( node->unary.operand )
#define left_node evaluate( node->binary.left )
#define right_node evaluate( node->binary.right )

double evaluate(Node *node)
{
    switch (node->type)
    {
        case NodeType_Error: return NAN;
        case NodeType_Number: return node->value;

        case NodeType_Positive: return + unary_node;
        case NodeType_Negative: return - unary_node;

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

#undef unary_node
#undef left_node
#undef right_node
