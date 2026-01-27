#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct BINARYNODE {
    char data;
    struct BINARYNODE* left;
    struct BINARYNODE* right;
}BinaryNode;

typedef struct STACK {
    BinaryNode** array;
    int top;
    int capacity;
}Stack;

Stack* CreatStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (BinaryNode**)malloc(sizeof(BinaryNode*) * capacity);
    return stack;
}

int IsEmpty(Stack* stack) {
    if (stack->top == -1) return 1;
    else return 0;
}

int IsFull(Stack* stack) {
    if (stack->top == stack->capacity - 1) return 1;
    else return 0;
}

void push(Stack* stack, BinaryNode* root) {
    if (IsFull(stack)) return;
    stack->array[++(stack->top)] = root;
}

BinaryNode* pop(Stack* stack) {
    if (IsEmpty(stack)) return NULL;
    return stack->array[(stack->top)--];
}

BinaryNode* peek(Stack* stack) {
    if (IsEmpty(stack)) return NULL;
    return stack->array[stack->top];
}

void PreorderTraversal(BinaryNode* root) {
    if (!root) return;

    Stack* stack = CreatStack(100);
    push(stack, root);

    while (!IsEmpty(stack)) {
        BinaryNode* node = pop(stack);
        printf("%c", node->data);

        if (node->right != NULL) push(stack, node->right);
        if (node->left != NULL) push(stack, node->left);
    }

    free(stack->array);
    free(stack);
    printf("\n");
}

int main() {

    BinaryNode node1 = {'A', NULL, NULL};
    BinaryNode node2 = {'B', NULL, NULL};
    BinaryNode node3 = {'C', NULL, NULL};
    BinaryNode node4 = {'D', NULL, NULL};
    BinaryNode node5 = {'E', NULL, NULL};
    BinaryNode node6 = {'F', NULL, NULL};
    BinaryNode node7 = {'G', NULL, NULL};
    BinaryNode node8 = {'H', NULL, NULL};

    node1.left = &node2;
    node1.right = &node6;
    node2.right = &node3;
    node3.left = &node4;
    node3.right = &node5;
    node6.right = &node7;
    node7.left = &node8;

    PreorderTraversal(&node1);

    return 0;
}