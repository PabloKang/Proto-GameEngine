#pragma once
#include "Star Hornet.h"


class Ship :
	public Entity
{
public:
	Ship(int entityID, std::string entityType, SDL_Texture* sprtsht, SDL_Renderer* ren, double xPos = 0, double yPos = 0, double width = 0, double height = 0);
	Ship(int entityID, std::string entityType, SDL_Texture* sprtsht, SDL_Renderer* ren, SDL_Rect info);
	~Ship();

	void control();
	void update();
	void draw();

	int maxHealth;
	int curHealth;
	int maxBoost;
	int curBoost;
	float boostTime;

	Sprite hull;
	Sprite turret;
};

