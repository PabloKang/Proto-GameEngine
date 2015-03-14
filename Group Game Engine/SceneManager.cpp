#include "SceneManager.h"


SceneManager::SceneManager()
{ 
	camera = NULL; 
}


SceneManager::SceneManager(Camera* cam, SoundManager* sm) : camera(cam), sm(sm)
{

}


SceneManager::~SceneManager(){

}

void SceneManager::addScene(Scene* scene)
{
	scenes.insert(std::pair<std::string, Scene*>(scene->sceneName, scene));
}

Scene* SceneManager::getScene(std::string name)
{
	return scenes.at(name);
}