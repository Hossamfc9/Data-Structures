#include <stdio.h>

#define mx 100000

typedef struct list {
    double entry[mx];
    int size;
}List;

void CreateList(List* pl) {
    pl->size = 0;
}

int ListEmpty(List* pl) {
    return !pl->size;
}

int ListFull(List* pl) {
    return pl->size == mx;
}

int ListSize(List* pl) {
    return pl->size;
}

void EmptyList(List* pl) {
    pl->size = 0;
}

void InesrtList(int p, double e, List* pl) {
    for(int i = pl->size - 1; i >= p; --i) {
        pl->entry[i + 1] = pl->entry[i];
    }
    pl->entry[p] = e;
    ++pl->size;
}

void DeleteList(int p, double* pe, List* pl) {
    *pe = pl->entry[p];
    for(int i = p + 1; i <= pl->size - 1; ++i) {
        pl->entry[i - 1] = pl->entry[i];
    }
    --pl->size;
}

void RetriveList(int p, double* pe, List* pl) {
    *pe = pl->entry[p];
}

void ReplaceList(int p, double e, List* pl) {
    pl->entry[p] = e;
}

void TraverseList(List* pl, void(*visit)(double)) {
    for(int i = 0; i < pl->size; ++i) {
        (*visit)(pl->entry[i]);
    }
}

int main () {

}