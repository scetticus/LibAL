#include <LibAL/Music.h>
#include <windows.h>
#include <stdio.h>

int main()
{
	AudioDevice *device = new AudioDevice();

	IMusic *music = device->CreateMusic();
	if (!music->LoadFromFile("music1.wav"))
	{
		printf("Failed to load sound file!");
	}
	
	IMusic *music2 = device->CreateMusic();
	if (!music2->LoadFromFile("music2.wav"))
	{

	}
	float seconds = 0;
	while (true)
	{
		char c = getchar();

		if (c == 'r')
		{
			music->Rewind();
			printf("Rewind\n");
		}
		if (c == 's')
		{
			music->Stop();
			printf("Stop\n");
		}
		if (c == 'l')
		{
			music->SetLooping(!music->IsLooping());
			printf("SetLooping: %d\n", music->IsLooping());
		}
		if (c == 'p')
		{
			if (!music->IsPlaying())
			{
				music->Play();
				music2->Play();
				printf("Play\n");
			}
			else{
				music->Pause();
				music2->Pause();
				printf("Pause\n");
			}
		}
		device->IsError();
	}
	return 0;
}