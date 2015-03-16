#include "Projectile.h"


Projectile::Projectile()
{
}


Projectile::Projectile(float entID, float lvl, std::string type, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, float velocity, double trajectory, SDL_Renderer* ren)
{
	curHealth = 20;
	maxHealth = 20;

	id = entID;
	layer = lvl;
	entityType = type;
	spritesheet = sprtsht;
	spriteRect = spriteR;
	hitBox = hitBoxR;
	center.x = spriteR.w / 2;
	center.y = spriteR.h / 2;
	speed = velocity;
	angle = trajectory;

	renderer = ren;

	initFrames();
}


Projectile::~Projectile()
{
}


void Projectile::initFrames()
{
	addFrameToSequence("default", makeFrame(spritesheet, 0, 0));	// Default
}