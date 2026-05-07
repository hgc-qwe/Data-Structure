#include <iostream>
#include <climits>
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
    if (root == nullptr) root = GetNewNode(x);
    else if (x <= root->data) root->left = Insert(root->left, x);
    else root->right = Insert(root->right, x);
    return root;
}

bool IsLesser(Node* root, int x) {
    if (root == nullptr) return true;
    if (root->data <= x && IsLesser(root->left, x) && IsLesser(root->right, x)) return true;
    else return false;
}

bool IsGreater(Node* root, int x) {
    if (root == nullptr) return true;
    if (root->data > x && IsGreater(root->left, x) && IsGreater(root->right, x)) return true;
    else return false;
}

bool Check(Node* root) {
    if (root == nullptr) return true;
    if (IsLesser(root->left, root->data) && IsGreater(root->right, root->data) && Check(root->left) && Check(root->right)) return true;
    else return false;
}

bool Check1(Node* root, int min, int max) {
    if (root == nullptr) return true;
    if (root->data > min && root->data < max && Check1(root->left, min, root->data) && Check1(root->right, root->data, max)) return true;
    else return false;
}

int main() {
    Node* root = nullptr;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 8);
    root = Insert(root, 12);

    cout << Check(root) << endl;
    cout << Check1(root, INT_MIN, INT_MAX) << endl;
    return 0;
}