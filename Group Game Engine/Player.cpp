#include "Player.h"


Player::Player()
{
	Ship();
}


Player::Player(int entityID, int lvl, std::string entityType, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, SDL_Renderer* ren)
{
	Ship(entityID, lvl, entityType, sprtsht, spriteR, hitBoxR, ren);
	initFrames();
}


Player::~Player()
{
}


void Player::initFrames()
{
	addFrameToSequence("default", makeFrame(spritesheet, 0, 0));	// Default left
}


// Primary Functions
void Player::update()
{
	// Get movement input
	control();
}



void Player::control()
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	// Forward momentum
	if (currentKeyStates[SDL_SCANCODE_W]){
		speed += 5;
	}
	if (currentKeyStates[SDL_SCANCODE_S]){
		speed -= 5;
	}
	// Rotating
	if (currentKeyStates[SDL_SCANCODE_A]){
		angle++;
	}
	if (currentKeyStates[SDL_SCANCODE_D]){
		angle--;
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