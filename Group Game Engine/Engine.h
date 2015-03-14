#ifndef ENGINE_H
#define ENGINE_H

#include "Star Hornet.h"
#include "Camera.h"
#include "SceneManager.h"
#include "Scene.h"


// ENGINE CLASS
class Engine
{
public:
	// Engine State Data
	Camera			camera;
	SceneManager	sceneManager;
	Scene*			currentScene;
	std::string		resPath;
	SoundManager*   sndMgr;

	// Engine Constructors
	Engine();
	~Engine();

	// Engine Functions
	bool	init();
	int		exec();
};

#endif