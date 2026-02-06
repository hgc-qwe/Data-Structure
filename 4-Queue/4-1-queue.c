#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct QUEUE {
    int data[MAX_SIZE];
    int front;
    int rear;
}Queue;

Queue* Init_Queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = 0;

    return queue;
}

void Push_Queue(Queue* queue, int num) {
    if ((queue->rear + 1) % MAX_SIZE == queue->front) return;

    queue->data[queue->rear] = num;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
}

void Pop_Queue(Queue* queue, int* num) {
    if (queue->front == queue->rear) return;

    *num = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
}

int Num_Queue(Queue* queue) {
    if (!queue) return 0;

    return (queue->rear + MAX_SIZE - queue->front) % MAX_SIZE;
}

void Free_Queue(Queue* queue) {
    free(queue);
}

void Print_Queue(Queue* queue) {
    if (queue->front == queue->rear) return;

    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    Queue* queue = Init_Queue();

    Push_Queue(queue, 10);
    Push_Queue(queue, 20);
    Push_Queue(queue, 30);

    printf("%d\n", Num_Queue(queue));
    Print_Queue(queue);

    int num;
    Pop_Queue(queue, &num);

    printf("%d\n", Num_Queue(queue));
    Print_Queue(queue);

    Free_Queue(queue);

    return 0;
}