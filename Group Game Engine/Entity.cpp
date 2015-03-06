#include "Star Hornet.h"
#include "Entity.h"
#include "Engine.h"

Entity::Entity()
{
	id = -1;
	type = "null";

	rect.h = 0;
	rect.w = 0;
	rect.x = 0;
	rect.y = 0;

	speed = 0;
	angle = 0;

	sprite = Sprite(rect, hardware.renderer);
}


Entity::Entity(int entityID, std::string entityType, SDL_Texture* sprsht, SDL_Renderer* ren, double xPos, double yPos, double width, double height)//Sprite sprite;
{
	id = entityID;
	type = entityType;
	this->visible = visible;
	this->collide = collide;
	spritesheet = sprsht;

	rect.h = height;
	rect.w = width;
	rect.x = xPos;
	rect.y = yPos;

	speed = 0;
	angle = 0;

	sprite = Sprite(rect, hardware.renderer);
}


Entity::Entity(int entityID, std::string entityType, SDL_Texture* sprsht, SDL_Rect info)//Sprite sprite;
{
	id = entityID;
	type = entityType;

	spritesheet = sprsht;

	rect.h = info.h;
	rect.w = info.w;
	rect.x = info.x;
	rect.y = info.y;

	speed = 0;
	angle = 0;

	sprite = Sprite(info, hardware.renderer);
}


Entity::~Entity()
{
}

void Entity::draw(std::string sequence){
	sprite.show(sequence);
}

void Entity::update(){
	//CheckPosition
	if (rect.x < 0 || //scene x boundary
		rect.x + rect.w > 300 //scene x2 boundary
		)
	{
		//rotate or flip accordingly if we want it to stay in the scene or make it stop in the next scene
	}

	else if (rect.y < 0, //scene y boundary
		rect.y + rect.h > 300) //scene y2 boundary
	{
		//rotate or flip accordingly if we want it to stay in the scene or make it stop in the next scene
	}
}

bool Entity::isAlive(){
	return alive;
}

void Entity::move(double move_x, double move_y, double angle){
	sprite.movex(move_x * speed);
	sprite.movey(move_y * speed);
	sprite.rotate(angle);
}