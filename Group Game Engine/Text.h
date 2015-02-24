#pragma once
#include <iostream>
#include <SDL.h>
#include "SDL_ttf.h"


class Text
{
public:
	Text(SDL_Renderer* renderer, std::string fontName, int fontSize = 10, bool visible = true);
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

