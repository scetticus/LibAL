#include <LibAL/Music.h>
#include <windows.h>
#include <stdio.h>

int main()
{
	AudioDevice *device = new AudioDevice();

	ISound *wave1 = device->CreateSound();
	ISound *wave2 = device->CreateSound();
	ISound *wave3 = device->CreateSound();

	if (!wave1->LoadFromFile("wave1.wav"))
	{
		printf("Failed to load sound file!");
	}
	if (!wave2->LoadFromFile("wave2.wav"))
	{
		printf("Failed to load sound file!");
	}
	if (!wave3->LoadFromFile("wave3.wav"))
	{
		printf("Failed to load sound file!");
	}


	IListener *listener = device->GetListener();
	wave1->SetLooping(true);
	wave1->SetLocation(-1.0, 1.0, 1);
	wave1->Play();

	wave2->SetLooping(true);
	wave2->SetLocation(0, 1, 1);
	wave2->Play();

	wave3->SetLooping(true);
	wave3->SetLocation(-1, 0, 1);
	wave3->Play();

	float x = 0;
	float y = 0;
	while (true)
	{
		char c = getchar();
		if (c == 'w')
		{
			y += 0.1f;
			printf("%f, %f\n", x, y);
		}
		if (c == 's')
		{
			y -= 0.1f;
			printf("%f, %f\n", x, y);

		}
		if (c == 'a')
		{
			x += 0.1f;
			printf("%f, %f\n", x, y);
		}

		if (c == 'd')
		{
			x -= 0.1f;
			printf("%f, %f\n", x, y);
		}

		listener->SetLocation(x, y, 1);
		device->IsError();
	}
}
