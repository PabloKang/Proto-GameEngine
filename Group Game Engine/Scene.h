#pragma once
#include <vector>
#include "Entity.h"


class Scene{
public:
	Scene();
	Scene(std::vector<Entity> entities);
	int getSize();
	void addEntity(Entity entity);
	void delEntity(Entity entity);
private:
	std::vector<Entity> entities;





};

