#include <iostream>
#include <queue>
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

void Print(Node* root) {
    if (root == nullptr) {
        return;
    } else {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            cout << curr->data << " ";
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
            q.pop();
        }
        cout << endl;
    }
    return;
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
}