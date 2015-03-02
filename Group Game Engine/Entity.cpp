#include "Star Hornet.h"


Entity::Entity(int entityID, std::string entityType, int xPos, int yPos, int width, int height)
{
	id = entityID;
	type = entityType;

	rect.h = height;
	rect.w = width;
	rect.x = xPos;
	rect.y = yPos;

	sprite = Sprite(rect);
}


Entity::~Entity()
{
}
