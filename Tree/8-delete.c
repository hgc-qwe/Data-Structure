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
    if (root == NULL) root = GetNewNode(x);
    else if (x <= root->data) root->left = Insert(root->left, x);
    else root->right = Insert(root->right, x);
    return root;
}

Node* Min(Node* root) {
    if (root == NULL) return NULL;
    if (root->left == NULL) return root;
    return Min(root->left);
}

Node* Delete(Node* root, char x) {
    if (root == NULL) return root;
    if (x < root->data) root->left = Delete(root->left, x);
    else if (x > root->data) root->right = Delete(root->right, x);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
        } else {
            Node* temp = Min(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void Print(Node* root) {
    if (root == NULL) return;
    Print(root->left);
    printf("%c ", root->data);
    Print(root->right);
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

    Print(root);
    printf("\n");

    root = Delete(root, 'G');

    Print(root);
    printf("\n");

    return 0;
}