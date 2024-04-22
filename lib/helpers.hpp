#pragma once

#include <cmath>
#include <cstdlib>
#include "raylib.h"

/**
 * Random value between [min,max] both included
*/
int getRandomNumberBetween(int min, int max)
{
	int range = max - min;
	const double random01 = static_cast<double>(std::rand()) / RAND_MAX;

	return min + static_cast<int>(random01 * range);
}


/**
 * @warning degrees [0-360], NOT radians
*/
Vector2 getUnityVector(int degrees)
{

	// Get min and max values
	// radians * pi = degrees/360, also take int account that 
	// radians * pi + 2 * pi * k = radians * pi, so negative values are also ok

	const double pi = std::acos(-1);
	const double angle = (degrees/360.0) * 2 * pi;

	const float x = std::cos(angle);
	const float y = std::sin(angle);

	return Vector2{x, y};
}