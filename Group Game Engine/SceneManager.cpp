#include "Star Hornet.h"
#include "SceneManager.h"
#include "Scene.h"


SceneManager::SceneManager()
{ 
	hardware = NULL; 
}


SceneManager::SceneManager(Hardware* hrd)
{
	hardware = hrd;
}


SceneManager::~SceneManager(){

}

void SceneManager::addScene(int sceneWidth, int sceneHeight, std::string name)
{
	scenes.insert(std::pair<std::string, Scene>(name, Scene(sceneWidth, sceneHeight, name)));
}

Scene& SceneManager::getScene(std::string name)
{
	return scenes.at(name);
}