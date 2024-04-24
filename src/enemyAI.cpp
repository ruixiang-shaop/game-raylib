#include "include/enemyAI.hpp"

namespace Game
{

void EnemyAI::update(State &state)
{
	const auto ballY = state.ball.position.y;
	const auto enemyY = state.enemy.box.y;
	if (ballY > enemyY)
	{
		state.enemy.speed = Player::DefaultSpeed;
	}
	else if (ballY < enemyY)
	{
		state.enemy.speed = -Player::DefaultSpeed;
	}
	else
	{
		state.enemy.speed = 0;
	}
}

}
