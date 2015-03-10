#include "Star Hornet.h"
#include "SpriteManager.h"

SpriteManager::SpriteManager()
{

}

SpriteManager::~SpriteManager()
{
}


int SpriteManager::add_texture(std::string name, SDL_Texture* texture)
{
	TextureMap[name] = texture;
	return numberofsprites++;
}

SDL_Texture& SpriteManager::get_texture(std::string type)
{
	return *TextureMap[type];
}

