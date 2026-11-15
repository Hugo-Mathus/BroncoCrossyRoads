#ifndef CAR_H
#define CAR_H

#include "raylib.h"

typedef struct{
    Rectangle rectangle;
    float speed;
    int direction;
} Car;

void createCar(Car *car, float x, float y, float width, float height, float speed, int direction);

void updateCar(Car *car, int screenWidth);

void drawCar(Car *car);

#endif