#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* CreatNewNode (int x) {
    Node* node = new Node();
    node->data = x;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

Node* Insert(Node* root, int x) {
    if (root == nullptr) {
        root = CreatNewNode(x);
    } else if (x <= root->data) {
        root->left = Insert(root->left, x);
    } else {
        root->right = Insert(root->right, x);
    }
    return root;
}

void Print(Node* root) {
    if (root == nullptr) return;
    Print(root->left);
    printf("%d ", root->data);
    Print(root->right);
}

Node* Find(Node* root, int x) {
    if (root == nullptr) return nullptr;
    if (x == root->data) return root;
    else if (x < root->data) return Find(root->left, x);
    else return Find(root->right, x);
}

Node* Min(Node* root) {
    if (root == nullptr) return nullptr;
    if (root->left == nullptr) return root;
    else return Min(root->left);
}

Node* Successor(Node* root, int x) {
    Node* curr = Find(root, x);
    if (curr == nullptr) return nullptr;
    if (curr->right != nullptr) return Min(curr->right);
    else {
        Node* su = NULL;
        Node* an = root;
        while (an != curr) {
            if (curr->data < an->data) {
                su = an;
                an = an->left;
            } else an = an->right;
        }
        return su;
    }
}

int main() {
    Node* root = nullptr;
    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 3);
    root = Insert(root, 7);
    root = Insert(root, 12);
    root = Insert(root, 18);
    root = Insert(root, 5);

    Print(root);
    printf("\n");

    Node* res = Successor(root, 7);
    if (res != nullptr) cout << res->data << endl;
    return 0;
}