#include "eval.h"
#include <math.h>

double evaluate(Node* node)
{
    switch (node->type)
    {
        case NodeType_Error: return NAN;
        case NodeType_Number: return node->value;
        // Unaries
        case NodeType_Positive: return evaluate( (Node*) node->unary.operation );
        case NodeType_Negative: return - evaluate( (Node*) node->unary.operation );
        // Binaries
        double left = evaluate( (Node*) node->binary.left );
        double right = evaluate( (Node*) node->binary.right );

        case NodeType_Add: return left + right;
        case NodeType_Subtract: return left - right;
        case NodeType_Multiply: return left * right;
        case NodeType_Divide: return left / right;
        case NodeType_Modulo: return modf(left, &right);
        case NodeType_Power: return powf(left, right);

        default: break;
    }

    return NAN;
}
