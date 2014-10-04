#ifndef H_AUDIODEVICE
#define H_AUDIODEVICE


#include <LibAL/interfaces/IAudioDevice.h>
#include <LibAL/interfaces/IAudioContext.h>
#include <LibAL/interfaces/IMusic.h>
#include <LibAL/interfaces/ISound.h>
#include <LibAL/Listener.h>
#include <al.h>
#include <alc.h>


class AudioDevice : public IAudioDevice
{
	ALCdevice *pDevice;
	IAudioContext *pContext;
	Listener *pListener;
public:
	AudioDevice();
	~AudioDevice();
	virtual bool Ready();
	
	virtual IAudioContext *GetContext();
	virtual IMusic *CreateMusic();
	virtual ISound *CreateSound();
	virtual IListener* GetListener();
	virtual IRecorder *CreateRecorder();
	virtual ISoundBuffer *CreateBuffer();
	ALCdevice *GetDevice()
	{
		return pDevice;
	}
	
	virtual bool IsError();
};

#endif