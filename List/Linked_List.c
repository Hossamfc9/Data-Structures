#include <stdio.h>

typedef struct listnode {
    double entry;
    struct listnode* next;
}typedef ListNode;

typedef struct list {
    ListNode* head;
    int size;
}typedef List;

void CreateList(List* pl) {
    pl->head = NULL;
    pl->size = 0;
}

int ListEmpty(List* pl) {
    return !pl->size;
}

int ListSize(List* pl) {
    return pl->size;
}

int ListFull(List* pl) { 
    return 0;
}

void DestroyList(List* pl) {
    
}

int main() {

}