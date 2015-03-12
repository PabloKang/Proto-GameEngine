#include "Star Hornet.h"
#include "Engine.h"

#define RESOURCE_PATH	"Group Game Engine"
#define WIDTH_RATIO		0.75
#define HEIGHT_RATIO	0.75

void fillDisplayMode(SDL_DisplayMode& currDis);


int main(int argc, char **argv)
{
	// Boot up SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	
	// Find current display settings and set window size
	SDL_DisplayMode current;
	fillDisplayMode(current);
	int screenWidth = current.w * WIDTH_RATIO;
	int screenHeight = current.h * HEIGHT_RATIO;

	// Create all game hardware and set engine
	SDL_Window		*window = SDL_CreateWindow("Star Hornet", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	SDL_Renderer	*renderer	= SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Hardware		*hardware	= new Hardware(window, renderer, RESOURCE_PATH, screenWidth, screenHeight);
	Engine			game(hardware);

	// If everything checks out, execute the game
	if ( !game.init() )
		return 1; 
	else
		return game.exec();
}


void fillDisplayMode(SDL_DisplayMode& currDis)
{
	for (int i = 0; i < SDL_GetNumVideoDisplays(); ++i){
		int should_be_zero = SDL_GetCurrentDisplayMode(i, &currDis);

		if (should_be_zero != 0)
			SDL_Log("Could not get display mode for video display #%d: %s", i, SDL_GetError());
		else // On success, print the current display mode.
			SDL_Log("Display #%d: current display mode is %dx%dpx @ %dhz. \n", i, currDis.w, currDis.h, currDis.refresh_rate);
	}
}


void logSDLError(std::ostream &os, const std::string &msg){
	os << msg << " error: " << SDL_GetError() << std::endl;
	std::ostringstream errMsg;
	errMsg << " error: " << SDL_GetError() << std::endl;
	OutputDebugString(errMsg.str().c_str());
}