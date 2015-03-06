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


Ship::Ship(int entityID, std::string entityType, SDL_Texture* sprtsht, double xPos, double yPos, double width, double height)
{
	Entity(entityID, entityType, sprtsht, xPos, yPos, width, height);

	curHealth = 100;
	maxHealth = 100;

	maxBoost = 100;
	curBoost = 0;
	boostTime = 0;
}


Ship::Ship(int entityID, std::string entityType, SDL_Texture* sprtsht, SDL_Rect info)
{
	Entity(entityID, entityType, sprtsht, info);

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
