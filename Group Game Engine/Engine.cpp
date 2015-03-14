#include "cleanup.h"
#include "Engine.h"
#include "Player.h"

#define RESOURCE_PATH "Group Game Engine"


Engine::Engine()
{
	resPath = RESOURCE_PATH;
	sndMgr = new SoundManager;
	sceneManager = SceneManager(&camera, sndMgr);

}

Engine::Engine(SoundManager* sm)
{
	resPath = RESOURCE_PATH;
	sndMgr = sm;
	sceneManager = SceneManager(&camera, sndMgr);
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
	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "SDL_mixer could not initialize!" << std::endl;
	}


	// TODO - Load Scene into sceneManager here.
	Scene* scene = new Scene(&camera,sndMgr);
	sceneManager.addScene(scene);

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
		currentScene->init(&camera,sndMgr);

		sceneName = currentScene->exec();
	}
	cleanup(camera.renderer, camera.window);
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();

	SDL_Quit();

	return 0;
}

