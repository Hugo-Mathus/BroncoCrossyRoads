#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "player.h"
#include "tree.h"
#include "car.h"

int playerHitsTree(const Player *player, const Tree *tree);
int playerHitsCar(const Player *player, const Car *car);

#endif