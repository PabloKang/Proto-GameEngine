#ifndef SHIP_H
#define SHIP_H

#include "Star Hornet.h"
#include "Entity.h"


class Ship :
	public Entity
{
public:
	Ship();
	Ship(int entityID, std::string entityType, SDL_Texture* sprtsht, Hardware* hrd, SDL_Rect spriteR, SDL_Rect hitBoxR);
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