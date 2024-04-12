#include "Global.h"

//#define Linked_Stack
#define Array_Stack

#ifdef Linked_Stack

/**
 * Linked Stack Implementation
*/ 

typedef struct stacknode {
    StackEntry val;
    struct stacknode* next;
}StackNode;

typedef struct stack {
    StackNode* top;
    int size;
}Stack;

#endif

#ifdef Array_Stack

typedef struct stack {
    int top;
    StackEntry entry[MAXSTACK];
}Stack;

#endif

/**
 * Implemented functions in Stack.c
 * 
 * every function has two implementations(Array, Linked)
*/

void CreateStack(Stack*);
int StackTop(Stack*);
int StackSize(Stack*);
void Push(StackEntry*, Stack*);
int Pop(StackEntry*, Stack*);
int StackEmpty(Stack*);
int StackFull(Stack*);
void ClearStack(Stack*);
void TraverseStack(Stack*);