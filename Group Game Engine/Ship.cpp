#include "Star Hornet.h"
#include "Ship.h"
#include "Entity.h"


Ship::Ship()
{
	maxBoost = 100;
	curBoost = 0;
	boostTime = 0;
}


Ship::Ship(float entID, float lvl, std::string entType, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, SDL_Renderer* ren)
{
	id = entID;
	layer = lvl;
	entityType = entType;
	spritesheet = sprtsht;
	spriteRect = spriteR;
	hitBox = hitBoxR;
	center.x = spriteRect.w / 2.0;
	center.y = spriteRect.h / 2.0;

	curHealth = 100;
	maxHealth = 100;
	maxBoost = 100;
	curBoost = 0;
	boostTime = 0;

	renderer = ren;

	type = SHIP;
}


Ship::~Ship()
{
}


// Primary Functions
void Ship::update()
{
	// Get movement input
	control();
}


void Ship::control()
{

}