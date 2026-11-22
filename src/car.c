#include "car.h"

void createCar(Car *car, float x, float y, float width, float height, float speed, int direction){
    car -> rectangle.x = x;
    car -> rectangle.y = y;

    car -> rectangle.width = width;
    car -> rectangle.height = height;

    car -> speed = speed;
    car -> direction = direction;
}

void updateCar(Car *car, int screenWidth)
{
    car->rectangle.x += car->speed * car->direction * GetFrameTime();

    // Moving right
    if (car->direction == 1 &&
        car->rectangle.x > screenWidth)
    {
        car->rectangle.x = -car->rectangle.width;
    }

    // Moving left
    if (car->direction == -1 &&
        car->rectangle.x + car->rectangle.width < 0)
    {
        car->rectangle.x = screenWidth;
    }
}
void drawCar(Car *car)
{
    DrawRectangleRec(car->rectangle, BLUE);
}