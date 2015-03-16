#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"


class Player :
	public Ship
{
public:
	Player();
	Player(float entityID, float lvl, std::string entityType, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, SDL_Renderer* ren,SoundManager* sm);
	~Player();

	void initFrames();
	void control(const Uint8* currentKeyStates);
	void update(const Uint8* currentKeyStates);
	void draw();
	void addToCamera(Camera* cam);

	// Additional sprites
	Sprite turret;
	//Sprite thrustFront;
	//Sprite thrustBack;

};

#endif