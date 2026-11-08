#ifndef PLAYER_H
#define PLAYER_H

typedef struct{
  int x;
  int y;
} Player;

void createPlayer(Player *player);
int getX(Player *player);
int getY(Player *player);
void movePlayer(Player *player);

#endif