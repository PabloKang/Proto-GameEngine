#include "Star Hornet.h"
#include "Scene.h"
#include "Entity.h"

//change everytyhing to using a map.
Scene::Scene(int sceneWidth, int sceneHeight) : sceneWidth(sceneWidth), sceneHeight(sceneHeight){}


//constructor assuming that there's a preexists vector of entities 

//will update the scene. goes through the scene that it's currently in and calls entity.update 
//	to see whether or not the entity is alive. if it's not, remove it. else, render i. //unsure as to what to pass.
//	do we need to clear first since this might be doing the rendering?


//i need a way to determine what types of objects they are in order to display specific messages. 
//Maybe add in an objectID? 1/2/3 for Ship, Bullets, Rocks/Enemy objects? 
void Scene::update()
{
	for (std::map<int, Sprite>::iterator it = sprites.begin(); it != sprites.end(); it++)
	{
		for (std::map<int, Sprite>::iterator it2 = sprites.begin(); it2 != sprites.end(); it2++)
		{
			if (it->first != it2->first)//comparison of sprite IDs. I'm assuming they're unique. If it's the same, don't check.
				//if it's equal, check coordinates for collisions with any other sprites. If there's collisions, remove collisions from the scene. 
			{
				if (it->second.getX() == it2->second.getX() && it->second.getY() == it2->second.getY())
					//checking if the coordinates are the same. 
					delSprite(it->first);
					//removing the spirte by ID from the map. 
				
			}
		}
	}
}


void Scene::draw()
{
	for (std::map<int, Sprite>::iterator it = sprites.begin(); it != sprites.end(); it++)
	{
		//call sprite.draw()? need an int in order to do so. Frame index. is there going to be a way to know which index?
	}
	//i'm assuming call camera.draw here?
}

//adds an entity onto the scene. 
//need to add a spriteID to the sprite cpp in order for this to work since it's not working with entities.

void Scene::addSprite(Sprite sprite)
{
	sprites.insert(std::pair<int, Sprite>(sprite.spriteID, sprite));
}

void Scene::delSprite(int id)
{
	sprites.erase(id);
}

//removes an entity onto the scene.
Sprite& Scene::getSprite(int id)
{
	return sprites.at(id);
}

/*adding for multimap
void Scene::addSprite(Sprite sprite)
{
sprites.insert(std::pair<int, Sprite>(sprite.objectID, sprite));
}
//i'd need objectID to be between 1-3 in order to distinguish between the different types.
*/

/*trying to use multimap
//removes an entity onto the scene.
void Scene::delSprite(Sprite sprite)
{
std::multimap<int, Sprite>::iterator it = sprites.find(sprite.objectID);
for (it; )
}
*/


