#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"


class Player :
	public Ship
{
public:
	Player();
	Player(int entityID, int lvl, std::string entityType, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, Camera* cam);
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