#pragma once

#include <iostream>
#include <SDL.h>
#include "SDL_ttf.h"


#include "Star Hornet.h"


class Text
{

public:
	Text(SDL_Renderer* renderer, std::string fontName, int fontSize = 10, bool visible = true);
	~Text();

	enum writeOption_t { CONTINUE, NEXT_LINE };

	void write(std::string text);
	void write(std::string text, int x, int y);


private:
	int nextX, nextY;
	int lineStartX;
	std::string fontName;
	SDL_Renderer* renderer;
	TTF_Font* font;
	int fontsize;
	SDL_Texture* texture;
	SDL_Color color;  // always black for now
	bool error;
	bool visible;
	SDL_Texture* renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);
	void yikes(const std::string &message); // for error conditions

};
