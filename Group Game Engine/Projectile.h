#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"


class Projectile :
	public Entity
{
public:
	// Constructors & Destructors
	Projectile();
	Projectile(float entID, float lvl, std::string type, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, float velocity, double trajectory, SDL_Renderer* ren);
	~Projectile();

	// Functions
	void initFrames();

	// Status Variables
	int lifespan;
};

#endif
