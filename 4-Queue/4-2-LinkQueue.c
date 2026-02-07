#include <stdio.h>
#include <stdlib.h>

typedef struct LINKNODE {
    int data;
    struct LINKNODE* next;
}LinkNode;

typedef struct LINKQUEUE {
    LinkNode* front;
    LinkNode* rear;
}LinkQueue;

LinkQueue* Init_Queue() {
    LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue));
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

void Push_Queue(LinkQueue* queue, int num) {
    LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
    newnode->data = num;
    newnode->next = NULL;

    if (queue->front == NULL) {
        queue->front = newnode;
        queue->rear = newnode;
    } else {
        queue->rear->next = newnode;
        queue->rear = newnode;
    }
}

void Pop_Queue(LinkQueue* queue, int* num) {
    if (queue->front == NULL) return;

    *num = queue->front->data;
    LinkNode* temp = queue->front;
    
    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(temp);
}

void Print_Queue(LinkQueue* queue) {
    if (queue->front == NULL) return;

    LinkNode* p = queue->front;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void Free_Queue(LinkQueue* queue) {
    if (!queue) return;

    LinkNode* p = queue->front;
    while (p) {
        LinkNode* temp = p;
        p = p->next;
        free(temp);
    }
    free(queue);
}

int main() {
    LinkQueue* queue = Init_Queue();

    Push_Queue(queue, 10);
    Push_Queue(queue, 20);
    Push_Queue(queue, 30);
    Push_Queue(queue, 40);

    Print_Queue(queue);

    int num;
    Pop_Queue(queue, &num);

    Print_Queue(queue);

    Free_Queue(queue);

    return 0;
}