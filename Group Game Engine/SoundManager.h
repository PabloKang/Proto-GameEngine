#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "Star Hornet.h"


class SoundManager

{
public:
	SoundManager();
	~SoundManager();
	void init();
	int getAvailableChannel();

	bool channelInUse(int);
	void freeChannel(int);
	void loadSound(std::string soundname, std::string filename);
	void loadMusic(std::string musicname, std::string filename);
	void freeSound(std::string soundname);
	void freeMusic(std::string musicname);
	Mix_Chunk* findSound(std::string soundname);
	Mix_Music* findMusic(std::string musicname);
private:
	std::set<int> availableChannels;
	std::set<int> usedChannels;

	std::map<std::string, Mix_Chunk*> soundMap;
	std::map<std::string, Mix_Music*> musicMap;
};


#endif