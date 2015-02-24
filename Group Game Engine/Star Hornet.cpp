#include "Star Hornet.h"


const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 900;


int main(int argc, char **argv)
{
	SDL_Window *window = SDL_CreateWindow("Sprite Demo", 800, 100, SCREEN_WIDTH,
		SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		SDL_Quit();
		return 1;
	}

	if (!game.init()) { return 1; }

	return game.exec();
}