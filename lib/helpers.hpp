#pragma once

#include <cmath>
#include <cstdlib>
#include <ctime>
#include "raylib.h"

Vector2 getRandomUnityVector()
{
    std::srand(std::time(nullptr));

	const double pi = std::acos(-1);
	const double random01 = static_cast<double>(std::rand()) / RAND_MAX;
	const double angle = 2 * pi * random01;

	const float x = std::cos(angle);
	const float y = std::sin(angle);

	return Vector2{x, y};
}