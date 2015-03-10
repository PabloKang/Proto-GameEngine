#include "Star Hornet.h"
#include "Scene.h"
#include "Entity.h"


Scene::Scene()
{

}


//constructor assuming that there's a preexists vector of entities. 
Scene::Scene(std::vector<Entity> entity)
{
	std::copy(entity.begin(), entity.end(), entities.begin());
}


//will update the scene. goes through the scene that it's currently in and calls entity.update 
//	to see whether or not the entity is alive. if it's not, remove it. else, render i. //unsure as to what to pass.
//	do we need to clear first since this might be doing the rendering?
void Scene::update()
{

}


void Scene::draw()
{

}


//get the amount of entities in the scene. not sure if his is needed. 
int Scene::size()
{
	return entities.size();
}


//adds an entity onto the scene. 
void Scene::addEntity(Entity entity)
{
	entities.insert(std::pair<int,Entity>(entity.entityID, entity));
}


//removes an entity onto the scene. 
void Scene::delEntity(int id)
{
	entities.erase(id);
}


//removes an entity onto the scene.
Entity& Scene::getEntity(int id)
{
	return entities.at(id);
}
