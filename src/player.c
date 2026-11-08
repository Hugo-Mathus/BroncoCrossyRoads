#include "player.h"
#include "raylib.h"
#include "stdbool.h"
void createPlayer(Player *player){
  player->x = MAP_WIDTH/2;
  player->y = 0;
}

int getX(Player *player){
  return player->x;
}

int getY(Player *player){
  return player->y;
}

//make sure it moves inside of the map
static bool canMove(Player *player, int x, int y){
  return x>=0 && x<=MAP_WIDTH && y>=0 && y<=MAP_HEIGHT;
}

static void move(Player *player, int dx, int dy){
  int newX, newY;
  newX = getX(player) + dx;
  newY = getY(player) + dy;
  if(canMove(player, newX, newY)){
    player->x = newX;
    player->y = newY;
  }
}

void movePlayer(Player *player){
  int key = GetKeyPressed();
  switch(key){
    case KEY_W:
    case KEY_UP:
      move(player, 0, -1);
      break;
    case KEY_S:
    case KEY_DOWN:
      move(player, 0, 1);
      break;
    case KEY_A:
    case KEY_LEFT:
      move(player, -1, 0);
      break;
    case KEY_D:
    case KEY_RIGHT:
      move(player, 1, 0);
      break;
    default:
      break;
  }
}

