#pragma once

#include "raylib.h"
#include "screen.hpp"
#include <cstdint>

namespace Game
{

struct Ball
{
	void update();

	void bounceHorizontal();
	void bounceVertical();

	Vector2 position;
	Vector2 speed {0, 0};
	bool bounced = false;
	int r = DefaultRadius;
	static constexpr int DefaultRadius = 10;
};

struct Player
{
	void update();

	Rectangle box;		// Coords is top left corner of the rectangle 
	float speed {0};
	static constexpr int DefaultW = 20;
	static constexpr int DefaultH = 150;
	static constexpr int DefaultSpeed = 5;
};

enum RoundState : std::uint8_t
{
	Playing,
	Win,
	Lose
};


class State
{
private:
	const float OffsetX = 5.0;
	const Vector2 BallSpawnPosition {Screen::GameWidth/2, Screen::GamePosition.y + Screen::GameHeight/2};
	const int BallMaxStartingAngle = 60;
	const float BallNormalSpeed = 8.0;
	const Vector2 PlayerSpawnPosition {OffsetX, Screen::GamePosition.y + Screen::GameHeight/2-Player::DefaultH/2};
	const Vector2 EnemySpawnPosition {Screen::GameWidth - Player::DefaultW - OffsetX,
									Screen::GamePosition.y + Screen::GameHeight/2-Player::DefaultH/2};
public:
	void startGame();

	Ball ball;
	Player player;
	Player enemy;
	RoundState roundState = RoundState::Playing;
	unsigned int playerPoints = 0U;
	unsigned int enemyPoints = 0U;
};

}
