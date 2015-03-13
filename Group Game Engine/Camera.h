#ifndef CAMERA_H
#define CAMERA_H

#include "Star Hornet.h"
#include "Sprite.h"

typedef std::priority_queue<Sprite, std::vector<Sprite>, SpriteCompare> render_queue;


class Camera{
public:

	Camera();
	Camera(SDL_Window* win, SDL_Renderer* ren, int w, int h);
	~Camera();

	void update();
	void draw();

	void moveCameraRight(int deltaX);
	void moveCameraLeft(int deltaX);
	void moveCameraUp(int deltaY);
	void moveCameraDown(int deltaY);
	void setCameraPos(int x, int y);

	void setTarget(Sprite* target);
	bool isInDisplay(Sprite& s);
	void queueSprite(Sprite& s);
	//Sprite& popSprite();

	int width;
	int height;
	SDL_Window* window;
	SDL_Renderer* renderer;
	render_queue drawQueue;

private:
	void fillDisplayMode(SDL_DisplayMode& currDis);

	SDL_Rect displayArea;
	bool targetLock;
	Sprite* target;
};

#endif