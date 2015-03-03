#pragma once
#include "SDL_mixer.h"
class SoundPlayer
{
public:
	SoundPlayer();
	~SoundPlayer();


	// playSound takes a soundfile string as argument
	// the integer repeat is the number of times the sound file will play
	// a negative value will for loop infinitely
	void playSound(Mix_Chunk* soundfile, int repeat);

	// change the playback volume for the sprite.  this integer represents a scale from 1 to 100, anything over 100 counts as 100.
	void changeVolume(int volume);

	//This will stop all sounds
	void stopAllSound();



private:
	int soundchannel;
	int soundvolume;


};