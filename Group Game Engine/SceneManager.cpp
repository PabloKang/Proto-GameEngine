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

/*void SceneManager::changeSize(){



}*/

Scene& SceneManager::getScene(std::string name)
{
	return scenes.at(name);
}