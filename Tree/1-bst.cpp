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

bool Search(Node* root, int x) {
    if (root == nullptr) return false;
    else if (x == root->data) return true;
    else if (x < root->data) return Search(root->left, x);
    else return Search(root->right, x);
}

int main() {
    Node* root;
    root = nullptr;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 8);
    root = Insert(root, 12);

    cout << Search(root, 15) << endl;
    cout << Search(root, 10) << endl;
    cout << Search(root, 99) << endl;

    return 0;
}