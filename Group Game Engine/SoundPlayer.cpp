#include "Star Hornet.h"
#include "SoundPlayer.h"
#include "SoundManager.h"


SoundPlayer::SoundPlayer(SoundManager* sm) :sm(sm)
{
	soundchannel = sm->getAvailableChannel();
	soundvolume = 255;
}

/*
void SoundPlayer::playSound(Mix_Chunk* soundfile, int repeat){
double leftvolume = soundvolume;
double rightvolume = soundvolume;

Mix_SetPanning(soundchannel, leftvolume, rightvolume);
Mix_PlayChannel(soundchannel, soundfile, repeat);
}

void SoundPlayer::playSound(Mix_Chunk* soundfile, float left, float right, int repeat){
double leftvolume = left * soundvolume;
double rightvolume = right * soundvolume;
//std::cout << "currX:" << currX << "currY:" << currY << std::endl;
std::cout << "leftvolume:" << leftvolume << " rightvolume:" << rightvolume << std::endl;
Mix_SetPanning(soundchannel, leftvolume, rightvolume);
Mix_PlayChannel(soundchannel, soundfile, repeat);
}*/
void SoundPlayer::playSound(std::string soundstring, int repeat)
{

	std::cout << "soundplayer soundstring " << soundstring << "\n";
	double leftvolume = soundvolume;
	double rightvolume = soundvolume;

	Mix_SetPanning(soundchannel, leftvolume, rightvolume);
	Mix_Chunk* soundfile = sm->findSound(soundstring);

	Mix_PlayChannel(soundchannel, soundfile, repeat);
}
void SoundPlayer::playSound(std::string soundstring, float left, float right, int repeat)
{
	//std::cout << "soundplayer soundstring " << soundstring << "\n";
	double leftvolume = left * soundvolume;
	double rightvolume = right * soundvolume;
	//std::cout << "currX:" << currX << "currY:" << currY << std::endl;
	//std::cout << "leftvolume:" << leftvolume << " rightvolume:" << rightvolume << std::endl;
	Mix_SetPanning(soundchannel, leftvolume, rightvolume);
	Mix_Chunk* soundfile = sm->findSound(soundstring);
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