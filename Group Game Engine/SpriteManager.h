#pragma once

#include "Star Hornet.h"


class SpriteManager{
public:
	SpriteManager();
	~SpriteManager();

	//returns the number index it is added on map
	int add_texture(std::string name, SDL_Texture* texture);

	SDL_Texture* get_texture(std::string type);




private:
	SDL_Renderer* renderer;
	int numberofsprites;
	std::map<std::string, SDL_Texture*> TextureMap; //types of sprite : Sprite class . /// Map of textures






};