#include "include/sounds.hpp"

namespace Game
{

SoundCollection::SoundCollection()
{
	sounds[static_cast<std::uint8_t>(SoundTypes::Hit)] = LoadSound("resources/hit.wav");
}

SoundCollection::~SoundCollection()
{
	for (uint8_t i = 0; i < static_cast<std::uint8_t>(SoundTypes::Max); i++)
	{
		UnloadSound(sounds[i]);
	}
}

/**
 * @warning assumes soundType is always below Max value
*/
void SoundCollection::play(SoundTypes soundType)
{
	PlaySound(sounds[static_cast<uint8_t>(soundType)]);
}

}
