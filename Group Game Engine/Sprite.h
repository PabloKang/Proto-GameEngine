#ifndef SPRITE_H
#define SPRITE_H

#include "Star Hornet.h"


class Sprite
{
public:
	Sprite();
	Sprite(Hardware* hrd, SDL_Rect rect, int lvl);
	~Sprite(void);

	// Sprite position
	void setPos(double x, double y);
	void moveX(double delta);
	void moveY(double delta);
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

	int makeFrame(SDL_Texture* texture, int x, int y);
	int addFrameToSequence(std::string seqName, int frameIndex);
	void draw(int frameIndex);
	void draw(std::string sequence);


	// PUBLIC VARIABLES //////////////////////////////////////
	Hardware* hardware;		// Hardware access
	SDL_Rect spriteRect;	// The rectangle bounding the sprite and defining its position
	SDL_Point center;
	double angle;
	double scaleX;
	double scaleY;
	SDL_RendererFlip flip;
	directions facing;
	int layer;

	// PRIVATE VARIABLES ////////////////////////////////////
private:
	struct frame
	{
		SDL_Texture* texture;
		int x;
		int y;
	};
	std::vector<frame> frames;

	std::map<std::string, std::vector<int>> frameSequenceMap;

	int sequenceIndex;		// shared by all sequences; it would be better to have
							// one for each sequence
};

#endif