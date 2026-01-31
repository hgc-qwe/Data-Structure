#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct SQSTACK {
    int data[MAX_SIZE];
    int top;
}Stack;

Stack* Init_Stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        perror("malloc");
        return NULL;
    }
    stack->top = -1;

    return stack;
}

bool Push_Stack(Stack* stack, int num) {
    if (stack->top == MAX_SIZE - 1) return false;
    stack->data[++(stack->top)] = num;
    return true;
}

bool Pop_Stack(Stack* stack, int* num) {
    if (stack->top == -1) return false;
    *num = stack->data[(stack->top)--];
    return true;
}

void Print_Stack(Stack* stack) {
    if (!stack || stack->top == -1) return;

    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
}

void Free_Stack(Stack* stack) {
    free(stack);
}

int Size_Stack(Stack* stack) {
    return stack->top + 1;
}

int main() {
    Stack* stack = Init_Stack();

    Push_Stack(stack, 100);
    Push_Stack(stack, 200);

    Print_Stack(stack);
    printf("\n");

    int num;
    bool res = Pop_Stack(stack, &num);

    Print_Stack(stack);

    printf("\n%d\n", Size_Stack(stack));

    Free_Stack(stack);

    return 0;
}