#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* head;

Node* GetNewNode(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void InsertAtHead(int x) {
    Node* temp = GetNewNode(x);
    if (head == NULL) {
        head = temp;
        return;
    } else {
        head->prev = temp;
        temp->next = head;
        head = temp;
        return;
    }
}

void InsertAtTail(int x) {
    Node* temp = GetNewNode(x);
    if (head == NULL) {
        head = temp;
        return;
    } else {
        Node* p = head;
        while (p->next) {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
        return;
    }
}

void Print() {
    Node* p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

void ReversePrint() {
    Node* p = head;
    while (p->next) {
        p = p->next;
    }
    while (p) {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
    return;
}

int main() {
    head = NULL;
    InsertAtHead(2);
    Print();
    ReversePrint();
    InsertAtHead(3);
    Print();
    ReversePrint();
    InsertAtHead(4);
    Print();
    ReversePrint();
    
    InsertAtTail(5);
    Print();
    ReversePrint();
    InsertAtTail(6);
    Print();
    ReversePrint();
    return 0;
}