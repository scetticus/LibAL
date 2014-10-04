#ifndef H_IAUDIODEVICE
#define H_IAUDIODEVICE

#include <LibAL/interfaces/IMusic.h>
#include <LibAL/interfaces/ISound.h>
#include <LibAL/interfaces/IAudioContext.h>
#include <LibAL/interfaces/IListener.h>
#include <LibAL/interfaces/IRecorder.h>

class IAudioDevice
{
public:
	virtual IAudioContext *GetContext() = 0;
	virtual IMusic *CreateMusic() = 0;
	virtual ISound *CreateSound() = 0;
	virtual IListener* GetListener() = 0;
	virtual IRecorder *CreateRecorder() = 0;
	virtual ISoundBuffer *CreateBuffer() = 0;

	virtual bool Ready() = 0;
	virtual bool IsError() = 0;


};

#endif