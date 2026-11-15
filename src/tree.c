#include "tree.h"

void createTree(Tree *tree, float x, float y, float width, float height)
{
    tree->rectangle.x = x;
    tree->rectangle.y = y;
    tree->rectangle.width = width;
    tree->rectangle.height = height;
}

void drawTree(Tree *tree)
{
    DrawRectangleRec(tree->rectangle, DARKGREEN);
}