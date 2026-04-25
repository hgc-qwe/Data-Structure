#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head;

void Init() {
    for (int i = 0; i < 5; i++) {
        Node* temp = new Node;
        temp->data = i + 1;
        temp->next = nullptr;
        
        temp->next = head;
        head = temp;
    }
    return;
}

void Print() {
    Node* p = head;
    while (p) {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
    return;
}

void Reverse() {
    stack<Node*> s;
    if (head == nullptr) return;
    Node* p = head;
    while (p) {
        s.push(p);
        p = p->next;
    }
    
    p = s.top();
    head = p;
    s.pop();
    while (!s.empty()) {
        p->next = s.top();
        s.pop();
        p = p->next;
    }
    p->next = nullptr;
}

void FreeList() {
    Node* p = head;
    while (p) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    head = nullptr;
    Init();
    Print();

    Reverse();
    Print();

    FreeList();

    return 0;
}