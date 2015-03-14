#include "Star Hornet.h"
#include "SoundManager.h"
#include <iostream>
SoundManager::SoundManager()
{
	for (int i = 1; i < 64; i++)
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

void SoundManager::loadSound(std::string soundname, std::string filename)
{
	Mix_Chunk* soundchunk = Mix_LoadWAV(filename.c_str());
	if (soundchunk == NULL)
	{
		printf("Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
	else
	{
		soundMap.emplace(std::pair<std::string, Mix_Chunk*>(soundname, soundchunk));
	}
}

void SoundManager::loadMusic(std::string musicname, std::string filename)
{
	Mix_Music* musicchunk = Mix_LoadMUS(filename.c_str());
	if (musicchunk == NULL)
	{
		printf("Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
	else
	{
		musicMap.emplace(std::pair<std::string, Mix_Music*>(musicname, musicchunk));
	}
}


Mix_Chunk* SoundManager::findSound(std::string soundname)
{
	std::cout << "fileMap size " << soundMap.size() << std::endl;
	//std::cout << "soundmanager soundstring " << soundname << "\n";
	if (soundMap.find(soundname) != soundMap.end())
	{
		return soundMap.find(soundname)->second;
	}
	else{
		std::cout << "mymap contains:\n";
		for (std::map<std::string, Mix_Chunk*>::iterator it = soundMap.begin(); it != soundMap.end(); ++it)
		{
			std::cout << it->first << " => " << it->second << '\n';

			printf("Failed to find sound effect!  %s\n", soundname.c_str());
			//std::cout << "soundmanager error soundstring " << soundname << "\n";
		}

	}
	return nullptr;
}

Mix_Music* SoundManager::findMusic(std::string musicname)
{


	std::cout << "fileMap size " << musicMap.size() << std::endl;

	if (musicMap.find(musicname) != musicMap.end())
	{
		return musicMap.find(musicname)->second;
	}
	else{
		std::cout << "mymap contains:\n";
		for (std::map<std::string, Mix_Music*>::iterator it = musicMap.begin(); it != musicMap.end(); ++it)
		{
			std::cout << it->first << " => " << it->second << '\n';

			printf("Failed to find music!  %s\n", musicname.c_str());

		}

	}
	return nullptr;
}


void SoundManager::freeSound(std::string soundname)
{
	Mix_FreeChunk(findSound(soundname));
	soundMap.erase(soundname);
}

void SoundManager::freeMusic(std::string musicname)
{
	Mix_FreeMusic(findMusic(musicname));
	musicMap.erase(musicname);

}


