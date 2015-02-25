#include "Star Hornet.h"


/*Scene::Scene()
{
std::vector<Entity>
}
don't need this?*/

Scene::Scene(std::vector<Entity> entity)
{
	std::copy(entity.begin(), entity.end(), entities.begin());
}

int Scene::getSize()
{
	return entities.size();
}

void Scene::addEntity(Entity entity)
{
	entities.push_back(entity);
}

void Scene::delEntity(Entity entity){
	for (int i = 0; i < entities.size(); i++){
		if (entity.id() == entities[i].id()){
			entities.erase(entities.begin() + i);
		}

	}
}