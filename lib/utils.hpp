#pragma once

#include <cmath>
#include <cstdlib>
#include "raylib.h"

enum Side
{
	Top,
	Bottom,
	Left,
	Right
};

class Utils
{
public:

/**
 * Random value between [min,max] both included
*/
static int getRandomNumberBetween(int min, int max)
{
	int range = max - min;
	const double random01 = static_cast<double>(std::rand()) / RAND_MAX;

	return min + static_cast<int>(random01 * range);
}

/**
 * @warning degrees [0-360], NOT radians
*/
static Vector2 getUnityVector(int degrees)
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

static Vector2 getNextPosition(Vector2 oldPosition, Vector2 speed)
{
	return {oldPosition.x + speed.x, oldPosition.y + speed.y};
}

static bool isPointOnUpperSideOfLine(Vector2 l1, Vector2 l2, Vector2 p)
{
    return ((l2.x-l1.x) * (p.y-l1.y) - (l2.y-l1.y) * (p.x-l1.x)) > 0;
}

static Side getCollisionSideRectCircle(Rectangle box, Vector2 circleCenter)
{
	/**
	 * 	A		B
	 * 	_________
	 * 	|		|
	 * 	|_______|
	 * 	
	 * 	C		D
	 * 
	*/

	Vector2 pointA {box.x, box.y};
	Vector2 pointB {box.x+box.width, box.y};
	Vector2 pointC {box.x, box.y+box.height};
	Vector2 pointD {box.x+box.width, box.y+box.height};

    bool isAboveAD = isPointOnUpperSideOfLine(pointD, pointA, circleCenter);
    bool isAboveCB = isPointOnUpperSideOfLine(pointB, pointC, circleCenter);

    if (isAboveAD)
    {
        if (isAboveCB)
        {
            //top edge has intersected
            return Side::Top;
        }
        else
        {
            //right edge intersected
            return Side::Right;
        }
    }
    else
    {
        if (isAboveCB)
        {
            //left edge has intersected
            return Side::Left;
        }
        else
        {
            //bottom edge intersected
            return Side::Bottom;
        }
    }
} 

};
