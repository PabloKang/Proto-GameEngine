#include "Star Hornet.h"
#include "SoundPlayer.h"
#include "SoundManager.h"

SoundPlayer::SoundPlayer()
{}

SoundPlayer::SoundPlayer(SoundManager* smr) :sm(smr)
{
	soundchannel = sm->getAvailableChannel();
	soundvolume = 255;
}
SoundPlayer::~SoundPlayer()
{
	//sm->freeChannel(soundchannel);
}

void SoundPlayer::playSound(std::string soundstring, int repeat)
{

	//std::cout << "soundplayer soundstring " << soundstring << "\n";
	int leftvolume = soundvolume;
	int rightvolume = soundvolume;

	Mix_SetPanning(soundchannel, leftvolume, rightvolume);
	Mix_Chunk* soundfile = sm->findSound(soundstring);
	if (Mix_Playing(soundchannel))
	{
		Mix_HaltChannel(soundchannel);
		if (Mix_Playing(soundchannel))
		{
			std::cout << "Sound is still playing";
		}
		Mix_PlayChannel(soundchannel, soundfile, repeat);
	}
	else{
		Mix_PlayChannel(soundchannel, soundfile, repeat);
	}
}
void SoundPlayer::playSound(std::string soundstring, float left, float right, int repeat)
{
	//std::cout << "soundplayer soundstring " << soundstring << "\n";
	int leftvolume;
	leftvolume = (int)(left * soundvolume);
	int rightvolume;
	rightvolume = (int)(right * soundvolume);

	Mix_SetPanning(soundchannel, leftvolume, rightvolume);
	Mix_Chunk* soundfile = sm->findSound(soundstring);
	if (Mix_Playing(soundchannel))
	{
		//std::cout << "mix playing" << soundchannel;
		Mix_HaltChannel(soundchannel);
		if (Mix_Playing(soundchannel))
		{
			std::cout << "Sound is still playing";
		}
		Mix_PlayChannel(soundchannel, soundfile, repeat);
	}
	else{
		Mix_PlayChannel(soundchannel, soundfile, repeat);
	}
}


void SoundPlayer::playMusic(std::string musicstring, int repeat)
{
	Mix_Music* musicfile = sm->findMusic(musicstring);
	Mix_PlayMusic(musicfile, repeat);
	
}

void SoundPlayer::changeVolume(int volume)
{
	soundvolume = volume;
}

void SoundPlayer::stopAllSound()
{
	Mix_HaltChannel(soundchannel);
}