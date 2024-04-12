#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "Stack.h"

/**
 * Tree Implementation
 * 
 * this implements two types of tree where we consider calculating depth and size every single time,
 * or we calculate them when required.
*/

void CreateTree(Tree* pt) {
    *pt = NULL;
}

void CreateTree2(Tree2* pt) {
    pt->root = NULL;
    pt->depth = 0;
    pt->size = 0;
}

int TreeEmpty(Tree* pt) {
    return (!*pt);
}

int TreeEmpty(Tree2* pt) {
    return (!pt->root);
}

int TreeFull(Tree* pt) {
    return 0;
}

int TreeFull2(Tree* pt) {
    return 0;
}

void InorderRec(Tree* pt, void(*pvisit)(TreeEntry)) {
    if(*pt) {
        InorderRec(&(*pt)->left, pvisit);
        (*pvisit)((*pt)->entry);
        InorderRec(&(*pt)->right, pvisit);
    }
}

void InorderRec2(Tree2* pt, void(*pvisit)(TreeEntry)) {
    InorderRec(&pt->root, &pvisit);
}

void Inorder(Tree* pt, void(*pvisit)(TreeEntry)) {
    Stack s;
    void* p = (void *) (*pt);
    /**
     * p is going to be pushed to the stack, we used void pointer as a generic element
     *  to avoid using TreeNode* and include it in Stack.h
     * 
     * this could be avoided using a Template function in Object Oriented Programming if you use C++ :)
    */

    if(p) {
        CreateStack(&s);
        do {
         Push(p, &s);
         p = (void *) (((TreeNode*)p)->left);
         Pop(&p, &s);
         (*pvisit)(((TreeNode*)p)->entry);
         p = (void *) (((TreeNode*)p)->right);
        }while(!StackEmpty(&s) || p);
    }
}

void Inorder(Tree2* pt, void(*pvisit)(TreeEntry)) {
    Stack s;
    void* p = (void*)(pt->root);// the only difference from the above function.
    if(p) {
        CreateStack(&s);
        do {
         Push(p, &s);
         p = (void *) (((TreeNode*)p)->left);
         Pop(&p, &s);
         (*pvisit)(((TreeNode*)p)->entry);
         p = (void *) (((TreeNode*)p)->right);
        }while(StackEmpty(&s) || p);
    }
}

/*
void ClearTreeRec(Tree* pt) {
    if(*pt) {
        ClearTreeRec((*pt)->left);
        ClearTreeRec((*pt)->right);
        free(*pt);
        *pt = NULL;
    }
}
*/

/**
 * the above function is not wrong, altough there is a better implementation.
 * rather than clearing every pointer and assigning it to NULL, every pointer
 * is going to be deleted, so it's pointless to assign it to NULL, we can free
 * all tree nodes and assign the root to NULL for efficiency
*/

void ClearTreeRecAux(Tree* pt) {
    if(*pt) {
        ClearTreeAux((*pt)->left);
        ClearTreeAux((*pt)->right);
        free(*pt);
    }
}

void ClearTreeRec(Tree* pt) {
    ClearTreeRecAux(pt);
    *pt = NULL;
}

ClearTreeRec2(Tree2* pt) {
    ClearTreeRec(&(pt->root));
    pt->depth = 0;
    pt->size = 0;
}