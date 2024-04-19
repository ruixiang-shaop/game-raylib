#pragma once

#include "state.hpp"

namespace Game
{

class Inputs
{
public:
	static bool isPlayerUp();
	static bool isPlayerDown();
	static void handleInput(State &state);
};

}
