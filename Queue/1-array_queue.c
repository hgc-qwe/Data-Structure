#include <stdio.h>
int q[5];
int front = -1, rear = -1;

void Push(int x) {
    if ((rear + 1) % 5 == front) {
        printf("Is Full\n");
        return;
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        q[front] = x;
    } else {
        rear = (rear + 1) % 5;
        q[rear] = x;
    }
    return;
}

void Pop() {
    if (front == -1 && rear == -1) {
        printf("Is Empty\n");
        return;
    } else if (front == 0 && rear == 0) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % 5;
    }
    return;
}

void Front() {
    if (front == -1 && rear == -1) {
        printf("Is Empty\n");
        return;
    } else {
        printf("%d\n", q[front]);
    }
    return;
}

void Isempty() {
    if (front == -1 && rear == -1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return;
}

void Print() {
    if (front == -1 && rear == -1) return;
    else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
    return;
}

int main() {
    Isempty();
    Push(1);Print();
    Push(2);Print();
    Push(3);Print();
    Push(4);Print();
    Push(5);Print();
    Push(6);Print();

    Front();

    Pop();Print();
    Pop();Print();

    Front();
    Isempty();

    return 0;
}