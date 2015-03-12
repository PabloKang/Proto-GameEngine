#ifndef SCENE_H
#define SCENE_H

#include "Star Hornet.h"
#include "Sprite.h"


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
//multimapversion	void	delSprite(Sprite sprite);
	Sprite& getSprite(int id); //Don't need this i think?
	void collisionDetection(std::pair<Sprite, Entity*> pair);

	// Public Variables
	std::string sceneName;
	int			sceneWidth;
	int			sceneHeight;

	// Map of all entities in the scene
	std::map<int, Sprite> sprites;
	std::map<int, Entity*> entities;
	//std::multimap<int, Sprite> sprites;
	//the ints will be 1-3
	//1 will be the player, 2 will be the player projectiles(bullets), 3 will be enemies/boulders?
};

#endif