#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Star Hornet.h"
#include "Scene.h"

class SceneManager{
public:
	SceneManager();
	SceneManager(Hardware* hrdwr);
	~SceneManager();

	void addScene(Scene* scenee);//need to know the size of the scene unless it's goign to be 1 scene, so the whole window.
	Scene* getScene(std::string name);

private:
	Hardware* hardware;
	std::map<std::string, Scene*> scenes;
};

#endif