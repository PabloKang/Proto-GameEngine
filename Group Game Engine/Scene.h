#ifndef SCENE_H
#define SCENE_H

#include "Star Hornet.h"


class Scene{
public:
	Scene();
	Scene(std::vector<Entity> entity);
	~Scene();

	void addEntity(Entity entity);
	int getSize();

	std::map<int, Entity> entities;

};

#endif