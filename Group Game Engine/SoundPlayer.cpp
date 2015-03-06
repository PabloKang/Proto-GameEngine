#include "Star Hornet.h"
#include "SoundPlayer.h"


void SoundPlayer::playSound(Mix_Chunk* soundfile, int repeat){
	double leftvolume = soundvolume;
	double rightvolume = soundvolume;
	//double leftvolume = ((640.0 - currX) / 640.0) * soundvolume;
	//double rightvolume = ((currX) / 640.0) * soundvolume;
	//std::cout << "currX:" << currX << "currY:" << currY << std::endl;
	//std::cout << "leftvolume:" << leftvolume << " rightvolume:" << rightvolume << std::endl;
	Mix_SetPanning(soundchannel, leftvolume, rightvolume);
	Mix_PlayChannel(soundchannel, soundfile, repeat);
}

void SoundPlayer::changeVolume(int volume)
{
	soundvolume = volume;
}

void SoundPlayer::stopAllSound()
{
	Mix_HaltChannel(soundchannel);
}