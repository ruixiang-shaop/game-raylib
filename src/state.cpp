#include "raylib.h"
#include "include/state.hpp"
#include "lib/helpers.hpp"

namespace Game
{

void Ball::update()
{
	position.x += speed.x;
	position.y += speed.y;
}

void Player::update()
{
	box.y += speed;
}

void State::startGame()
{

	roundState = RoundState::Playing;

	// Get restricted random angle and choose start side
	bool startLeft = getRandomNumberBetween(0,99) > 50;
	int randomAngle = getRandomNumberBetween(-BallMaxStartingAngle, BallMaxStartingAngle);
	if (startLeft) randomAngle = 180 - randomAngle;
	auto ballVector = getUnityVector(randomAngle);
	ball.position = BallSpawnPosition;
	ball.speed.x = ballVector.x * BallNormalSpeed;
	ball.speed.y = ballVector.y * BallNormalSpeed;

	player.box = {PlayerSpawnPosition.x, PlayerSpawnPosition.y, Player::DefaultW, Player::DefaultH};
	enemy.box = {EnemySpawnPosition.x, EnemySpawnPosition.y, Player::DefaultW, Player::DefaultH};
}

}
