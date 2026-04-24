#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* top;

void Push(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    
    temp->next = top;
    top = temp;

    return;
}

void Pop() {
    if (top == NULL) return;
    else {
        Node* temp = top;
        top = temp->next;
        free(temp);
    }
    return;
}

void Print() {
    Node* p = top;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

int main() {
    top = NULL;
    Push(1);Print();
    Push(2);Print();
    Push(3);Print();
    Pop();Print();
    Push(5);Print();

    return 0;
}