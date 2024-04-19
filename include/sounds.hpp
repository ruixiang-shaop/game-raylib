#pragma once

#include <array>
#include <cstdint>
#include "raylib.h"

namespace Game
{

enum SoundTypes : std::uint8_t
{
	Hit,
	Max
};

class SoundCollection
{
public:
	SoundCollection();
	~SoundCollection();

	void play(SoundTypes soundType);

private:
	std::array<Sound, static_cast<std::uint8_t>(SoundTypes::Max)> sounds;
};

}
