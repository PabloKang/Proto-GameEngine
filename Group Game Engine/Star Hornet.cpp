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
	std::cout << "this should work" << game.sndMgr->getAvailableChannel() << std::endl;
	// If everything checks out, execute the game
	if ( !game.init() )
		return 1; 
	else
		return game.exec();
}


// SDL ERROR FUNCTION
void logSDLError(std::ostream &os, const std::string &msg){
	os << msg << " error: " << SDL_GetError() << std::endl;
	std::ostringstream errMsg;
	errMsg << " error: " << SDL_GetError() << std::endl;
	OutputDebugString(errMsg.str().c_str());
}


std::string exePath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}