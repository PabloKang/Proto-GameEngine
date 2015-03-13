#include "Entity.h"


Entity::Entity()
{
	Sprite();
}


Entity::Entity(int entID, int lvl, std::string type, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, SDL_Renderer* ren)//Sprite sprite;
{
	Sprite(entID, lvl, spriteR, ren);

	entityType = type;

	spritesheet = sprtsht;
	spriteRect = spriteR;
	hitBox = hitBoxR;
}


Entity::~Entity()
{
}


void Entity::move(double deltaX, double deltaY, double deltaAngle){
	moveX(deltaX * speed);
	moveY(deltaY * speed);
	rotate(deltaAngle);
}


void Entity::initFrames()
{

}