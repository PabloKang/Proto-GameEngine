#pragma once
#include "Sprite.h"


class Entity
{
public:
	Entity();
	~Entity();

	// Primary Functions
	void update();
	void draw(SDL_Renderer& renderer);
	void moveSprite(Sprite& sprite, float move_x, float move_y, float angle);
};

