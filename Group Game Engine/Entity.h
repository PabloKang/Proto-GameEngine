#pragma once

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
	float speed;
	float angle;

	// Constructor/Destructor
	Entity();
	Entity(int entityID, std::string entityType, SDL_Texture* sprtsht, SDL_Renderer* ren, bool collide, bool visible, double xPos = 0, double yPos = 0, double width = 0, double height = 0);
	Entity(int entityID, std::string entityType, SDL_Texture* sprtsht, SDL_Renderer* ren, SDL_Rect info);

	~Entity();

	// Primary Functions
	void update();
	void switchVisible();
	void switchCollide();
	void switchAlive();
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

