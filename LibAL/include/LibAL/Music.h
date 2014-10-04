#ifndef H_MUSIC
#define H_MUSIC

#include <LibAL/AudioPlayer.h>

#include <LibAL/interfaces/IMusic.h>

class Music : virtual public AudioPlayer, public IMusic
{

public:
	Music();
	~Music();
};

#endif