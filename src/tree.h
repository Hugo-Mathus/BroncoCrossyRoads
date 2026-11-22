#ifndef TREE_H
#define TREE_H

#include "raylib.h"

typedef struct{
    Rectangle rectangle;
} Tree;

void createTree(Tree *tree, float x, float y, float width, float height);
void drawTree(Tree *tree);

#endif