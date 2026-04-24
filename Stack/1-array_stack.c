#include <stdio.h>
#define MAX_SIZE 101
int arr[MAX_SIZE];
int top = -1;

void Push(int x) {
    if (top == MAX_SIZE - 1) {
        printf("To Much!\n");
        return;
    }
    arr[++top] = x;
    return;
}

void Pop() {
    if (top == -1) {
        printf("Is Empty!\n");
        return;
    }
    top--;
    return;
}

void Print() {
    for (int i = 0; i <= top; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

int main() {
    Push(1);Print();
    Push(2);Print();
    Push(3);Print();
    Pop();Print();
    Push(5);Print();

    return 0;
}