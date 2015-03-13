#ifndef CAMERA_H
#define CAMERA_H

#include "Star Hornet.h"
#include "Sprite.h"


class Camera{
public:

	Camera();
	~Camera();

	bool init();
	bool init(SDL_Window* win, SDL_Renderer* ren, int w = 640, int h = 480);
	void update();
	void draw();

	void moveCameraRight(int deltaX);
	void moveCameraLeft(int deltaX);
	void moveCameraUp(int deltaY);
	void moveCameraDown(int deltaY);
	void setCameraPos(int x, int y);

	void setTarget(Sprite* target);
	bool isInDisplay(Sprite s);
	void queueSprite(Sprite s);
	Sprite popSprite();

	SDL_Window* window;
	SDL_Renderer* renderer;
	std::priority_queue<Sprite, int> drawQueue;

private:
	void fillDisplayMode(SDL_DisplayMode& currDis);

	SDL_Rect displayArea;
	bool targetLock;
	Sprite* target;
};

#endif