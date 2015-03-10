#include "SpriteManager.h"
void logSDLError(std::ostream &os, const std::string &msg);


SpriteManager::SpriteManager()
{

}

SpriteManager::~SpriteManager()
{
}


void SpriteManager::add_texture(std::string name, SDL_Texture* texture)
{
	textureMap.insert(std::pair<std::string,SDL_Texture*>(name, texture));
}

SDL_Texture* SpriteManager::get_texture(std::string type)
{
	return textureMap[type];
}

/**
* Loads an image into a texture on the rendering device
* @param file The image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
SDL_Texture* SpriteManager::loadTexture(const std::string &file, SDL_Renderer *ren)
{
	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
	if (texture == nullptr){
		logSDLError(std::cout, "LoadTexture");
	}
	return texture;
}


/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void logSDLError(std::ostream &os, const std::string &msg)
{
	os << msg << " error: " << SDL_GetError() << std::endl;
	std::ostringstream errMsg;
	errMsg << " error: " << SDL_GetError() << std::endl;
	OutputDebugString(errMsg.str().c_str());
}