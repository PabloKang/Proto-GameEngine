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


Ship::Ship(int entityID, std::string entityType, SDL_Texture* sprtsht, Hardware* hrd, SDL_Rect spriteR, SDL_Rect hitBoxR)
{
	Entity(entityID, entityType, sprtsht, hrd, spriteR, hitBoxR);

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