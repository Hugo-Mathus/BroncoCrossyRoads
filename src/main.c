/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"
#include "player.h"
#include <math.h> 
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

double map[6][10] = {
		{0.2,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0.1,0.1,0,0.1,0.1,0,0,0},
		{1,1,1,1,1.2,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0.2,0,0,0.2,0,0,0,0}
	};

double getID(int x, int y) {
	return map[y][x];
}

bool isTree(int x, int y){

	if(fmod(map[y][x]*10,10) == 1){
		return true;
	}

	return false;
}

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	//TODO - Scale map to 128 by 128

	// Create the window and OpenGL context
	InitWindow(1000, 600, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Texture wabbit = LoadTexture("wabbit_alpha.png");

	int height = 6;
	int width = 10;

	Player player;
	createPlayer(&player);

	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		for(int i = 0; i < width; i++) {
			for(int j = 0; j < height; j++) {
				
				if((int)map[j][i] == 0) {
					DrawRectangle(i*100, j*100, 100, 100, GREEN);
				} else if((int)map[j][i] == 1) {
					DrawRectangle(i*100, j*100, 100, 100, GRAY);
				}

				if(isTree(i, j)) {
					DrawRectangle((i*100) + 25, (j*100) + 25, 50, 50, DARKGREEN);
				} else if(fmod(map[j][i]*10,10) == 2) {
					DrawRectangle((i*100) + 25, (j*100) + 25, 50, 50, YELLOW);
				}

			}
		}

		movePlayer(&player);
		drawPlayer(&player);

		// // draw some text using the default font
		// DrawText("Hello Raylib", 200,200,20,WHITE);

		// // draw our texture to the screen
		// DrawTexture(wabbit, 400, 200, WHITE);
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}

