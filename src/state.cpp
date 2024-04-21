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

	auto ballVector = getRandomUnityVector();
	ball.position = BallSpawnPosition;
	ball.speed.x = ballVector.x * BallNormalSpeed;
	ball.speed.y = ballVector.y * BallNormalSpeed;

	player.box = {PlayerSpawnPosition.x, PlayerSpawnPosition.y, Player::DefaultW, Player::DefaultH};
	enemy.box = {EnemySpawnPosition.x, EnemySpawnPosition.y, Player::DefaultW, Player::DefaultH};
}

}
