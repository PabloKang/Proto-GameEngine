#ifndef ENGINE_H
#define ENGINE_H

#include "Star Hornet.h"
#include "SceneManager.h"
#include "Scene.h"


// ENGINE CLASS
class Engine
{
public:
	// Engine State Data
	Hardware*		hardware;
	SceneManager	sceneManager;
	Scene			currentScene;

	// Engine Constructors
	Engine(Hardware* hrd);
	Engine(SDL_Window* win, SDL_Renderer *ren, std::string res, int width, int height);
	~Engine();

	// Engine Functions
	bool	init();
	int		exec();
};

#endif