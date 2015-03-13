#ifndef SHIP_H
#define SHIP_H

#include "Entity.h"


class Ship :
	public Entity
{
public:
	Ship();
	Ship(int entityID, int lvl, std::string entityType, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, SDL_Renderer* ren);
	~Ship();

	virtual void control();
	void update();
	void draw();

	int maxBoost;
	int curBoost;
	float boostTime;
};

#endif