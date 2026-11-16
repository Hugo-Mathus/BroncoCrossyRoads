#ifndef PLAYER_H
#define PLAYER_H

typedef struct{
  int x;
  int y;
} Player;

void createPlayer(Player *player);
int getX(const Player *player);
int getY(const Player *player);
void movePlayer(Player *player);

void drawPlayer(const Player *player);

#endif