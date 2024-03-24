#include <stdio.h>
#include <stdlib.h>

typedef struct queuenode {
    double entry;
    struct queuenode* next;
}QueueNode;

typedef struct queue {
    QueueNode* front;
    QueueNode* rear;
    int size;
}Queue;

void CreateQueue(Queue* pq) {
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

int Append(double e, Queue* pq) {
    QueueNode* pn = (QueueNode*)malloc(sizeof(double));
    /*
        if malloc function fails to allocate a memory for pointer.
    */
    if(!pn) {
        return 0;
    }
    pn->next = NULL;
    pn->entry = e;
    if(!pq->rear) {
        pq->front = pn;
    }
    else {
        pq->rear->next = pn;
    }
    pq->rear = pn;
    ++pq->size;
    // process succeeded, return one to state that.
    return 1;
}
/*
...
if(!Append(e, &q)) {
    ...
}
*/

void Serve(double* pe, Queue* pq) {
    QueueNode* pn = pq->front;
    *pe = pq->front->entry;
    pq->front = pq->front->next;
    free(pn);
    if(!pq->front) {
        pq->rear = NULL;
    }
    --pq->size;
}

void ClearQueue(Queue* pq) {
    while(pq->front) {
        pq->rear = pq->front->next;
        free(pq->front);
        pq->front = pq->rear;
    }
    pq->size = 0;
}

void TraverseQueue(Queue* pq, void(*pf)(double)) {
    for(QueueNode* pn = pq->front; pn != NULL; pn = pn->next) {
        (*pf)(pn->entry);
    }
}

int QueueEmpty(Queue* pq) {
    return (!pq->front);
}

int QueueFull(Queue* pq) {
    return 0;
}

int QueueSize(Queue* pq) {
    return pq->size;
}

int main() {
    Queue q;
    CreateQueue(&q);
}