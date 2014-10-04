#include <LibAL/AudioDevice.h>
#include <windows.h>
#include <stdio.h>

int main()
{
	AudioDevice *device = new AudioDevice();
	IRecorder *recorder = device->CreateRecorder();
	recorder->Start();
	ISound *sound = device->CreateSound();
	while (true)
	{
		ISoundBuffer *buffer = recorder->CopyToBuffer();

		if (buffer)
		{
			sound->Rewind();

			sound->SetBuffer(buffer);
			delete buffer;
		}
		sound->Play();
		Sleep(100);
	}
	recorder->Stop();
}

