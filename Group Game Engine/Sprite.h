#pragma once

#include "SDL.h"
#include <SDL_mixer.h>
#include <vector>
#include <map>


enum directions { LEFT, RIGHT, UP, DOWN };


class Sprite
{
public:
	Sprite(int width, int height, SDL_Renderer* ren);
	~Sprite(void);

	// Sprite position
	void setPos(int x, int y);
	void movex(int delta);
	void movey(int delta);
	int getX();
	int getY();
	// Sprite rotation ///////////////////////////////////////
	void autoCenter();
	void setCenter(SDL_Point centerPoint);
	SDL_Point getCenter();
	void rotate(double deltaAngle);
	void setAngle(double specificAngle);
	double getAngle();
	// Sprite scaling ////////////////////////////////////////
	void changeScale(double deltaScaleX, double deltaScaleY);
	void setScale(double specificScaleX, double specificScaleY);
	double getScaleX();
	double getScaleY();
	// Sprite flipping ///////////////////////////////////////
	void setFlip(SDL_RendererFlip flipType = SDL_FLIP_NONE);
	SDL_RendererFlip getFlip();

	// makeFrame returns the unique index of the frame
	int makeFrame(SDL_Texture* texture, int x, int y);

	// addFrameToSequence returns the number of frames in the sequence after the add
	int addFrameToSequence(std::string seqName, int frameIndex);

	// show(int) renders the frame with the specified frameIndex
	void show(int frameIndex);

	// show(string) cycles through all frames in the specified sequence, one per call
	void show(std::string sequence);

	// addFrameToSequence returns the number of frames in the sequence after the add
	void addSoundToSequence(std::string seqName, Mix_Chunk soundChunk);

	// play(string) plays the sound named by the parameter string
	void play(std::string sound);


// The private part of the class is given as a hint or suggestion.
// In homework 3 you can make any modifications you want to the class's innards.
private:
	SDL_Renderer* renderer;
	SDL_Rect spriteRect;	// The rectangle bounding the sprite and defining its position
	SDL_Point center;
	double angle;
	double scaleX;
	double scaleY;
	SDL_RendererFlip flip;
	directions facing;

	struct frame
	{
		SDL_Texture* texture;
		int x;
		int y;
	};
	std::vector<frame> frames;

	std::map<std::string, std::vector<int>> frameSequenceMap;
	std::map<std::string, Mix_Chunk> soundSequenceMap;
	int sequenceIndex;		// shared by all sequences; it would be better to have
							// one for each sequence


};