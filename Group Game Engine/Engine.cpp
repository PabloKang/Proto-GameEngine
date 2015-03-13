#include "cleanup.h"
#include "Engine.h"
#include "Player.h"

#define RESOURCE_PATH "Group Game Engine"


Engine::Engine()
{
	resPath = RESOURCE_PATH;
	sceneManager = SceneManager(&camera);
}


Engine::~Engine() {}


bool Engine::init()
{

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
		logSDLError(std::cout, "IMG_Init");
		SDL_Quit();
		return false;
	}

	if (camera.window == nullptr){
		logSDLError(std::cout, "CreateWindow");
		SDL_Quit();
		return false;
	}

	if (camera.renderer == nullptr){
		logSDLError(std::cout, "CreateRenderer");
		cleanup(camera.window);
		SDL_Quit();
		return false;
	}

	// TODO - Load Scene into sceneManager here.
	Scene scene = Scene(&camera);

	sceneManager.addScene(&scene);
	currentScene = &scene;

	return true;
}


int Engine::exec()
{
	std::string sceneName = "NULL";


	SDL_Event e;
	bool quit = false;
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


		SDL_RenderClear(camera.renderer);
		SDL_RenderPresent(camera.renderer);
	}
	cleanup(camera.renderer, camera.window);
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();

	SDL_Quit();

	return 0;
}

