#include <LibAL/AudioContext.h>
#include <stdio.h>

AudioContext::AudioContext(ALCdevice* device)
{
	pContext = alcCreateContext(device, NULL);
}

AudioContext::~AudioContext()
{
	alcDestroyContext(pContext);
}

bool AudioContext::Ensure()
{
	if (!pContext)
		return false;
	return alcMakeContextCurrent(pContext);

}
