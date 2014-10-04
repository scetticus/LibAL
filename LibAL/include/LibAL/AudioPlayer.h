#ifndef H_AUDIOPLAYER
#define H_AUDIOPLAYER

#include <LibAL/AudioDevice.h>
#include <LibAL/SoundBuffer.h>
#include <LibAL/interfaces/IAudioPlayer.h>

class AudioPlayer : virtual public IAudioPlayer
{
	SoundBuffer *pBuffer;
	ALuint m_source[1];
	int playerState;
	bool bLooping;
public:
	AudioPlayer();
	~AudioPlayer();
	virtual void SetBuffer(ISoundBuffer *buffer);
	virtual ISoundBuffer *GetBuffer();
	virtual bool LoadFromFile(char *szFile);
	

	virtual void SeekOffset(float offset);
	virtual void SeekSecond(float second);
	virtual float GetDuration();
	virtual float GetPosition();

	virtual void Play();
	virtual void Stop();
	virtual void Pause();
	virtual void Rewind();

	virtual bool IsPlaying();
	virtual bool IsPaused();

	virtual void SetLooping(bool state);
	virtual bool IsLooping();

	virtual void SetPitch(float value);
	virtual void SetVolume(float value);

	ALuint GetSourceID()
	{
		return m_source[0];
	}


	float GetBufferLengthInSeconds();
};

#endif