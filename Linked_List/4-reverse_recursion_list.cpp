#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* head;

void Insert(int data, int n) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (n == 1) {
        temp->next = head;
        head = temp;
    } else {
        Node* p = head;
        for (int i = 0; i < n-2; i++) {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
    return;
}

void Print(Node* node) {
    if (node == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", node->data);
    Print(node->next);
}

void Reverse(Node* node) {
    if (node->next == NULL) {
        head = node;
        return;
    }
    Reverse(node->next);
    Node* q = node->next;
    q->next = node;
    node->next = NULL;
}

int main() {
    head = NULL;
    Insert(3, 1);
    Insert(4, 2);
    Insert(5, 3);
    Insert(6, 4);
    Print(head);

    Reverse(head);
    Print(head);

    return 0;
}