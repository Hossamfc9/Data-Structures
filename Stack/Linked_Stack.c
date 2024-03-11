#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct stacknode {
    int val;
    struct StackNode* next;
}StackNode;

typedef struct stack {
    StackNode* top;
    int size;
}Stack;

void CreateStack(Stack* ps) {
    ps->top = NULL;
    ps->size = 0;
}


void Push(int e, Stack* ps) {
    StackNode* pn = (StackNode*)malloc(sizeof(StackNode));
    pn->val = e;
    pn->next = ps->top;
    ps->top = pn;
    ++ps->size;
}

void Pop(int* pe, Stack* ps) {
    StackNode* pn;
    pe = ps->top->val;
    pn = ps->top;
    ps->top = ps->top->next;
    free(pn);
    --ps->size;
}

int StackEmpty(Stack* ps) {
    return (ps->top == NULL);
}

int StackFull(Stack* ps) {
    return (int)NULL;
}

void ClearStack(Stack* ps) {
    StackNode* pn = ps->top;
    while(pn) {
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }
}

void TraverseStack(Stack* ps, void (*pf) (int)) {
    StackNode* pn = ps->top;
    while(pn) {
        (*pf)(pn->val);
        pn = pn->next;
    }
}

int StackSize(Stack* ps) {
    return ps->size;
}

int main(void) {
    Stack s;
    printf("Hello, World!");
}