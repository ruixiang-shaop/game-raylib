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
	if (Game::Inputs::isPlayerUp())
	{
		state.player.speed = -Player::DefaultSpeed;
	}
	else if (Game::Inputs::isPlayerDown())
	{
		state.player.speed = Player::DefaultSpeed;
	}
	else
	{
		state.player.speed = 0;
	}
}

}
