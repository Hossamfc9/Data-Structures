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

void Inorder2(Tree2* pt, void(*pvisit)(TreeEntry)) {
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

void ClearTreeRec2(Tree2* pt) {
    ClearTreeRec(&(pt->root));
    pt->depth = 0;
    pt->size = 0;
}

void InsertTreeRec(Tree* pt, TreeEntry* pe) {
    if(!*pt) {
        *pt = (Tree)malloc(sizeof(TreeNode));
        (*pt)->entry = *pe;
        (*pt)->left = NULL;
        (*pt)->right = NULL;
    }
    else if(LT(pe->key, (*pt)->entry.key)) {
        InsertTreeRec(&(*pt)->left, &pe);
    }
    else {
        InsertTreeRec(&(*pt)->right, &pe);
    }
}

void InsertTreeAux(Tree* pt, TreeEntry* pe, int* pdepth) {
    if(!(*pt)) {
        *pt = (Tree)malloc(sizeof(TreeNode));
        (*pt)->entry = *pe;
        (*pt)->left = NULL;
        (*pt)->right = NULL;
    }
    else if(LT(pe->key, (*pt)->entry.key)) {
        InsertTreeAux(&(*pt)->left,&pe, pdepth);
    }
    else {
        InsertTreeAux(&(*pt)->right, &pe, pdepth);
    }
    ++(*pdepth);
}

void InsertTreeRec2(Tree2* pt, TreeEntry* pe) {
    int d = 0;
    InsertTreeAux(&(pt->root), &pe, &d);
    pt->depth = max(pt->depth, d);
    ++pt->size;
}

/**
 * getting size and depth would differ from a design and the other.
*/

int TreeSizeRec(Tree* pt) {
    int size = 0;
    if(!pt) {
        return 0;
    }
    size = TreeSizeRec(&(*pt)->left) + TreeSizeRec(&(*pt)->right) + 1;
    return size;
}

int TreeSize2(Tree2* pt) {
    return pt->size;
}

int TreeDepthRec(Tree* pt) {
    if(!pt) {
        return 0;
    }
    int depth = max(TreeDepthRec(&(*pt)->left), TreeDepthRec(&(*pt)->right)) + 1;
    return depth;
}

int TreeDepth2(Tree2* pt) {
    return pt->depth;
}

void InsertTreeRec(Tree* pt, TreeEntry* pe) {
    if(!(*pt)) {
        *pt =  (Tree)malloc(sizeof(TreeNode));
        (*pt)->entry = *pe;
        (*pt)->left = NULL;
        (*pt)->right = NULL;
    }
    else if(LT(pe->key, (*pt)->entry.key)) {
        InsertTreeRec(&(*pt)->left, &pe);
    }
    else {
        InsertTreeRec(&(*pt)->right, &pe);
    }
}

/**
 * the above function could also be written itrativerly;
 * as all what you'll need is to insert without depending on the previous nodes
 * to put them in a stack.
*/

void InsertTree2(Tree2* pt, TreeEntry* pe) {
    TreeNode *p;
    int d = 1;
    p = (TreeNode*)malloc(sizeof(TreeNode));
    p->entry = *pe;
    p->left = NULL;
    p->right = NULL;
    if(!pt->root) {
        pt->root = p;
    }
    else {
        TreeNode *prev, *cur;
        cur = pt->root;
        while(cur != NULL) {
            prev = cur;
            if(LT(cur->entry.key, pe->key))
            {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
            ++d;
        }
        cur = p;
        /**
         * in video 19 minute 37:18 he made it in a different way.
         * if(LT(pe->key, cur->entry.key)) {
         *  prev->left = p;
         * }
         * else {
         *  prev->right = p;
         * }
         * 
         * it is the same as conditions already had been approved in the while loop
         * and cur accesses the same address.
        */
    }
    pt->depth = max(pt->depth, d);
}

/**
 * InsertTree(Tree* pt, TreeEntry* pe)
 * is the same implementation but we don't mention depth.
*/

int FindItemTreeRec(Tree* pt, TreeEntry* pe, KeyType k) {
    if(!*pt) {
        return 0;
    }
    if(EQ((*pt)->entry.key, k)) {
        *pe = (*pt)->entry;
        return 1;
    }
    if(LT(k, (*pt)->entry.key)) {
        return FindItemTreeRec((*pt)->left, pe, k);
    }
    else {
        return FindItemTreeRec((*pt)->right, pe, k);
    }
}

int FindItemTreeRec2(Tree2* pt, TreeEntry* pe, KeyType k) {
    return FindItemTreeRec(&pt->root, &pe, k);
}

int FindItemTree(Tree* pt, TreeEntry* pe, KeyType k) {
    int found = 0;
    TreeNode* p = *pt;
    while(p != NULL) {
        if(EQ(k, p->entry.key)) {
            found = 1;
            *pe = p->entry;
            break;
        }
        if(LT(k, p->entry.key)) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }
    return found;
}

void DeleteNodeTree(Tree* pt) {
    TreeNode *q = *pt, *r;
    if(!(*pt)->left) {
        *pt = (*pt)->right;
    }
    else if(!(*pt)->right) {
        *pt = (*pt)->left;
    }
    else {
        /*
        *pt = (*pt)->left;
        for(r = q->right; r->left; r = r->left);
        r->left = q->left;
        not very efficient solution.
        */
       q = (*pt)->left;
       if(!q->right) {
        (*pt)->entry = q->entry;
        (*pt)->left = q->left;
       }
       else {
        do {
            r = q;
            q = q->right;
        }while(q->right);
        (*pt)->entry = q->entry;
        r->right = q->left;
       }
    }
    free(q);
}

int DeleteItemTree(Tree* pt, TreeEntry* pe, KeyType k) {
    int found = 0;
    TreeNode* q = *pt, *prev = NULL;
    while(!q && !(found = EQ(k, q->entry.key))) {
        prev = q;
        if(LT(k, q->entry.key)) {
            q = q->left;
        }
        else {
            q = q->right;
        }
    }
    if(found) {
        *pe = q->entry;
        if(!prev) {
            DeleteNodeTree(pt);
        }
        else if(LT(k, prev->entry.key)) {
            DeleteNodeTree(&prev->left);
        }
        else {
            DeleteNodeTree(&prev->right);
        }
    }
}