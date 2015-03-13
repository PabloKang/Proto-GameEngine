#ifndef SPRITE_H
#define SPRITE_H

#include "Star Hornet.h"
class Camera;


class Sprite
{
public:
	Sprite();
	Sprite(int sID, int lvl, SDL_Rect rect, Camera* cam);
	~Sprite();

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
	virtual void update();
	void draw(int frameIndex);
	void draw(std::string sequence);
	void addToCamera();


	// PUBLIC VARIABLES //////////////////////////////////////
	Camera*		camera;		// Camera access
	int			id;
	SDL_Rect	spriteRect;	// The rectangle bounding the sprite and defining its position
	SDL_Point	center;
	int			layer;
	double		angle;
	double		scaleX;
	double		scaleY;
	directions	facing;
	SDL_RendererFlip flip;

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