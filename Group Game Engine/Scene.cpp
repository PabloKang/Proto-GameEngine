#include "Star Hornet.h"
#include "Scene.h"
#include "Entity.h"

Scene::Scene(){
	sceneWidth = 0;
	sceneHeight = 0;
}

//change everytyhing to using a map.
Scene::Scene(int sceneWidth, int sceneHeight, std::string sceneName) : sceneWidth(sceneWidth), sceneHeight(sceneHeight), sceneName(sceneName){}
//constructor now takes in the sceneWidth and sceneHeight so that it could be initialized correctly. 
//I'm not sure what these are needed for since I don't really use it throughout. 


Scene::~Scene(){

}

//i need a way to determine what types of objects they are in order to display specific messages. 
//Maybe add in an objectID? 1/2/3 for Ship, Bullets, Rocks/Enemy objects? 
//I did it assuming that i'll there will be an objectID in order to distinguish between the two. 
void Scene::update()
{
	for (std::map<int, Sprite>::iterator it = sprites.begin(); it != sprites.end(); it++)
	{
		for (std::map<int, Sprite>::iterator it2 = sprites.begin(); it2 != sprites.end(); it2++)
		{
			if (it->first != it2->first)//comparison of sprite IDs. I'm assuming they're unique. If it's the same, don't check.
				//if it's equal, check coordinates for collisions with any other sprites. If there's collisions, remove collisions from the scene. 
			{
				if ((it->second.getX() == it2->second.getX() && it->second.getY() == it2->second.getY()) 
					|| it->second.getX() < sceneWidth || it->second.getY() < sceneHeight 
					|| it->second.getX() > sceneWidth || it->second.getX() > sceneHeight)
					//assuming that sceneHeight/Width are of the whole window size. if they go off the map, they die
					//checking if the coordinates are the same. 
				{
					//if (it->second.objectID == 1)
					//{	
					//	//call messenger for ship death or lose hp
					//}
					//else if (it->second.objectID == 2)
					//{
					//	//call messenger for bullet death
					//}
					//else
					//{	
					//	//call messenger for rock/enemy death.
					//}
					delSprite(it->first);//remove no matter what
				}
					//removing the spirte by ID from the map. 
				
			}
		}
	}
}


void Scene::draw()
{
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


//the rest is just testing for multimaps. Multimaps may have been easier, but the deletion was confusing. 
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


