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
	Mix_Chunk getMix_Chunk(std::string);
	bool channelInUse(int);
	void freeChannel(int);
private:
	std::set<int> availableChannels;
	std::set<int> usedChannels;

	std::map<std::string, Mix_Chunk> fileMap;
};

#endif