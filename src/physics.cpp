#include "include/physics.hpp"
#include "include/screen.hpp"
#include "lib/utils.hpp"
#include "raylib.h"

namespace Game
{

void Physics::update(State &state)
{
	auto &player = state.player;
	auto &enemy = state.enemy;
	auto &ball = state.ball;

	bool bounced = false;

	Vector2 newBallPosition = Utils::getNextPosition(ball.position, ball.speed);

	// Ball collision against left and right borders of the game border
	Rectangle leftBorder {Screen::GamePosition.x, Screen::GamePosition.y, 0, Screen::GamePosition.y+Screen::GameHeight};
	Rectangle rightBorder {Screen::GameWidth, Screen::GamePosition.y, 0, Screen::GamePosition.y+Screen::GameHeight};

	if (CheckCollisionCircleRec(newBallPosition, ball.r, leftBorder))
	{
		state.roundState = RoundState::Lose;
		return;
	}
	else if (CheckCollisionCircleRec(newBallPosition, ball.r, rightBorder))
	{
		state.roundState = RoundState::Win;
		return;
	}

	// Ball collision against top and bottom borders of the game border
	Rectangle topBorder {Screen::GamePosition.x, Screen::GamePosition.y, Screen::GameWidth, 0};
	Rectangle bottomBorder {Screen::GamePosition.x, Screen::GamePosition.y+Screen::GameHeight, Screen::GameWidth, 0};

	if (CheckCollisionCircleRec(newBallPosition, ball.r, topBorder) ||
		CheckCollisionCircleRec(newBallPosition, ball.r, bottomBorder))
	{
		ball.bounceVertical();
		bounced = true;
	}

	// Ball collision against player
	if (!bounced && CheckCollisionCircleRec(newBallPosition, ball.r, player.box))
	{
		switch (Utils::getCollisionSideRectCircle(player.box, ball.position))
		{
			case Side::Top:
			case Side::Bottom:
				ball.bounceVertical();
				break;
			case Side::Left:
			case Side::Right:
				ball.bounceHorizontal();
				break;
		}
	} 
	// Ball collision against enemy
	else if (!bounced && CheckCollisionCircleRec(newBallPosition, ball.r, enemy.box))
	{
		switch (Utils::getCollisionSideRectCircle(enemy.box, ball.position))
		{
			case Side::Top:
			case Side::Bottom:
				ball.bounceVertical();
				break;
			case Side::Left:
			case Side::Right:
				ball.bounceHorizontal();
				break;
		}
	}
	else if (!bounced)
	{
		ball.noBounce();
	}

	player.update();
	enemy.update();
	ball.update();
}

}
