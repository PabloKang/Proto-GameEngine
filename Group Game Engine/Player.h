#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"


class Player :
	public Ship
{
public:
	Player();
	Player(int entityID, int lvl, std::string entityType, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, SDL_Renderer* ren);
	~Player();

	void initFrames();
	void control(const Uint8* currentKeyStates);
	void update(const Uint8* currentKeyStates);
	void draw();

	Sprite turret;
	//Sprite thrustFront;
	//Sprite thrustBack;
};

#endif