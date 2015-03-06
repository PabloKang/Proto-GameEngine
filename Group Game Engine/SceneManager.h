#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Star Hornet.h"
#include "Scene.h"

class SceneManager{
public:
	SceneManager(int windowHeight, int windowLength);
	~SceneManager();

	//void changeSize();
	Scene getScene(int x, int y);
	Scene getSceneFromCoords(int x, int y);

private:
	int numOfScenes;
	int windowHeight;
	int windowLength;
	int mapHeight; //windowHeight * 3
	int mapLength; //windowLength * 3
	Scene scenes[3][3];
};

#endif