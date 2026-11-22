#include "player.h"
#include "raylib.h"
#include <stdbool.h>


#define MAP_W GetScreenWidth()
#define MAP_H GetScreenHeight()
#define PLAYER_SPEED 3
#define PLAYER_SIZE 100

//32*32 and player's x y position is for top left corner 

void createPlayer(Player *player){
  player->x = PLAYER_SIZE* 4;
  player->y = MAP_H - PLAYER_SIZE;
}

int getX(const Player *player) {
    return player->x;
}

int getY(const Player *player) {
    return player->y;
}



//make sure it moves inside of the map
static int moveInsideX(Player *player, int x){
  if(x<0){
    return 0;
  }
  else if(x >= MAP_W - PLAYER_SIZE){
    return MAP_W - PLAYER_SIZE;
  }
  else{
    return x;
  }

}

static int moveInsideY(Player *player, int y){
  if(y<PLAYER_SIZE*3){
    return PLAYER_SIZE*3;
  }
  else if(y >= MAP_H - PLAYER_SIZE){
    return MAP_H - PLAYER_SIZE;
  }
  else{
    return y;
  }

}

static void move(Player *player, int dx, int dy){
  int newX, newY;
  newX = getX(player) + dx;
  newY = getY(player) + dy;

  // if(isTree(newX, newY)){
  //   return 0;
  // }

  player->x = moveInsideX(player, newX);
  player->y = moveInsideY(player, newY);
}

// void movePlayer(Player *player){
//   int key = GetKeyPressed();
//   switch(key){
//     case KEY_W:
//     case KEY_UP:
//       move(player, 0, -PLAYER_SIZE);
//       break;
//     case KEY_S:
//     case KEY_DOWN:
//       move(player, 0, PLAYER_SIZE);
//       break;
//     case KEY_A:
//     case KEY_LEFT:
//       move(player, -PLAYER_SIZE, 0);
//       break;
//     case KEY_D:
//     case KEY_RIGHT:
//       move(player, PLAYER_SIZE, 0);
//       break;
//     default:
//       break;
//   }
// }


void movePlayer(Player *player, bool up, bool down, bool left, bool right){
  int key = GetKeyPressed();
  switch(key){
    case KEY_W:
    case KEY_UP:
      if(!up) {
        move(player, 0, -PLAYER_SIZE);
      }
      break;
    case KEY_S:
    case KEY_DOWN:
      if(!down){
        move(player, 0, PLAYER_SIZE);
      }
      break;
    case KEY_A:
    case KEY_LEFT:
      if(!left) {
        move(player, -PLAYER_SIZE, 0);
      }
      break;
    case KEY_D:
    case KEY_RIGHT:
      if (!right){
        move(player, PLAYER_SIZE, 0);
      }
      break;
    default:
      break;
  }
}



//gcc src/main.c src/player.c -o game -I"$(brew --prefix raylib)/include" -L"$(brew --prefix raylib)/lib" -lraylib
