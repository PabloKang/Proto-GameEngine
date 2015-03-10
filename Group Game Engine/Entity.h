#ifndef ENTITY_H
#define ENTITY_H

#include "Star Hornet.h"
#include "Sprite.h"
#include "SoundManager.h"
#include "SoundPlayer.h"

class Entity : public Sprite
{
public:
	// Identification
	int			entityID;
	std::string entityType;

	// Properties
	SDL_Rect hitBox;
	float speed;
	bool alive;
	bool visible;
	bool collidable;

	// Constructor/Destructor
	Entity();
	Entity(int id, std::string type, SDL_Texture* sprtsht, Hardware* hrd, SDL_Rect spriteR, SDL_Rect hitBoxR);
	~Entity();

	// Overridden Functions
	virtual void update();
	void draw(std::string sequence);

	// Unique Functions
	void playSound(std::string sound);
	void move(double deltaX, double deltaY, double deltaAngle);

private:
	SDL_Texture* spritesheet;
};

#endif