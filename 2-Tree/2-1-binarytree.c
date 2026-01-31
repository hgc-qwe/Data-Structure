#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BINARYNODE {
    char data;
    struct BINARYNODE* lchild;
    struct BINARYNODE* rchild;
}BinaryNode;

void Recursive1(BinaryNode* root) {
    if (root == NULL) return;

    printf("%c ", root->data);

    Recursive1(root->lchild);
    Recursive1(root->rchild);
}

void Recursive2(BinaryNode* root) {
    if (root == NULL) return;

    Recursive2(root->lchild);
    printf("%c ", root->data);
    Recursive2(root->rchild);
}

void Recursive3(BinaryNode* root) {
    if (root == NULL) return;

    Recursive3(root->lchild);
    Recursive3(root->rchild);
    printf("%c ", root->data);
}

void CreateBinaryTree() {
    BinaryNode node1 = {'A', NULL, NULL};
    BinaryNode node2 = {'B', NULL, NULL};
    BinaryNode node3 = {'C', NULL, NULL};
    BinaryNode node4 = {'D', NULL, NULL};
    BinaryNode node5 = {'E', NULL, NULL};
    BinaryNode node6 = {'F', NULL, NULL};
    BinaryNode node7 = {'G', NULL, NULL};
    BinaryNode node8 = {'H', NULL, NULL};

    node1.lchild = &node2;
    node1.rchild = &node6;
    node2.rchild = &node3;
    node3.lchild = &node4;
    node3.rchild = &node5;
    node6.rchild = &node7;
    node7.lchild = &node8;

    Recursive1(&node1);
    Recursive2(&node1);
    Recursive3(&node1);
}

int main() {
    CreateBinaryTree();

    return 0;
}