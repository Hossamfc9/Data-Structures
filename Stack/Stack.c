#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

#ifdef Linked_Stack

void CreateStack(Stack* ps) {
    ps->top = NULL;
    ps->size = 0;
}


void Push(StackEntry e, Stack* ps) {
    StackNode* pn = (StackNode*)malloc(sizeof(StackNode));
    pn->val = e;
    pn->next = ps->top;
    ps->top = pn;
    ++ps->size;
}

void Pop(StackEntry* pe, Stack* ps) {
    StackNode* pn;
    *pe = ps->top->val;
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

void TraverseStack(Stack* ps, void (*pf) (StackEntry)) {
    StackNode* pn = ps->top;
    while(pn) {
        (*pf)(pn->val);
        pn = pn->next;
    }
}

int StackSize(Stack* ps) {
    return ps->size;
}

#endif

#ifdef Array_Stack

int push(StackEntry e, Stack *ptrs) {
    if(ptrs->top == MAXSTACK) {
        return 0;
    }
    ptrs->entry[ptrs->top++] = e;
    return 1;
}

int stackFull(Stack *ptrs) {
    return (ptrs->top == MAXSTACK);
}

void pop(StackEntry *e, Stack* ptrs) {
    *e = ptrs->entry[--ptrs->top];
}

void stackTop(StackEntry *e, Stack* ptrs) {
    *e = ptrs->entry[ptrs->top - 1];
}

void display(int e) {
    printf("e is: %d\n", e);
}

void TraverseStack(Stack *ptrs, void(*pf)(StackEntry)) {
    for(int i = ptrs->top - 1; i >= 0; i--) {
        (*pf)(ptrs->entry[i]);
    }
}

#endif