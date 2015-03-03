#pragma once

#include "Sprite.h"


class Entity
{
public:
	// Identification
	int id;
	std::string type;

	// Properties
	SDL_Rect rect;
	float speed;
	float angle;
	int curHealth;
	int maxHealth;
	bool visible;

	// Constructor/Destructor
	Entity(int entityID, std::string entityType, int xPos = 0, int yPos = 0, int width = 0, int height = 0);
	~Entity();

	// Primary Functions
	void update();
	void draw(SDL_Renderer& renderer);
	void move(float move_x, float move_y, float angle);

private:
	Sprite sprite;
};

