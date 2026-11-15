#ifndef TREE_H
#define TREE_H

typedef struct{
    int x;
    int y;
} Tree;

void createTree(Tree *tree, int x, int y);
int getTreeX(Tree *tree);
int getTreeY(Tree *tree);

#endif