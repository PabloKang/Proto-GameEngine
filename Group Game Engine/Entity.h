#ifndef ENTITY_H
#define ENTITY_H

#include "Sprite.h"
#include "SoundManager.h"
#include "SoundPlayer.h"


class Entity 
	: public Sprite
{
public:
	// Identification
	std::string entityType;

	// Properties
	SDL_Rect hitBox;
	float	speed;
	int		maxHealth;
	int		curHealth;
	bool	alive;
	bool	visible;
	bool	collidable;

	// Constructor/Destructor
	Entity();
	Entity(int entID, int lvl, std::string type, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, SDL_Renderer* ren);
	~Entity();

	// Overridden Functions
	void draw(std::string sequence);

	// Unique Functions
	void playSound(std::string sound);
	void move(double deltaX, double deltaY, double deltaAngle);

	// Virtual Functions
	virtual void initFrames();

	// Gets and Sets


	SDL_Texture* spritesheet;
};

#endif