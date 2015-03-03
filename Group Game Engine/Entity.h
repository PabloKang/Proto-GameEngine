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
	//float speed;
	float angle;
	int health;

	// Constructor/Destructor
	Entity(int entityID, std::string entityType, int health, double xPos = 0, double yPos = 0, double width = 0, double height = 0);

	~Entity();

	// Primary Functions
	void update();
	void draw(std::string sequence);
	void move(double move_x, double move_y, double angle);

private:
	Sprite sprite;
};

