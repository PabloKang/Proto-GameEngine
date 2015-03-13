#include "Camera.h"


Camera::Camera()
{
	// Find current display settings and set window size
	SDL_DisplayMode current;
	fillDisplayMode(current);
	int screenWidth = current.w * WIDTH_RATIO;
	int screenHeight = current.h * HEIGHT_RATIO;

	// Create all game hardware and set engine
	SDL_Window		*win = SDL_CreateWindow("Star Hornet", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	SDL_Renderer	*ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//Camera(win, ren, screenWidth, screenHeight);

	displayArea = { 0, 0, screenWidth, screenHeight };
	window = win;
	renderer = ren;
}

Camera::Camera(SDL_Window* win, SDL_Renderer* ren, int w, int h)
{
	displayArea = { 0, 0, w, h };
	window = win;
	renderer = ren;
}

Camera::~Camera(){
}


bool Camera::isInDisplay(Sprite s){

	int entLeft = s.spriteRect.x,
		entRight = s.spriteRect.x + s.spriteRect.w,
		entTop = s.spriteRect.y,
		entBottom = s.spriteRect.y + s.spriteRect.h,
		camLeft = displayArea.x,
		camRight = displayArea.x + displayArea.w,
		camTop = displayArea.y,
		camBottom = displayArea.y + displayArea.h;

	if ((entRight > camLeft && entLeft < camRight) && (entBottom > camTop && entTop < camBottom))
	{
		return true;
	}
	return false;
}

//changes the camera's current coordinates. this sets the
void Camera::setCameraPos(int x, int y){
	displayArea.x = x;
	displayArea.y = y;
}

//adds a target for the camera to lock on with its coordinates
void Camera::setTarget(Sprite* lock){
	target = lock;
}


//call this function in a for loop? once per tick?
void Camera::update(){
	if (targetLock){
		setCameraPos(target->spriteRect.x, target->spriteRect.y);
	}
}


//add sprite to queue with priority based on Sprite.layer. low priority (lower number for layer) gets precidence
void Camera::queueSprite(Sprite s){
	if (isInDisplay(s)) {
		drawQueue.push(s);
	}
}


////returns top sprite in queue, else returns NULL if queue is empty
//Sprite Camera::popSprite(){
//	if (!queue.empty()){
//		return queue.pop();
//	}
//	else{
//		return NULL;
//	}
//}
//
////returns size of queue
//int Camera::queueSize(){
//	return queue.size();
//}
//
////returns frotn of queue (one going next)
//Sprite Camera::queuePeek(){
//	return queue.top();
//}
//
////DONT KNOW WHAT TO PUT FOR 3RD VARIABLE. DESTINATION RECTANGLE PLEASE FILL IN
////NEED SPRIET CLASS TO ADD getTexture, getRenderer, getRect, 
//void camera::draw(){
//	while (!queue.empty()){
//		Sprite * temp = queue.pop();
//		temp.draw();
//
//	}
//
//
//}


void Camera::fillDisplayMode(SDL_DisplayMode& currDis)
{
	for (int i = 0; i < SDL_GetNumVideoDisplays(); ++i){
		int should_be_zero = SDL_GetCurrentDisplayMode(i, &currDis);

		if (should_be_zero != 0)
			SDL_Log("Could not get display mode for video display #%d: %s", i, SDL_GetError());
		else // On success, print the current display mode.
			SDL_Log("Display #%d: current display mode is %dx%dpx @ %dhz. \n", i, currDis.w, currDis.h, currDis.refresh_rate);
	}
}