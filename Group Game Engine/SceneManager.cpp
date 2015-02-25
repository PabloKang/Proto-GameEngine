#include "SceneManager.h"

SceneManager::SceneManager(int windowHeight, int windowLength) :windowHeight(windowHeight), windowLength(windowLength){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			this->scenes[i][j] = Scene();
		}
	}
	mapHeight = 3 * windowHeight;
	mapLength = 3 * windowLength;

}

SceneManager::~SceneManager(){

}

/*void SceneManager::changeSize(){



}*/

Scene SceneManager::getScene(int x, int y){
	return scenes[x][y];
}

Scene SceneManager::getSceneFromCoords(int x, int y){
	return scenes[x / windowLength][y / windowHeight];

}