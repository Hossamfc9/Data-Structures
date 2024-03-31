#include<stdio.h>
#include<stdlib.h>

#define mx 100000

typedef struct stack {
    int top;
    int entry[mx];
}Stack;

void CreateStack(Stack *ptrs) {
    ptrs->top = 0;
}

int push(int e, Stack *ptrs) {
    if(ptrs->top == mx) {
        return 0;
    }
    ptrs->entry[ptrs->top++] = e;
    return 1;
}

int stackFull(Stack *ptrs) {
    return (ptrs->top == mx);
}

void pop(int *e, Stack* ptrs) {
    *e = ptrs->entry[--ptrs->top];
}

void stackTop(int *e, Stack* ptrs) {
    *e = ptrs->entry[ptrs->top - 1];
}

void display(int e) {
    printf("e is: %d\n", e);
}

void TraverseStack(Stack *ptrs, void(*pf)(int)) {
    for(int i = ptrs->top - 1; i >= 0; i--) {
        (*pf)(ptrs->entry[i]);
    }
}

int main(void) {
    Stack s;
    CreateStack(&s);
    printf("Hello, World");
}