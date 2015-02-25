#include "Star Hornet.h"


const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 900;


int main(int argc, char **argv)
{
	SDL_Window *window = SDL_CreateWindow("Sprite Demo", 800, 100, SCREEN_WIDTH,
		SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	Engine game(window, renderer);

	if (!game.init()) { return 1; }
	return game.exec();
}