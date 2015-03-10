#ifndef PLAYER_H
#define PLAYER_H

#include "Star Hornet.h"
#include "Ship.h"

class Player :
	public Ship
{
public:
	Player();
	Player(int entityID, std::string entityType, SDL_Texture* sprtsht, Hardware* hrd, SDL_Rect spriteR, SDL_Rect hitBoxR);
	~Player();

	void control();
	void update();
	void draw();

	int maxHealth;
	int curHealth;
	int maxBoost;
	int curBoost;
	float boostTime;

	Sprite sprite_hull;
	Sprite sprite_turret;
};

#endif