#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include "Star Hornet.h"
#include "SoundManager.h"


class SoundPlayer
{
public:
	SoundPlayer();
	SoundPlayer(SoundManager* sm);
	~SoundPlayer();


	// playSound takes a soundfile string as argument
	// the integer repeat is the number of times the sound file will play
	// a negative value will for loop infinitely
	void playSound(std::string soundstring, int repeat);
	
	// float left and right are the percent (from 0 to 1) of the amount of 
	// panning the sound will have, 0 for none, 1 for full volume
	// ie for a sound to be all the way to the right it would be left = 0 right = 1
	void playSound(std::string soundstring, float left, float right, int repeat);

	// change the playback volume for the sprite.  this integer represents a scale from 1 to 100, anything over 100 counts as 100.
	void changeVolume(int volume);

	//This will stop all sounds
	void stopAllSound();

private:
	int soundchannel;
	int soundvolume;
	SoundManager* sm;

};
#endif