#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "Star Hornet.h"


class SpriteManager{
public:
	SpriteManager();
	~SpriteManager();

	//returns the number index it is added on map
	void add_texture(std::string name, SDL_Texture* texture);
	SDL_Texture* get_texture(std::string type);
	SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);

private:
	SDL_Renderer* renderer;
	std::map<std::string, SDL_Texture*> textureMap; //types of sprite : Sprite class . /// Map of textures

};

#endif