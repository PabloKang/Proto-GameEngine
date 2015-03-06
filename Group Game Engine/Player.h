#ifndef PLAYER_H
#define PLAYER_H

#include "Star Hornet.h"
#include "Ship.h"

class Player :
	public Ship
{
public:
	Player();
	Player(int entityID, std::string entityType, SDL_Texture* sprtsht, double xPos = 0, double yPos = 0, double width = 0, double height = 0);
	Player(int entityID, std::string entityType, SDL_Texture* sprtsht, SDL_Rect info);
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