#ifndef H_AUDIOCONTEXT
#define H_AUIDOCONTEXT

#include <LibAL/interfaces/IAudioContext.h>
#include <al.h>
#include <alc.h>

class AudioContext : public IAudioContext
{
	ALCcontext *pContext;
public:
	AudioContext(ALCdevice* device);
	~AudioContext();
	virtual bool Ensure();
};

#endif