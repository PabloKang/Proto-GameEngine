#include "Star Hornet.h"
#include "Scene.h"


Scene::Scene(){
	sceneWidth = 0;
	sceneHeight = 0;
	//local declarations if that's better. I declared it in the .h though. 
	//std::vector<Entity> shipEnts;
	//std::vector<Entity> bulEnts;
	entities.insert(std::pair<std::string, std::vector<Entity>>("Ships", shipEnts));
	entities.insert(std::pair<std::string, std::vector<Entity>>("Bullets", bulEnts));
}

//change everytyhing to using a map.
Scene::Scene(int sceneWidth, int sceneHeight, std::string sceneName) : sceneWidth(sceneWidth), sceneHeight(sceneHeight), sceneName(sceneName){}
//constructor now takes in the sceneWidth and sceneHeight so that it could be initialized correctly. 
//I'm not sure what these are needed for since I don't really use it throughout. 


Scene::~Scene(){

}

void Scene::addEntity(std::string name, Entity entity)
{
	entities.at(name).push_back(entity);
}
void Scene::delEntity(std::string name, Entity entity)
{
	for (std::vector<Entity>::iterator it = entities.at(name).begin(); it != entities.at(name).end(); it++)
	{
		if (it->entityID == entity.entityID)
		{
			entities.at(name).erase(it);
			break;//so it doesn't erase more than one if there's a possible collision in entity ids
		}

	}
}
void Scene::collisionDetection()//std::pair<Sprite, Entity*> pair)//don't think i need the parameters
{
	for (int i = 0; i < entities.at("Ships").size(); i++)
	{
		for (int j = 0; j < entities.at("Bullets").size(); j++)
		{
			int shipLeft = entities.at("Ships").at(i).hitBox.x, shipRight = entities.at("Ships").at(i).hitBox.x + entities.at("Ships").at(i).hitBox.w,
				shipTop = entities.at("Ships").at(i).hitBox.y, shipBottom = entities.at("Ships").at(i).hitBox.y + entities.at("Ships").at(i).hitBox.h,
				bulletLeft = entities.at("Bullets").at(j).hitBox.x, bulletRight = entities.at("Bullets").at(j).hitBox.x + entities.at("Bullets").at(j).hitBox.w,
				bulletTop = entities.at("Bullets").at(j).hitBox.y, bulletBottom = entities.at("Bullets").at(j).hitBox.y + entities.at("Bullets").at(j).hitBox.h;
			if (shipBottom <= bulletTop || shipTop >= bulletBottom || shipRight <= bulletLeft || shipLeft >= bulletRight)
			{
				//there's a collision so call message and take damage. 
				//TODO
			}
		}
	}

}

//i need a way to determine what types of objects they are in order to display specific messages. 
//Maybe add in an objectID? 1/2/3 for Ship, Bullets, Rocks/Enemy objects? 
//I did it assuming that i'll there will be an objectID in order to distinguish between the two. 
void Scene::update()//goes through the sprites map and calls draw on it. 
{//goes through the sprites and calls all of the updates for them. call the updates for entities instead?
	for (std::map<int, Sprite>::iterator it = sprites.begin(); it != sprites.end(); it++)
	{
		//it->second.draw("default");//don't know what styring to put in
	}
	//call hrdware.camera.draw()
}


void Scene::draw()
{//goes through the entities and calls the update on it. 
	//not really sure as to how you want me to do this anymore. I'm assuming this was goign to render everything.
	//sprite has two draw functions, but I don't believe that I can use either without some more context. 
	//i've tried going through the code and other cpps, but here's nothing really helpful hat I could find. 
	for (std::map<int, Sprite>::iterator it = sprites.begin(); it != sprites.end(); it++)
	{
		//call sprite.draw()? need an int in order to do so. Frame index. is there going to be a way to know which index?
	}
	//i'm assuming call camera.draw here per your email. However, it's commented out now, so I guess it's no longer needed. 
}

//adds an entity onto the scene. 
//need to add a spriteID to the sprite cpp in order for this to work since it's not working with entities.
//You said to change this from entities to sprites, and that you'd change it so that sprites had IDs in order to work for this.

void Scene::addSprite(Sprite sprite)
{
	//sprites.insert(std::pair<int, Sprite>(sprite.spriteID, sprite));
}//adds a sprite into the mapping. Uses it's spriteID in order to map it. 

void Scene::delSprite(int id)
{
	sprites.erase(id);
}//removes a sprite based on it's ID in the mapping.


Sprite& Scene::getSprite(int id)
{
	return sprites.at(id);
}//get a sprite given it's ID in the mapping
