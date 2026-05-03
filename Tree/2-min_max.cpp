#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int x) {
    Node* node = new Node();
    node->data = x;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* Insert(Node* root, int x) {
    if (root == nullptr) {
        root = GetNewNode(x);
    } else if (x <= root->data) {
        root->left = Insert(root->left, x);
    } else {
        root->right = Insert(root->right, x);
    }
    return root;
}

int Min(Node* root) {
    if (root == nullptr) return -1;
    else if (root->left == nullptr) return root->data;
    else return Min(root->left);
}

int Max(Node* root) {
    if (root == nullptr) return -1;
    else if (root->right == nullptr) return root->data;
    else return Min(root->right);
}

int main() {
    Node* root = nullptr;
    
    root = Insert(root, 15);
    root = Insert(root, 9);
    root = Insert(root, 26);
    root = Insert(root, 8);
    root = Insert(root, 11);

    cout << Min(root) << endl;
    cout << Max(root) << endl;
    return 0;
}