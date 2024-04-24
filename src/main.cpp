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
#include <ctime>
#include "raylib.h"
#include "include/screen.hpp"
#include "include/sounds.hpp"
#include "include/state.hpp"
#include "include/inputs.hpp"
#include "include/physics.hpp"

#include "lib/utils.hpp"

int main()
{
    std::srand(std::time(nullptr));

    InitWindow(Game::Screen::Width, Game::Screen::Height, "Game");

    InitAudioDevice();      // Initialize audio device

    SetTargetFPS(60);       // Set our game to run at 60 frames-per-second

	Game::SoundCollection sounds;
	Game::State state;

	state.startGame();
	
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
		Game::Inputs::handleInput(state);
		Game::Physics::update(state);
		
		if (state.ball.bounced) sounds.play(Game::SoundTypes::Hit);
		if (state.roundState != Game::RoundState::Playing)
		{
			if (state.roundState == Game::RoundState::Win)
			{
				state.playerPoints++;
			}
			else
			{
				state.enemyPoints++;
			}
			state.startGame();			
		}

        BeginDrawing();

		ClearBackground(BLACK);
		DrawLine(Game::Screen::GamePosition.x, Game::Screen::GamePosition.y,
			Game::Screen::GameWidth, Game::Screen::GamePosition.y, WHITE);
		DrawRectangle(state.player.box.x, state.player.box.y,
			state.player.box.width, state.player.box.height, WHITE);
		DrawRectangle(state.enemy.box.x, state.enemy.box.y,
			state.enemy.box.width, state.enemy.box.height, WHITE);
		DrawCircle(state.ball.position.x, state.ball.position.y,
			state.ball.r, WHITE);

		auto playerPointsText = std::to_string(state.playerPoints);
		auto enemyPointsText = std::to_string(state.enemyPoints);
		DrawText(playerPointsText.c_str(), Game::Screen::ScoreboardWidth/2-100, 0, Game::Screen::ScoreboardHeight, RED);
		DrawText(enemyPointsText.c_str(), Game::Screen::ScoreboardWidth/2+100, 0, Game::Screen::ScoreboardHeight, RED);

        EndDrawing();
    }

    // Unload global data loaded
    CloseAudioDevice();     // Close audio context
    CloseWindow();          // Close window and OpenGL context

    return 0;
}
