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

#include <iostream>
#include <chrono>
#include "raylib.h"
#include "include/screen.hpp"
#include "include/sounds.hpp"
#include "include/state.hpp"
#include "include/inputs.hpp"
#include "include/physics.hpp"

int main()
{
    InitWindow(Game::Screen::Width, Game::Screen::Height, "Game");

    InitAudioDevice();      // Initialize audio device

    SetTargetFPS(60);       // Set our game to run at 60 frames-per-second
	constexpr int gameLogicTPS = 60;						// Game logic is updated 60 times per second
	constexpr double gameLogicTickInNs = (1/gameLogicTPS)*1000000000;	// Tick duration in nanoseconds

	Game::SoundCollection sounds;
	Game::State state;

	state.startGame();
	
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
		const auto frameStart = std::chrono::steady_clock::now();

		Game::Inputs::handleInput(state);
		Game::Physics::update(state);

        BeginDrawing();

		ClearBackground(BLACK);
		DrawRectangle(state.player.position.x, state.player.position.y,
			state.player.w, state.player.h, WHITE);
		DrawRectangle(state.enemy.position.x, state.enemy.position.y,
			state.enemy.w, state.enemy.h, WHITE);
		DrawCircle(state.ball.position.x, state.ball.position.y,
			state.ball.r, WHITE);

        EndDrawing();

		while (true) {
			const auto frameEnd = std::chrono::steady_clock::now();
			auto ellapsed = std::chrono::duration_cast<std::chrono::microseconds>(
				frameEnd - frameStart).count();
			if (ellapsed >= gameLogicTickInNs) break;
		}
    }

    // Unload global data loaded
    CloseAudioDevice();     // Close audio context
    CloseWindow();          // Close window and OpenGL context

    return 0;
}
