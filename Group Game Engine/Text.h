#pragma once

#include "Star Hornet.h"


class Text
{
public:
	Text();
	~Text();

private:
	int nextX, nextY;
	int lineStartX;
	std::string fontName;
	SDL_Renderer* renderer;
	TTF_Font* font;
	SDL_Texture* texture;
	SDL_Color color;
	bool error;
	bool visible;
	bool newLine = true;

	void logSDLError(std::string message); // for error conditions
};

