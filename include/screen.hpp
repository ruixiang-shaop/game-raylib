#pragma once

#include "raylib.h"

namespace Game
{

class Screen
{
public:
	static constexpr int Width = 1368;
	static constexpr int Height = 768;
	static constexpr int ScoreboardWidth = Width;
	static constexpr int ScoreboardHeight = 50;
	static constexpr Vector2 ScoreboardPosition {0, 0};
	static constexpr int GameWidth = Width;
	static constexpr int GameHeight = Height-ScoreboardHeight;
	static constexpr Vector2 GamePosition {0, ScoreboardHeight};
};

}
