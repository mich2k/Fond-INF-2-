#include "tree_int.h"
#include <stdlib.h>

extern const ElemType* TreeMax(const Node*);
void TreeMaxRec(const Node*, ElemType*);

void TreeMaxRec(const Node* n, ElemType* max){
    if(IsEmptyTree(n))
        return;
    if(n->value > *max)
        *max = (ElemType) n->value;
    TreeMaxRec(LeftTree(n), max);
    TreeMaxRec(RightTree(n), max);
}

const ElemType* TreeMax(const Node* n){
    if(IsEmptyTree(n))
        return NULL;
    ElemType* max = (ElemType*) GetRootValueTree(n);
    TreeMaxRec(n,max);
    return max;
}

int main(void) {
    ElemType v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* tree = CreateRootTree(
        &v[6],
        CreateRootTree(
            &v[2], CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[9], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &v[3], CreateRootTree(&v[4], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree())));
    ElemType max = *TreeMax(tree);
    DeleteTree(tree);
    return EXIT_SUCCESS;
}