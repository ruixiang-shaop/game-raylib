#include "raylib.h"
#include "include/state.hpp"
#include "lib/utils.hpp"

namespace Game
{

void Ball::update()
{
	position.x += speed.x;
	position.y += speed.y;
	this->bounced = false;
}

void Ball::bounceHorizontal()
{
	this->speed.x *= -1;
	this->bounced = true;
}

void Ball::bounceVertical()
{
	this->speed.y *= -1;
	this->bounced = true;
}

void Player::update()
{
	box.y += speed;

	if (box.y < Game::Screen::GamePosition.y)
	{
		box.y = Game::Screen::GamePosition.y;
	}
	const auto furthestDownY = Game::Screen::GamePosition.y + Game::Screen::GameHeight - box.height;
	if (box.y > furthestDownY)
	{
		box.y = furthestDownY;
	}
}

void State::startGame()
{

	roundState = RoundState::Playing;

	// Get restricted random angle and choose start side
	bool startLeft = Utils::getRandomNumberBetween(0,99) > 50;
	int randomAngle = Utils::getRandomNumberBetween(-BallMaxStartingAngle, BallMaxStartingAngle);
	if (startLeft) randomAngle = 180 - randomAngle;
	auto ballVector = Utils::getUnityVector(randomAngle);
	ball.position = BallSpawnPosition;
	ball.speed.x = ballVector.x * BallNormalSpeed;
	ball.speed.y = ballVector.y * BallNormalSpeed;

	player.box = {PlayerSpawnPosition.x, PlayerSpawnPosition.y, Player::DefaultW, Player::DefaultH};
	enemy.box = {EnemySpawnPosition.x, EnemySpawnPosition.y, Player::DefaultW, Player::DefaultH};
}

}
