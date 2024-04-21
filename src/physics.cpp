#include "include/physics.hpp"
#include "include/screen.hpp"
#include "raylib.h"

namespace Game
{

void Physics::update(State &state)
{
	auto &player = state.player;
	auto &enemy = state.enemy;
	auto &ball = state.ball;

	player.update();
	enemy.update();
	ball.update();

	Rectangle leftBorder {-1, 0, 1, Screen::Height};
	Rectangle rightBorder {Screen::Width, 0, 1, Screen::Height};

	if (CheckCollisionCircleRec(ball.position, ball.r, leftBorder))
	{
		state.roundState = RoundState::Lose;
		return;
	}
	else if (CheckCollisionCircleRec(ball.position, ball.r, rightBorder))
	{
		state.roundState = RoundState::Win;
		return;
	}

	Rectangle topBorder {0, 0, Screen::Width, 0};
	Rectangle bottomBorder {0, Screen::Height, Screen::Width, 0};

	if (CheckCollisionCircleRec(ball.position, ball.r, topBorder) ||
		CheckCollisionCircleRec(ball.position, ball.r, bottomBorder))
	{
		ball.speed.y *= -1;
		ball.bounced = true;
		
	}
	else if (CheckCollisionCircleRec(ball.position, ball.r, player.box) ||
		CheckCollisionCircleRec(ball.position, ball.r, enemy.box))
	{
		ball.speed.x *= -1;
		ball.bounced = true;
	}
	else
	{
		ball.bounced = false;
	}
}

}
