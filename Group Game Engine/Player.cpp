#include "Star Hornet.h"
#include "Player.h"



Player::Player()
{
	Entity();
	curHealth = 100;
	maxHealth = 100;

	maxBoost = 100;
	curBoost = 0;
	boostTime = 0;
}


Player::Player(int entityID, std::string entityType, SDL_Texture* sprtsht, double xPos, double yPos, double width, double height)
{
	Entity(entityID, entityType, sprtsht, xPos, yPos, width, height);

	curHealth = 100;
	maxHealth = 100;

	maxBoost = 100;
	curBoost = 0;
	boostTime = 0;
}


Player::Player(int entityID, std::string entityType, SDL_Texture* sprtsht, SDL_Rect info)
{
	Entity(entityID, entityType, sprtsht, info);

	curHealth = 100;
	maxHealth = 100;

	maxBoost = 100;
	curBoost = 0;
	boostTime = 0;
}


Player::~Player()
{
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