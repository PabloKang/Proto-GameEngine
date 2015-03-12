#include "cleanup.h"
#include "Star Hornet.h"
#include "Engine.h"
#include "SceneManager.h"

#define RESOURCE_PATH "Group Game Engine"


Engine::Engine(Hardware hrdware)
{
	hardware = hrdware;
}

Engine::Engine(SDL_Window* win, SDL_Renderer* ren, std::string res, int width, int height)
{
	hardware.window			= win;
	hardware.renderer		= ren;
	hardware.resPath		= res;
	hardware.screenWidth	= width;
	hardware.screenHeight	= height;
}

Engine::~Engine() {}


bool Engine::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::ostringstream debugMsg;
		debugMsg << "SDL_Init Error: " << SDL_GetError() << std::endl;
		OutputDebugString(debugMsg.str().c_str());
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
		logSDLError(std::cout, "IMG_Init");
		SDL_Quit();
		return false;
	}

	if (hardware.window == nullptr){
		logSDLError(std::cout, "CreateWindow");
		SDL_Quit();
		return false;
	}

	if (hardware.renderer == nullptr){
		logSDLError(std::cout, "CreateRenderer");
		cleanup(hardware.window);
		SDL_Quit();
		return false;
	}

	return true;
}


int Engine::exec()
{
	SceneManager sceneManager = SceneManager();
	SDL_Event e;
	bool quit = false;
	std::string spriteFrameSequence = "default";
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	// MAIN GAME LOOP -----------------------------------------
	while (!quit){


		// Poll all events in event queue
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			// Check all one-time keypress events
			if (e.type == SDL_KEYDOWN){
				if (e.key.keysym.sym == SDLK_ESCAPE){
					quit = true;
				}
			}
		}

		//Render the scene
		SDL_RenderClear(hardware.renderer);
		SDL_RenderPresent(hardware.renderer);
	}

	cleanup(hardware.renderer, hardware.window);
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();

	SDL_Quit();

	return 0;
}

