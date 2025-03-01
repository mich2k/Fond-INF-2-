#include "tree_int.h"
#include <stdlib.h>

extern Node* DeleteBstNode(Node*, const ElemType*);

Node* DeleteBstNode(Node*n, const ElemType*key){
    if(IsEmptyTree(n) || *key == *GetRootValueTree(n))
        return NULL;
    Node* root_pos = n;
    while(ElemCompare(GetRootValueTree(n), key) != 0){
        if(ElemCompare(GetRootValueTree(n), key) < 0)
            n = RightTree(n);
        else
            n = LeftTree(n);        
    }

    if(IsLeafTree(n))
        n->value = NULL;
    else
        DeleteTree(n);
    return root_pos;
}


// INPUT ALBERO BST

int main(void) {
    ElemType v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* tree = CreateRootTree(
        &v[6],
        CreateRootTree(
            &v[4], CreateRootTree(&v[2], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &v[5], CreateRootTree(&v[7], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[8], CreateEmptyTree(), CreateEmptyTree())));

    WriteStdoutInOrderTree(tree);   //BST
    DeleteBstNode(tree, &v[8]);
    WriteStdoutInOrderTree(tree);   //BST
    DeleteTree(tree);
    return EXIT_SUCCESS;
}