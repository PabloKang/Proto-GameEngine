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
	Scene scene = Scene();
	sceneManager.addScene(&scene);

	return true;
}


int Engine::exec()
{
	std::string sceneName = "Scene";


	SDL_Event e;
	bool quit = false;
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	// MAIN GAME LOOP -----------------------------------------
	while (sceneName != "NULL"){
		currentScene = sceneManager.getScene(sceneName);
		currentScene->init(&camera);

		sceneName = currentScene->exec();
	}
	cleanup(camera.renderer, camera.window);
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();

	SDL_Quit();

	return 0;
}

