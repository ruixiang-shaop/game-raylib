#include <cmath>
#include <cstdlib>
#include <ctime>
#include "raylib.h"
#include "include/state.hpp"

namespace Game
{

Ball::Ball(Vector2 pos)
{
	position.x = pos.x;
	position.y = pos.y;
}

void Ball::update()
{
	position.x += speed.x;
	position.y += speed.y;
}

Player::Player(Vector2 pos)
{
	position.x = pos.x;
	position.y = pos.y;
}

void Player::update()
{
	position.y += speed;
}

void State::startGame()
{
    std::srand(std::time(nullptr));
	const double pi = std::acos(-1);

	// Calculate random vector for ball with its normal speed
	const double random01 = static_cast<double>(std::rand()) / RAND_MAX;

	const double angle = 2 * pi * random01;

	const double x = std::cos(angle) * BallNormalSpeed;
	const double y = std::sin(angle) * BallNormalSpeed;

	this->ball.speed.x = x;
	this->ball.speed.y = y;
}

}
