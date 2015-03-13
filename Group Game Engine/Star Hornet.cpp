#include "Star Hornet.h"
#include "Engine.h"


void fillDisplayMode(SDL_DisplayMode& currDis);


int main(int argc, char **argv)
{
	// Boot up SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	
	Engine game = Engine();

	// If everything checks out, execute the game
	if ( !game.init() )
		return 1; 
	else
		return game.exec();
}





//// HARDWARE FUNCTIONS
//Hardware::Hardware(){}
//Hardware::Hardware(SDL_Window* win, SDL_Renderer* ren, std::string res, int width, int height)
//{
//	window = win;
//	renderer = ren;
//	resPath = res;
//	screenWidth = width;
//	screenHeight = height;
//}
//Hardware::~Hardware(){}


// SDL ERROR FUNCTION
void logSDLError(std::ostream &os, const std::string &msg){
	os << msg << " error: " << SDL_GetError() << std::endl;
	std::ostringstream errMsg;
	errMsg << " error: " << SDL_GetError() << std::endl;
	OutputDebugString(errMsg.str().c_str());
}