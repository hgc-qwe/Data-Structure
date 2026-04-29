#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* front;
Node* rear;

void Push(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (front == NULL && rear == NULL) {
        front = temp;
        rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    return;
}

void Pop() {
    Node* temp = front;
    if (front == NULL && rear == NULL) {
        return;
    } else {
        front = front->next;
    }
    free(temp);
    return;
}

void Print() {
    if (front == NULL && rear == NULL) return;
    else {
        Node* p = front;
        while (p) {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
    return;
}

int main() {
    front = NULL;
    rear = NULL;

    Push(1);Print();
    Push(2);Print();
    Push(3);Print();
    Push(4);Print();
    Push(5);Print();

    Pop();Print();
    Pop();Print();
    Pop();Print();

    return 0;
}