#include "Entity.h"



Entity::Entity()
{
	id = -1;
	entityType = "null";

	spritesheet = NULL;
	spriteRect.w = hitBox.w = 0;
	spriteRect.h = hitBox.h = 0;
	spriteRect.x = hitBox.x = 0;
	spriteRect.y = hitBox.y = 0;
}


Entity::Entity(int entID, int lvl, std::string type, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, Camera* cam)//Sprite sprite;
{
	Sprite(entID, lvl, spriteR, cam);

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