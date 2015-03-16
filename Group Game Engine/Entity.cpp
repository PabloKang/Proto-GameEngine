#include "Entity.h"


Entity::Entity()
{
	speed = 0;
	curHealth = 100;
	maxHealth = 100;
	alive = true;
	visible = true;
	collidable = true;
}


Entity::Entity(float entID, float lvl, std::string entType, SDL_Texture* sprtsht, SDL_Rect spriteR, SDL_Rect hitBoxR, SDL_Renderer* ren)
{
	id = entID;
	layer = lvl;
	entityType = entType;
	spritesheet = sprtsht;
	spriteRect = spriteR;
	hitBox = hitBoxR;
	center.x = spriteRect.w / 2.0;
	center.y = spriteRect.h / 2.0;

	renderer = ren;

	type = ENTITY;
}


Entity::~Entity()
{
}


void Entity::update()
{
	move();
}


void Entity::move(){
	float angleRad = M_PI * (angle / 180);

	moveX(cos(angleRad) * speed);
	moveY(sin(angleRad) * speed);
}


void Entity::initFrames()
{

}