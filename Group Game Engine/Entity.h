#ifndef ENTITY_H
#define ENTITY_H

#include "Star Hornet.h"
#include "Sprite.h"
#include "SoundManager.h"
#include "SoundPlayer.h"

class Entity
{
public:
	// Identification
	int id;
	std::string type;

	// Properties
	SDL_Texture* spritesheet;
	SDL_Rect rect;
	bool alive = true;
	float speed;
	float angle;

	// Constructor/Destructor
	Entity();
	Entity(int entityID, std::string entityType, SDL_Texture* sprtsht, SDL_Renderer* ren, double xPos = 0, double yPos = 0, double width = 0, double height = 0);
	Entity(int entityID, std::string entityType, SDL_Texture* sprtsht, SDL_Renderer* ren, SDL_Rect info);

	~Entity();

	// Primary Functions
	void update();
	bool isAlive();
	bool onScreen();
	bool canCollide();
	void playSound(std::string sound);
	void draw(std::string sequence);
	void move(double move_x, double move_y, double angle);

private:
	Sprite sprite;
	bool collide;
	bool alive = true;
	bool visible;
	SoundPlayer sp;
	SoundManager* sm;
};

#endif