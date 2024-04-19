#pragma once

#include "raylib.h"
#include "screen.hpp"

namespace Game
{

struct Ball
{
	Ball(Vector2 pos);
	void update();

	Vector2 position;
	Vector2 speed {0, 0};
	const unsigned int r = 10;
};

struct Player
{
	Player(Vector2 pos);
	void update();

	Vector2 position;		// Position is top left corner of the rectangle 
	float speed {0};
	int w {DefaultW};
	int h {DefaultH};
	static constexpr int DefaultW = 40;
	static constexpr int DefaultH = 100;
};

class State
{
private:
	const float OffsetX = 5.0;
	const Vector2 ballSpawn {Screen::Width/2, Screen::Height/2};
	const float BallNormalSpeed = 8.0;
	const Vector2 playerSpawn {OffsetX, Screen::Height/2-Player::DefaultH/2};
	const Vector2 enemySpawn {Screen::Width - Player::DefaultW - OffsetX, Screen::Height/2-Player::DefaultH/2};
public:
	void startGame();

	Ball ball {ballSpawn};
	Player player {playerSpawn};
	Player enemy {enemySpawn};
	unsigned int playerPoints = 0U;
	unsigned int enemyPoints = 0U;
};

}