#include "Star Hornet.h"
#include "Camera.h"

Camera::Camera(int sceneX, int sceneY, int height, int width){
	this->x = sceneX;
	this->y = sceneY;
	this->height = height;
	this->width = width;
	//currentScene = getScene(sceneX, sceneY);
}

Camera::~Camera(){

}


//bool Camera::isEntityOnScr(Entity entity){
//	//return getSceneFromCoords(entity.rect.x, entity.rect.y) == currentScene; //need entity, is the coords called x and y or something else?
//	//also is comparison of two class objects without an overloaded equality operator going to work? all we need to check is if the pointers are to the same object
//	return true;
//}

//changes the camera's current coordinates. this sets the
void Camera::changeCoord(int sceneX, int sceneY){
	this->x = sceneX;
	this->y = sceneY;

	this->targetLock = 0;
	//currentScene = getScene(sceneX, sceneY);

}

//adds a target for the camera to lock on with its coordinates
void Camera::setTarget(Sprite target){
	this->target = target;
}


//call this function in a for loop? once per tick?
void Camera::update(){
	if (this->targetLock){
		this->x = target.spriteRect.x;
		this->y = target.spriteRect.y;
		this->targetLock = 1;
	}
	else{
		//we dont want to do anything if camera is not locked
	}

}


//add sprite to queue with priority based on Sprite.layer. low priority (lower number for layer) gets precidence
void Camera::queueSprite(Sprite s){
	if (s.spriteRect.x < 0 || s.spriteRect.x > this->width){
		return;
	}
	if (s.spriteRect.y < 0 || s.spriteRect.y > this->height){
		return;
	}

	//queue.push(s);
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
//		SDL_RenderCopyEx(temp->getRenderer(), temp->frame.getTexture(), temp->frame.getTexture(), temp->getRect(), temp->getAngle(), temp->getCenter(), temp->getFlip());
//
//	}
//
//
//}