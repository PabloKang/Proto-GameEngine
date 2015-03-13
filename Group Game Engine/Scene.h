#ifndef SCENE_H
#define SCENE_H

#include "Star Hornet.h"
#include "SpriteManager.h"
#include "Entity.h"

class Scene
{
public:
	// Constructors & Destructors
	Scene();
	Scene(Camera* cam);
	~Scene();

	// Functions
	void init(Camera* cam);
	std::string exec();

	void	update();
	void	addSprite(Sprite sprite);
	void	delSprite(int id);
	Sprite& getSprite(int id); 
	void	collisionDetection();
	void	addCollidable(Entity* entity);
	void	delCollidable(std::string type, int entID);

	// Public Variables
	std::string sceneName;

	// Map of all entities in the scene
	std::map<int, Sprite> sprites;
	std::map<std::string, std::vector<Entity*>> collidables;

private:
	Camera* camera;
	SpriteManager spriteManager;
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
};

#endif