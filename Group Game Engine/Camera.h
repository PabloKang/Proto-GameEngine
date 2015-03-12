#ifndef CAMERA_H
#define CAMERA_H

#include "Star Hornet.h"
#include "Entity.h"
#include "Scene.h"


class Camera{
public:

	Camera(int sceneX = 1, int sceneY = 1, int width = 640, int height = 480);
	~Camera();

	void renderEntities();
	//bool isEntityOnScr(Entity entity);
	void changeCoord(int sceneX, int sceneY);
	void setTarget(Sprite target);
	void update();
	void queueSprite(Sprite s);
	Sprite popSprite();
	int queueSize();
	Sprite queuePeek;
private:
	int x, y, width, height;
	bool targetLock;
	Sprite target;
	//Scene currentScene; unnecesary now?
	//std::priority_queue<Sprite, Sprite.layer> queue;
};

#endif