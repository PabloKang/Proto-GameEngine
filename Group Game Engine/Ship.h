#ifndef SHIP_H
#define SHIP_H

#include "Star Hornet.h"
#include "Entity.h"
#include "Sprite.h"

class Ship :
	public Entity
{
public:
	Ship();
	Ship(int entityID, std::string entityType, SDL_Texture* sprtsht, double xPos = 0, double yPos = 0, double width = 0, double height = 0);
	Ship(int entityID, std::string entityType, SDL_Texture* sprtsht, SDL_Rect info);
	~Ship();

	virtual void control();
	void update();
	void draw();

	int maxHealth;
	int curHealth;
	int maxBoost;
	int curBoost;
	float boostTime;

	Sprite sprite;
};

#endif