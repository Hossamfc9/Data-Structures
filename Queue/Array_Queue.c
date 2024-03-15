#include <stdio.h>

#define MAXSIZE 100000

typedef struct queue {
    int front;
    int rear;
    int size;
    double entry[MAXSIZE];
}Queue;

void CreateQueue(Queue* pq) {
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}
/*Initializing front with 5 and rear with 4 is also right but you don't know
if the size of the queue is only 3 elements
*/

void Append(double e, Queue* pq) {
    pq->rear = (pq->rear + 1) % MAXSIZE;
    pq->entry[pq->rear] = e;
    ++pq->size;
}

void Serve(double* pe, Queue* pq) {
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % MAXSIZE;
    --pq->size;
}

int QueueEmpty(Queue* pq) {
    return (!pq->size);
}

int QueueFull(Queue* pq) {
    return (pq->size == MAXSIZE);
}

int QueueSize(Queue* pq) {
    return pq->size;
}

void ClearQueue(Queue* pq) {
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void TraverseQueue(Queue* pq, void (*pf)(double)) {
    for(int pos = pq->front, s = 0; s < pq->size; ++s) {
        (*pf)(pq->entry[pos]);
        pos = (pos + 1) % MAXSIZE;
    }
}

int main() {
    Queue q;
    CreateQueue(&q);
}