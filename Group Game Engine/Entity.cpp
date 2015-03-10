#include "Star Hornet.h"
#include "Entity.h"
#include "Engine.h"

Entity::Entity()
{
	entityID = -1;
	entityType = "null";

	spritesheet = NULL;
	spriteRect.w = hitBox.w = 0;
	spriteRect.h = hitBox.h = 0;
	spriteRect.x = hitBox.x = 0;
	spriteRect.y = hitBox.y = 0;
}


Entity::Entity(int id, std::string type, SDL_Texture* sprtsht, Hardware* hrd, SDL_Rect spriteR, SDL_Rect hitBoxR)//Sprite sprite;
{
	entityID = id;
	entityType = type;

	spritesheet = sprtsht;
	spriteRect = spriteR;
	hitBox = hitBoxR;
}


Entity::~Entity()
{
}


void Entity::update(){
}


void Entity::move(double deltaX, double deltaY, double deltaAngle){
	moveX(deltaX * speed);
	moveY(deltaY * speed);
	rotate(deltaAngle);
}

void Entity::playSound(std::string sound){

}

bool Entity::onScreen(){
	return visible;
}

bool Entity::canCollide(){
	return collide;
}

void Entity::move(double move_x, double move_y, double angle){
	sprite.movex(move_x * speed);
	sprite.movey(move_y * speed);
	sprite.rotate(angle);
}