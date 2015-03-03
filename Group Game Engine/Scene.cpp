#include "Star Hornet.h"


/*Scene::Scene()
{
std::vector<Entity>
}
don't need this?*/

Scene::Scene(std::vector<Entity> entity)//constructor assuming that there's a preexists vector of entities. 
{
	std::copy(entity.begin(), entity.end(), entities.begin());
}

int Scene::getSize()//get the amount of entities in the scene. not sure if his is needed. 
{
	return entities.size();
}

void Scene::addEntity(Entity entity)//adds on entities onto the scene. 
{
	entities.push_back(entity);
}


void update_scene(){//will update the scene. goes through the scene that it's currently in and calls entity.update 
	//to see whether or not the entity is alive. if it's not, remove it. else, render i. //unsure as to what to pass.
	//do we need to clear first since this might be doing the rendering?
	for (int i = entities.begin(); i != entities.end(); i++)
	{
		if (i.update() == 1)
			Entity.draw("is this correct?");//if the entity.update comes out true, then that means it's alive. call draw->show to render i.
		else
			entities.erase(i);
	}
}
/*don't think this is needed anymore with update_scene

void Scene::delEntity(Entity entity){
	for (int i = 0; i < entities.size(); i++){
		if (entity.id() == entities[i].id()){
			entities.erase(entities.begin() + i);
		}

	}
}*/