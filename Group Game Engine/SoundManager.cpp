#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager()
{
	for (int i = 1; i < 16; i++)
	{
		availableChannels.insert(i);

	}
}

SoundManager::~SoundManager()
{}

void SoundManager::init()
{
	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "SDL_mixer could not initialize!" << std::endl;
	}
}

int SoundManager::getAvailableChannel()
{
	if (availableChannels.size() > 0)
	{
		int returnval = *availableChannels.begin();
		availableChannels.erase(availableChannels.find(returnval));
		usedChannels.insert(returnval);
		return returnval;
	}
	else
	{
		return -1;
	}
}

bool SoundManager::channelInUse(int channel)
{
	if (usedChannels.find(channel) != usedChannels.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}
void SoundManager::freeChannel(int channel)
{
	usedChannels.erase(usedChannels.find(channel));
	availableChannels.insert(channel);
}