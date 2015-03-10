#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Star Hornet.h"
#include "Scene.h"

class SceneManager{
public:
	SceneManager();
	SceneManager(Hardware* hrdwr);
	~SceneManager();

	Scene& getScene(std::string name);

private:
	Hardware* hardware;
	std::map<std::string, Scene> scenes;
};

#endif