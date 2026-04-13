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

void Delete(int n) {
    Node* temp = head;
    if (n == 1) {
        head = head->next; // 移动头指针
        free(temp);
    } else {
        Node* p = head;
        for (int i = 0; i < n-2; i++) {
            p = p->next;
        }
        Node* temp2 = p->next;
        p->next = temp2->next;
        free(temp2);
    }
    return;
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

int main() {
    head = NULL;
    Insert(2, 1);
    Insert(4, 2);
    Insert(5, 1);
    Insert(7, 4);
    Print();

    int n;
    scanf("%d", &n);
    Delete(n);
    Print();

    return 0;
}