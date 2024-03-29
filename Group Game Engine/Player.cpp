#include <math.h>
#include "Player.h"
#include "Camera.h"

const int spriteSize = 128;
const float rotationRatio = (70.5 / 128.f);


Player::Player()
{

}


Player::Player(float entID, float lvl, std::string entType, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, SDL_Renderer* ren, SoundManager* smr) 
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
	for (int i = 0; i <= 9; i++){
		addFrameToSequence("default", makeFrame(spritesheet, i * spriteSize, 0));
	}
}


// Primary Functions

void Player::update(const Uint8* currentKeyStates)
{
	// Update Hull
	control(currentKeyStates);
	move();

	// Update Turret
	int mx, my;
	SDL_GetMouseState(&mx, &my);
	float dx = mx - spriteRect.x;
	float dy = my - spriteRect.y;
	double turretAngle = (atan2(dy, dx)) * 180 / M_PI;
	turret.setPos(spriteRect.x, spriteRect.y);
	turret.angle = turretAngle;
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


void Player::draw()
{
	if (speed < 1.5) { Sprite::draw(8); }
	else if (speed < 2.5) { Sprite::draw(7); }
	else if (speed < 3.5) { Sprite::draw(6); }
	else if (speed < 4.5) { Sprite::draw(5); }
	else if (speed < 5.5) { Sprite::draw(4); }
	else if (speed < 6.5) { Sprite::draw(3); }
	else if (speed < 7.5) { Sprite::draw(2); }

	turret.draw();
}


void Player::addToCamera(Camera* cam)
{
	cam->queueSprite(*this);
	cam->queueSprite(this->turret);
}