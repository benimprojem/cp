#include "codegen.h"
#include <stdio.h>

int instructionCount = 0;

void generateCode(Node *node) {
    if (!node) return;

    switch (node->type) {
        case NODE_NUMBER:
            printf("%d: PUSH %d\n", instructionCount++, node->number.value);
            break;
        case NODE_IDENTIFIER:
            printf("%d: LOAD %s\n", instructionCount++, node->identifier.name);
            break;
        case NODE_BINARY_OP:
            generateCode(node->binary.left);
            generateCode(node->binary.right);
            if (strcmp(node->binary.op, "+") == 0) {
                printf("%d: ADD\n", instructionCount++);
            } else if (strcmp(node->binary.op, "-") == 0) {
                printf("%d: SUB\n", instructionCount++);
            } else if (strcmp(node->binary.op, "*") == 0) {
                printf("%d: MUL\n", instructionCount++);
            } else if (strcmp(node->binary.op, "/") == 0) {
                printf("%d: DIV\n", instructionCount++);
            }
            break;
        case NODE_ASSIGN:
            generateCode(node->binary.right);
            printf("%d: STORE %s\n", instructionCount++, node->binary.left->identifier.name);
            break;
        // diğer durumlar
        default:
            break;
    }
}

void printInstructions() {
    printf("Generated Instructions:\n");
}
