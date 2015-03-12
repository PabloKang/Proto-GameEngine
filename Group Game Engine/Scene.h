#ifndef SCENE_H
#define SCENE_H

#include "Star Hornet.h"
#include "Entity.h"


class Scene{
public:
	// Constructors & Destructors
	Scene();
	Scene(int sceneWidth, int sceneHeight, std::string sceneName);//I'm assuming this is to declare the size of the window?

	~Scene();

	// Functions
	void update();
	void draw();
	//	int	 size();
	void	addSprite(Sprite sprite);
	void	delSprite(int id);

	Sprite& getSprite(int id); //Don't need this i think?
	//void collisionDetection(std::pair<Sprite, Entity*> pair);
	void collisionDetection();
	void addEntity(std::string name, Entity entity);
	void delEntity(std::string name, Entity entity);
	//std::vectors in case it's better to have it in the .h
	std::vector<Entity> shipEnts;
	std::vector<Entity> bulEnts;

	// Public Variables
	std::string sceneName;
	int			sceneWidth;
	int			sceneHeight;

	// Map of all entities in the scene
	std::map<int, Sprite> sprites;
	std::map<std::string, std::vector<Entity>> entities;

};

#endif