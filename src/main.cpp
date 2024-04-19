/*******************************************************************************************
*
*   raylib game template
*
*   <Game title>
*   <Game description>
*
*   This game has been created using raylib (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2021 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "include/screen.hpp"
#include "include/sounds.hpp"
#include <iostream>

int main()
{
    // Initialization
    //---------------------------------------------------------
    InitWindow(Screen::width, Screen::height, "Game");

    InitAudioDevice();      // Initialize audio device

	Game::SoundCollection sounds;

    SetTargetFPS(60);       // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
	int i = 0;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
		i++;
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawFPS(Screen::width-100, 10);

        EndDrawing();
		if (i % 100 == 0) sounds.play(Game::SoundTypes::Hit);
    }


    // Unload global data loaded
    CloseAudioDevice();     // Close audio context
    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
