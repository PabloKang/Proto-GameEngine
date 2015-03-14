#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Star Hornet.h"
#include "Scene.h"


class SceneManager{
public:
	SceneManager();
	SceneManager(Camera* cam,SoundManager* sm);
	~SceneManager();
	void addScene(Scene* scenee);//need to know the size of the scene unless it's goign to be 1 scene, so the whole window.
	Scene* getScene(std::string name);

private:
	Camera* camera;
	SoundManager* sm;
	std::map<std::string, Scene*> scenes;
};

#endif