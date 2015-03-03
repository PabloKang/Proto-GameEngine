#include "Star Hornet.h"


Entity::Entity(int entityID, std::string entityType, int health, double xPos, double yPos, double width, double height)//Sprite sprite;
{
	id = entityID;
	type = entityType;
	this->health = health;
	rect.h = height;
	rect.w = width;
	rect.x = xPos;
	rect.y = yPos;

	this->sprite = //globalspritemap[entityType]; preloaded spritemap of all sprites we needed so we don't have to reload
					//and make the frames all over again for each individual entity
					//or this->sprite = sprite;
}


Entity::~Entity()
{
}

void Entity::draw(std::string sequence){
	sprite.show(sequence);
}

void Entity::update(){
	//send out message to messenger accordingly ex. to pop it from the entity list
	if (health <= 0){

	}
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

void Entity::move(double move_x, double move_y, double angle){
	sprite.movex(move_x);
	sprite.movey(move_y);
	sprite.rotate(angle);
}