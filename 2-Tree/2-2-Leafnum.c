#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BINARYNODE {
    char ch;
    struct BINARYNODE* lchild;
    struct BINARYNODE* rchild;
}BinaryNode;

void LeafNum(BinaryNode* root, int* num) {
    if (!root) return;

    if (root->lchild == NULL && root->rchild == NULL) {
        (*num)++;
    }
    LeafNum(root->lchild, num);
    LeafNum(root->rchild, num);
}

void CreatBinaryTree() {
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

    int leafnum = 0;
    LeafNum(&node1, &leafnum);
    printf("%d\n", leafnum);

}

int main() {
    CreatBinaryTree();
    return 0;
}