#ifndef SCENE_H
#define SCENE_H

#include "Star Hornet.h"
#include "Entity.h"


class Scene{
public:
	// Constructors & Destructors
	Scene();
	Scene(std::vector<Entity> entity);
	~Scene();

	// Functions
	void update();
	void draw();
	int	 size();
	void	addEntity(Entity entity);
	void	delEntity(int id);
	Entity& getEntity(int id);


	// Public Variables
	std::string sceneName;
	int			sceneWidth;
	int			sceneHeight;

	// Map of all entities in the scene
	std::map<int, Entity> entities;
};

#endif