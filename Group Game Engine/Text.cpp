#include "Star Hornet.h"

#include <iostream>
#include <sstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Text.h"


Text::Text(SDL_Renderer* renderer, std::string fontName, int fontSize, bool visible)
{
	if (TTF_Init() != 0){
		yikes("TTF_Init failure.");
	}
	this->fontName = fontName;
	this->fontsize = fontSize;
	this->renderer = renderer;
	this->color = { 0, 0, 0, 0 };  // always black for now
	this->visible = visible;
}

Text::~Text()
{

}

SDL_Texture* Text::renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer)
{
	//Open the font
	TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (font == nullptr){
		yikes("TTF_OpenFont failure.");
		return nullptr;
	}
	//We need to first render to a surface as that's what TTF_RenderText
	//returns, then load that surface into a texture
	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	if (surf == nullptr){
		TTF_CloseFont(font);
		yikes("TTF_RenderText_Blended failure.");
		return nullptr;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr){
		yikes("CreateTextureFromSurface Failure.");
	}
	//Clean up the surface and font
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}

void Text::write(std::string text)
{
	int pos = 0;
	pos = text.find_last_of("\n");
	if (pos > 0)
{
		text.erase(pos);
		nextY += 12;
	}
	SDL_Texture *image = renderText(text, this->fontName, this->color, this->fontsize, this->renderer);
	if (image == nullptr){
		yikes("Render Image failure");
		TTF_Quit();
	}
	int iW, iH;
	SDL_QueryTexture(image, NULL, NULL, &iW, &iH);

	SDL_Rect dst;
	dst.x = nextX;
	dst.y = nextY;
	dst.w = iW;
	dst.h = iH;
	SDL_RenderCopy(renderer, image, NULL, &dst);
}

void Text::write(std::string text, int x, int y)
{
	SDL_Texture *image = renderText(text, this->fontName, this->color, this->fontsize, this->renderer);
	if (image == nullptr){
		yikes("Render Image failure");
		TTF_Quit();
	}
	int iW, iH;
	SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
	nextX = x;
	nextY = y;

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = iW;
	dst.h = iH;
	SDL_RenderCopy(renderer, image, NULL, &dst);
}
void Text::yikes(const std::string &message) // for error conditions
{
	if (error)
		std::cout << "Message: " << message << " error: " << SDL_GetError() << std::endl;
}



