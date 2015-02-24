#pragma once

#include "Star Hornet.h"


class Resources
{
public:
	Resources();
	~Resources();

	// TODO - Functions for loading, manipulating, accessing and deleting textures, sound files and fonts
	SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);

private:
	// TODO - Maps for Fonts and Sound files
	std::map<std::string, SDL_Texture> textureMap;


};

