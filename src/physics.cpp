#include "include/physics.hpp"
#include "include/screen.hpp"
#include "lib/utils.hpp"
#include "raylib.h"
#include <iostream>

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

	// Ball collision against left and right borders of the game border
	Rectangle leftBorder {Screen::GamePosition.x, Screen::GamePosition.y, 0, Screen::GamePosition.y+Screen::GameHeight};
	Rectangle rightBorder {Screen::GameWidth, Screen::GamePosition.y, 0, Screen::GamePosition.y+Screen::GameHeight};

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

	// Ball collision against top and bottom borders of the game border
	Rectangle topBorder {Screen::GamePosition.x, Screen::GamePosition.y, Screen::GameWidth, 0};
	Rectangle bottomBorder {Screen::GamePosition.x, Screen::GamePosition.y+Screen::GameHeight, Screen::GameWidth, 0};

	if (CheckCollisionCircleRec(ball.position, ball.r, topBorder) ||
		CheckCollisionCircleRec(ball.position, ball.r, bottomBorder))
	{
		ball.bounceVertical();
		return;
	}

	// Ball collision against player
	if (CheckCollisionCircleRec(ball.position, ball.r, player.box))
	{
		Vector2 ballOldPosition = Utils::getPreviousPosition(ball.position, ball.speed);
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
	else if (CheckCollisionCircleRec(ball.position, ball.r, enemy.box))
	{
		Vector2 ballOldPosition = Utils::getPreviousPosition(ball.position, ball.speed);
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
}

}
