#include <stdio.h>
#include <stdlib.h>

typedef struct LINK {
    int data;
    struct LINK* next;
}Link;

typedef struct STACK {
    Link* top;
    int size;
}Stack;

Stack* Init_Stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) return NULL;

    stack->size = 0;
    stack->top = NULL;
    return stack;
}

void Push_Stack(Stack* stack, int num) {
    if (!stack) return;
    
    Link* newnode = (Link*)malloc(sizeof(Link));
    if (!newnode) return;
    newnode->data = num;
    newnode->next = stack->top;
    stack->top = newnode;
    stack->size++;
}

void Pop_Stack(Stack* stack, int* num) {
    if(!stack->size) return;

    Link* p = stack->top;
    *num = stack->top->data;
    stack->top = stack->top->next;
    free(p);
    stack->size--;
}

int Size_Stack(Stack* stack) {
    return stack->size;
}

void Free_Stack(Stack* stack) {
    while (stack->size != 0) {
        Link* p = stack->top;
        stack->top = p->next;
        free(p);
        stack->size--;
    }

    free(stack);
}

void Print_Stack(Stack* stack) {
    if (!stack || stack->size == 0) return;

    Link* p = stack->top;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = Init_Stack();
    Push_Stack(stack, 100);
    Push_Stack(stack, 200);
    Push_Stack(stack, 300);

    Print_Stack(stack);
    printf("%d\n", Size_Stack(stack));

    int num;
    Pop_Stack(stack, &num);

    Print_Stack(stack);
    printf("%d\n", Size_Stack(stack));

    Free_Stack(stack);
}