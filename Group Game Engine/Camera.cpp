#include "Camera.h"

Camera::Camera(int sceneX, int sceneY){
	sceneIndex.first = sceneX;
	sceneIndex.second = sceneY;

	//currentScene = getScene(sceneX, sceneY);
}

Camera::~Camera(){

}

void Camera::renderEntities(){


}

bool Camera::isEntityOnScr(Entity entity){
	//return getSceneFromCoords(entity.rect.x, entity.rect.y) == currentScene; //need entity, is the coords called x and y or something else?
	//also is comparison of two class objects without an overloaded equality operator going to work? all we need to check is if the pointers are to the same object
	return true;
}

void Camera::changeScene(int sceneX, int sceneY){
	sceneIndex.first = sceneX;
	sceneIndex.second = sceneY;

	//currentScene = getScene(sceneX, sceneY);

}