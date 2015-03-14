#include "Player.h"
#include <math.h>

const int spriteSize = 128;
const float rotationRatio = (70.5 / 128.f);


Player::Player()
{

}


Player::Player(float entID, int lvl, std::string entType, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, SDL_Renderer* ren)
{
	id = entID;
	layer = lvl;
	entityType = entType;
	spritesheet = sprtsht;
	spriteRect = spriteR;
	hitBox = hitBoxR;
	center.x = spriteSize * rotationRatio;
	center.y = spriteSize / 2;

	renderer = ren;

	type = PLAYER;

	initFrames();
	//Sprite(int sID, int lvl, SDL_Rect rect, SDL_Renderer* ren) 
}


Player::~Player()
{
}


void Player::initFrames()
{
	addFrameToSequence("default", makeFrame(spritesheet, 0, 0));	// Default left
}


// Primary Functions

void Player::update(const Uint8* currentKeyStates)
{
	// Get movement input
	control(currentKeyStates);
	move();
}



void Player::control(const Uint8* currentKeyStates)
{

	// Forward momentum
	if (currentKeyStates[SDL_SCANCODE_W] && !currentKeyStates[SDL_SCANCODE_S] && speed < 7){
		speed += 0.2f;
	}
	else if (currentKeyStates[SDL_SCANCODE_S] && !currentKeyStates[SDL_SCANCODE_W] && speed > -3){
		speed -= 0.2f;
	}
	else if (!currentKeyStates[SDL_SCANCODE_W] && !currentKeyStates[SDL_SCANCODE_S]) {
		if (speed > 0)
			speed -= 0.02f;
		else if (speed < 0)
			speed += 0.02f;
	}
	// Rotating
	if (currentKeyStates[SDL_SCANCODE_A]){
		rotate(-2);
	}
	if (currentKeyStates[SDL_SCANCODE_D]){
		rotate(2);
	}
	// Boosting
	if (currentKeyStates[SDL_SCANCODE_Q] && boostTime >= 50 && curBoost > -8){
		curBoost = curBoost - 12;
		boostTime -= 55;
	}
	else if (curBoost < 0) { curBoost = curBoost + 0.25f; }
	if (currentKeyStates[SDL_SCANCODE_E] && boostTime >= 50 && curBoost > -8){
		curBoost = curBoost + 12;
		boostTime -= 55;
	}
	else if (curBoost > 0) { curBoost = curBoost - 0.25f; }
	if (boostTime < maxBoost) boostTime += 0.2f;
}