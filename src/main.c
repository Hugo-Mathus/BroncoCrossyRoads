/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"
#include "player.h"
#include <math.h> 
#include <stdbool.h>
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

	// 0 - grass
//{0,0,0,0,0,0,0,0,0,0},
	// 1 - road
//{1,1,1,1,1,1,1,1,1,1},
	// 2 - water
//{2,2,2,2,2,2,2,2,2,2},

	//0.1 - tree
	//0.2 - coin

double map[6][10] = {
		{2,2,2,2,2,2,2,2,2,2},
		{0,0,0,0,0,0,0,0,0,0},
		{2,2,2,2,2,2,2,2,2,2},
		{0,0,0.1,0,0,0,0,0,0,0.1},
		{1,1,1,1,1,1,1,1,1,1},
		{0.1,0.1,0.1,0.1,0,0.1,0.1,0.1,0.1,0.1}
	};

int score = 0;


double getID(int x, int y) {
	return map[y][x];
}

bool isTree(int x, int y){
	if((x >= 0 || x <= 9) && (y >= 0 || y <= 5)){
		if(fmod(map[y][x]*10,10) == 1){
			return true;
		}
		return false;
	}

	return true;
	
}

void checkCoins(Player *p) {
    int x = getX(p) / 100;
    int y = getY(p) / 100;

    if (fmod(map[y][x] * 10, 10) == 2) {
        map[y][x] -= 0.2;
		score++;
    }
}


int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(1000, 600, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Image treeImage = LoadImage("Tree2.png");
	ImageResize(&treeImage, 100, 100);
	Texture tree = LoadTextureFromImage(treeImage);
	UnloadImage(treeImage);

	Image billyImage = LoadImage("Billy_PC.png");
	ImageResize(&billyImage, 100, 100);
	Texture billy = LoadTextureFromImage(billyImage);
	UnloadImage(billyImage);

	Image coinImage = LoadImage("bc_coin.PNG");
	ImageResize(&coinImage, 100, 100);
	Texture coin = LoadTextureFromImage(coinImage);
	UnloadImage(coinImage);

	Image roadImage = LoadImage("bc_road.PNG");
	ImageResize(&roadImage, 100, 100);
	Texture road = LoadTextureFromImage(roadImage);
	UnloadImage(roadImage);

	Image grassImage = LoadImage("bc_grass.PNG");
	ImageResize(&grassImage, 100, 100);
	Texture grass = LoadTextureFromImage(grassImage);
	UnloadImage(grassImage);

	Image waterImage = LoadImage("bc_water.PNG");
	ImageResize(&waterImage, 100, 100);
	Texture water = LoadTextureFromImage(waterImage);
	UnloadImage(waterImage);


	int height = 6;
	int width = 10;

	Player player;
	createPlayer(&player);

	int x = 0;
	int y = 0;

	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		for(int i = 0; i < width; i++) {
			for(int j = 0; j < height; j++) {
				
				if((int)map[j][i] == 1) {
					DrawTexture(road, (i*100), (j*100), WHITE);
					// DrawRectangle(i*100, j*100, 100, 100, GRAY);
				} else if((int)map[j][i] == 2) {
					DrawTexture(water, (i*100), (j*100), WHITE);
				} else {
					DrawTexture(grass, (i*100), (j*100), WHITE);

				}

			}
		}


		for(int i = 0; i < width; i++) {
			for(int j = 0; j < height; j++) {
				if(isTree(i, j)) {
					DrawTexture(tree, (i*100), (j*100), WHITE);
					// DrawRectangle((i*100) + 25, (j*100) + 25, 50, 50, DARKGREEN);
				} else if(fmod(map[j][i]*10,10) == 2) {
					DrawTexture(coin, (i*100), (j*100), WHITE);
					// DrawRectangle((i*100) + 25, (j*100) + 25, 50, 50, YELLOW);
				}

			}

		}


		// movePlayer(&player);
		x = getX(&player)/100;
		y = getY(&player)/100;


		movePlayer(&player, isTree(x, y-1), isTree(x, y+1), isTree(x-1, y), isTree(x+1, y) );
		checkCoins(&player);
		//Draw player
		DrawTexture(billy, getX(&player), getY(&player), WHITE);


		// // draw some text using the default font
		DrawText(TextFormat("Score: %d", score), 0,0,20,WHITE);

		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(tree);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}

