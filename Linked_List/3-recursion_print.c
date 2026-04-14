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
    } else {
        printf("%d ", node->data);
        Print(node->next);
    }
} 

void RecursionPrint(Node* node) {
    if (node == NULL) {
        return;
    } else {
        RecursionPrint(node->next);
        printf("%d ", node->data);
    }
}

int main() {
    head = NULL;
    Insert(2, 1);
    Insert(9, 2);
    Insert(3, 1);
    Insert(7, 4);
    Print(head);
    RecursionPrint(head);
    printf("\n");

    return 0;
}