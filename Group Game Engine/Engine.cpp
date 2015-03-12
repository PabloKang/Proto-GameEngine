#include "cleanup.h"
#include "Star Hornet.h"
#include "Engine.h"
#include "SceneManager.h"

#define RESOURCE_PATH "Group Game Engine"


Engine::Engine(Hardware* hrdware)
{
	hardware = *hrdware;
	sceneManager = SceneManager(&hardware);
}

Engine::Engine(std::string res, int width, int height)
{
	// TODO - Find out why window disappears unless initialized here instead of in Star Hornet.cpp
	hardware.window = SDL_CreateWindow("Star Hornet", 0, 0, 1024, 900, SDL_WINDOW_SHOWN);
	hardware.renderer = SDL_CreateRenderer(hardware.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	hardware.resPath = res;
	hardware.screenWidth = width;
	hardware.screenHeight = height;
	sceneManager = SceneManager(&hardware);
}

Engine::Engine(SDL_Window* win, SDL_Renderer* ren, std::string res, int width, int height)
{
	hardware.window			= win;
	hardware.renderer		= ren;
	hardware.resPath		= res;
	hardware.screenWidth	= width;
	hardware.screenHeight	= height;
	sceneManager = SceneManager(&hardware);
}

Engine::~Engine() {}


bool Engine::init()
{

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

	// TODO - Load protoScene into sceneManager here.

	return true;
}


int Engine::exec()
{
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
				break;
			}
			// Check all one-time keypress events
			if (e.type == SDL_KEYDOWN){
				if (e.key.keysym.sym == SDLK_ESCAPE){
					quit = true;
				}
			}
		}

		//Render the scene
		SDL_RenderClear(hardware.getRenderer());
		SDL_RenderPresent(hardware.getRenderer());
	}

	cleanup(hardware.renderer, hardware.window);
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();

	SDL_Quit();

	return 0;
}

