#include "Star Hornet.h"
#include "Engine.h"

#define RESOURCE_PATH	"Group Game Engine"
#define SCREEN_WIDTH	1024
#define SCREEN_HEIGHT	900


int main(int argc, char **argv)
{
	SDL_Window		*window		= SDL_CreateWindow("Star Hornet", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer	*renderer	= SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Hardware		hardware	= Hardware(window, renderer, RESOURCE_PATH, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	Engine game(hardware);

	if ( !game.init() )
		return 1; 
	else
		return game.exec();
}


void logSDLError(std::ostream &os, const std::string &msg){
	os << msg << " error: " << SDL_GetError() << std::endl;
	std::ostringstream errMsg;
	errMsg << " error: " << SDL_GetError() << std::endl;
	OutputDebugString(errMsg.str().c_str());
}