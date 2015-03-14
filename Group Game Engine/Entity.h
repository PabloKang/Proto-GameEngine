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
	Entity(float entID, int lvl, std::string type, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, SDL_Renderer* ren);
	~Entity();

	void move();
	void draw(std::string sequence);
	

	// Virtual Functions
	virtual void initFrames();

	SDL_Texture* spritesheet;
};

#endif