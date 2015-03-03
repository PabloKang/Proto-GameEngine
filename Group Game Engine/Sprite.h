#pragma once

#include "Star Hornet.h"


class Sprite
{
public:
	Sprite();
	Sprite(SDL_Rect rect, SDL_Renderer* renderer);
	~Sprite(void);

	// Sprite position
	void setPos(double x, double y);
	void movex(double delta);
	void movey(double delta);
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
		double x;
		double y;
	};
	std::vector<frame> frames;

	std::map<std::string, std::vector<int>> frameSequenceMap;

	int sequenceIndex;		// shared by all sequences; it would be better to have
							// one for each sequence
};