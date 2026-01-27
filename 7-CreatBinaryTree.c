#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BINARYNODE {
    char data;
    struct BINARYNODE* left;
    struct BINARYNODE* right;
}BinaryNode;

BinaryNode* CreatBinarytree() {
    BinaryNode* node;
    char ch;
    fflush(stdin);
    scanf("%c", &ch);

    if (ch == '#') node = NULL;
    else {
        node = (BinaryNode*)malloc(sizeof(BinaryNode));
        node->data = ch;
        node->left = CreatBinarytree();
        node->right = CreatBinarytree();
    }

    return node;
}

void Recursive(BinaryNode* root) {
    if (root == NULL) return;

    printf("%c ", root->data);

    Recursive(root->left);
    Recursive(root->right);
}

void FreeBinaryTree(BinaryNode* node) {
    if (!node) return;

    FreeBinaryTree(node->left);
    FreeBinaryTree(node->right);
    free(node);
}

int main() {
    BinaryNode* node = CreatBinarytree();
    Recursive(node);
    FreeBinaryTree(node);

    return 0;
}