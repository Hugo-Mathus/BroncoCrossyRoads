#include "tree.h"

void createTree(Tree *tree, int x, int y){
    tree -> x = x;
    tree -> y = y;
}

int getTreeX(Tree *tree){
    return tree->x;
}

int getTreeY(Tree *tree){
    return tree->y;
}