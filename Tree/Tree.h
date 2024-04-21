#include"Global.h"

typedef struct treenode {
    TreeEntry entry;
    struct treenode *left, *right;
} TreeNode;

/*
    there are two definitions about tree, they both manage size and depth of the tree
    but in a different way.
    
    book defines that a tree is a root connected to a treenode, but this makes a problem
    in calculating size and depth because you need to do it every single time.

    you can see the two implementations are made down there.
*/

typedef TreeNode * Tree;

typedef struct tree {
    TreeNode* root;
    int size;
    int depth;
}Tree2;

void CreateTree(Tree*);
void ClearTree(Tree*);
int TreeSize(Tree*);
int TreeDepth(Tree*);
void Preorder(Tree*, void(*)(TreeEntry));
void Inorder(Tree*, void(*)(TreeEntry));
void Postorder(Tree*, void(*)(TreeEntry));
int TreeDepthRec(Tree*);
int TreeDepth2(Tree*);
void InsertTreeRec(Tree*, TreeEntry*);
void InsertTree2(Tree2*, TreeEntry*);