#include "include/physics.hpp"
#include "include/screen.hpp"
#include "raylib.h"

namespace Game
{

void Physics::update(State &state)
{
	state.player.update();
	state.enemy.update();
	state.ball.update();

	if ((state.ball.position.y <= 0) ||
		(state.ball.position.y >= Screen::Height))
	{
		state.ball.speed.y *= -1;
	}
	if ((state.ball.position.x <= 0) ||
		(state.ball.position.x >= Screen::Width))
	{
		state.ball.speed.x *= -1;
	}
}

}
