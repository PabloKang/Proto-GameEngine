#include "Scene.h"


Scene::Scene(){
	//local declarations if that's better. I declared it in the .h though. 
	std::vector<Entity*> shipEnts;
	std::vector<Entity*> bulEnts;

	collidables.insert(std::pair<std::string, std::vector<Entity*>>("Ship", shipEnts));
	collidables.insert(std::pair<std::string, std::vector<Entity*>>("Bullet", bulEnts));
}

//change everytyhing to using a map.
Scene::Scene(Camera* cam) : sceneName("NULL"), camera(cam)
{
	Scene();
}


Scene::~Scene(){

}


void Scene::init()
{

}


std::string Scene::exec()
{
	return "NULL";
}


void Scene::addCollidable(Entity* entity)
{
	if (entity->collidable){
		collidables.at(entity->entityType).push_back(entity);
	}
}


void Scene::delCollidable(std::string type, int entID)
{
	for (int i = 0; i < collidables.at(type).size(); i++)
	{
		if (collidables.at(type).at(i)->id == entID)
		{
			collidables.at(type).erase(collidables.at(type).begin() + i);
			break;//so it doesn't erase more than one if there's a possible collision in entity ids
		}
	}
}


void Scene::collisionDetection()
{
	for (int i = 0; i < collidables.at("Ship").size(); i++)
	{
		for (int j = 0; j < collidables.at("Bullet").size(); j++)
		{
			Entity* currShip = collidables.at("Ship").at(i);
			Entity* currBull = collidables.at("Bullet").at(j);
			SDL_Point bullet = currBull->center;

			int shipLeft = currShip->hitBox.x,
				shipRight = currShip->hitBox.x + currShip->hitBox.w,
				shipTop = currShip->hitBox.y,
				shipBottom = currShip->hitBox.y + currShip->hitBox.h;

			if ((bullet.x > shipLeft && bullet.x < shipRight) && (bullet.y > shipTop && bullet.y < shipBottom))
			{
				currShip->curHealth -= currBull->curHealth;
				if (currShip->curHealth <= 0) {
					delCollidable(currShip->entityType, currShip->id);
					sprites.erase(currShip->id);
					// TODO - Render explosion ////////////////////////////////////////////////////////////
				}

				delCollidable(currBull->entityType, currBull->id);
				sprites.erase(currBull->id);
			}
		}
	}

}


void Scene::update()//goes through the sprites map and calls draw on it. 
{//goes through the sprites and calls all of the updates for them. call the updates for entities instead?
	for (std::map<int, Sprite>::iterator it = sprites.begin(); it != sprites.end(); it++)
	{
		it->second.update();
	}
	collisionDetection();
}


void Scene::addSprite(Sprite sprite)
{
	sprites.insert(std::pair<int, Sprite>(sprite.id, sprite));
}//adds a sprite into the mapping. Uses it's spriteID in order to map it. 


void Scene::delSprite(int id)
{
	sprites.erase(id);
}//removes a sprite based on it's ID in the mapping.


Sprite& Scene::getSprite(int id)
{
	return sprites.at(id);
}//get a sprite given it's ID in the mapping
