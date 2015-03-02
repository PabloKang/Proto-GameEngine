#pragma once

#include "Star Hornet.h"


class SpriteManager{
public:
	SpriteManager();
	~SpriteManager();

	Sprite getSprite(std::string type);

	void update_all();


private:
	SDL_Renderer* renderer;
	int numberofsprites;
	std::map<std::string, Sprite>; //types of sprite : Sprite class






};