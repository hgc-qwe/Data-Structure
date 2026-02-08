#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* s1;
    int* s2;
    int top1;
    int top2;
    int size;
}MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->size = 100;
    queue->s1 = (int*)malloc(queue->size * sizeof(int));
    queue->s2 = (int*)malloc(queue->size * sizeof(int));
    queue->top1 = -1;
    queue->top2 = -1;

    return queue;
}

void myQueuePush(MyQueue* queue, int x) {
    queue->s1[++(queue->top1)] = x;
}

int myQueuePop(MyQueue* queue) {
    if (queue->top2 == -1) {
        while (queue->top1 != -1) {
            queue->s2[++(queue->top2)] = queue->s1[(queue->top1)--];
        }
    }

    return queue->s2[(queue->top2)--];
}

int myQueuePeek(MyQueue* queue) {
    if (queue->top2 == -1) {
        while (queue->top1 != -1) {
            queue->s2[++(queue->top2)] = queue->s1[(queue->top1)--];
        }
    }

    return queue->s2[queue->top2];
}

bool myQueueEmpty(MyQueue* queue) {
    return (queue->top1 == -1 && queue->top2 == -1);
}

void myQueueFree(MyQueue* queue) {
    free(queue->s1);
    free(queue->s2);
    free(queue);
}

void myQueuePrint(MyQueue* queue) {
    if (myQueueEmpty(queue)) return;

    int t1 = queue->top1;
    int t2 = queue->top2;

    for (int i = t2; i >= 0; i--) {
        printf("%d ", queue->s2[i]);
    }
    for (int i = 0; i <= t1; i++) {
        printf("%d ", queue->s1[i]);
    }
    
    printf("\n");
}

int main() {
    MyQueue* queue = myQueueCreate();

    myQueuePush(queue, 10);
    myQueuePush(queue, 20);
    myQueuePush(queue, 30);
    myQueuePush(queue, 40);

    myQueuePrint(queue);

    int num;
    num = myQueuePop(queue);

    myQueuePrint(queue);

    printf("%d\n", myQueuePeek(queue));

    return 0;
}