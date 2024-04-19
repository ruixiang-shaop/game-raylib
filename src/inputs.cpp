#include "include/inputs.hpp"
#include "raylib.h"

namespace Game
{

bool Inputs::isPlayerUp()
{
	return IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN);
}

bool Inputs::isPlayerDown()
{
	return IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_UP);
}

void Inputs::handleInput(State &state)
{
	const float PlayerDefaultSpeed = 5.0;
	if (Game::Inputs::isPlayerUp())
	{
		state.player.speed = -PlayerDefaultSpeed;
	}
	else if (Game::Inputs::isPlayerDown())
	{
		state.player.speed = PlayerDefaultSpeed;
	}
	else
	{
		state.player.speed = 0;
	}
}

}
