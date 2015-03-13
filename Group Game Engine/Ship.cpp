#include "Star Hornet.h"
#include "Ship.h"
#include "Entity.h"


Ship::Ship()
{
	Entity();

	curHealth = 100;
	maxHealth = 100;

	maxBoost = 100;
	curBoost = 0;
	boostTime = 0;
}


Ship::Ship(int entityID, int lvl, std::string entityType, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, SDL_Renderer* ren)
{
	Entity(entityID, lvl, entityType, sprtsht, spriteR, hitBoxR, ren);

	curHealth = 100;
	maxHealth = 100;

	maxBoost = 100;
	curBoost = 0;
	boostTime = 0;
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