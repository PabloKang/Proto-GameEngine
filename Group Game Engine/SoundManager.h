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
	Mix_Chunk* findSound(std::string soundname);
private:
	std::set<int> availableChannels;
	std::set<int> usedChannels;

	std::map<std::string, Mix_Chunk*> fileMap;
};


#endif