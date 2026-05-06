#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
}Node;

Node* GetNewNode(char x) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* Insert(Node* root, char x) {
    if (root == NULL) {
        root = GetNewNode(x);
    } else if (x <= root->data) {
        root->left = Insert(root->left, x);
    } else {
        root->right = Insert(root->right, x);
    }
    return root;
}

void Preorder(Node* root) {
    if (root == NULL) return;

    printf("%c ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node* root) {
    if (root == NULL) return;

    Inorder(root->left);
    printf("%c ", root->data);
    Inorder(root->right);
}

void Postorder(Node* root) {
    if (root == NULL) return;

    Postorder(root->left);
    Postorder(root->right);
    printf("%c ", root->data);
}

int main() {
    Node* root = NULL;
    root = Insert(root, 'F');  
    root = Insert(root, 'D');
    root = Insert(root, 'J');
    root = Insert(root, 'B');
    root = Insert(root, 'E');
    root = Insert(root, 'G');
    root = Insert(root, 'K');
    root = Insert(root, 'A');
    root = Insert(root, 'C');
    root = Insert(root, 'I');
    root = Insert(root, 'H');

    Preorder(root);
    printf("\n");

    Inorder(root);
    printf("\n");

    Postorder(root);
    printf("\n");

    return 0;
}