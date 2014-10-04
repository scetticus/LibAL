#include <LibAL/Sound.h>

Sound::Sound()
	: AudioPlayer()
{
}

Sound::~Sound()
{
}

void Sound::SetLocation(float x, float y, float z)
{
	alSource3f(GetSourceID(), AL_POSITION, x, y, z);
	
}

void Sound::SetDirection(float x, float y, float z)
{
	
	alSource3f(GetSourceID(), AL_DIRECTION, x, y, z);
}

void Sound::SetVelocity(float x, float y, float z)
{
	alSource3f(GetSourceID(), AL_VELOCITY, x, y, z);
}
