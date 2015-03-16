#ifndef SCENE_H
#define SCENE_H

#include "Star Hornet.h"
#include "SpriteManager.h"
#include "Entity.h"
#include "Player.h"

class Projectile;


class Scene
{
public:
	// Constructors & Destructors
	Scene();
	Scene(Camera* cam,SoundManager* sm);
	~Scene();

	// Functions
	void init(Camera* cam, SoundManager* sm);
	std::string exec();

	void	update();
	//void	addSprite(Sprite sprite);
	//void	delSprite(float id);
	//Sprite& getSprite(float id); 
	void	collisionDetection();
	void	addCollidable(Entity* entity);
	void	delCollidable(std::string type, float entID);

	// Public Variables
	std::string sceneName;

	// All sprites and entities in this scene:
	//std::map<float, Sprite*> sprites;
	Sprite background;
	Player hornet;
	std::map<float, Ship> enemies;
	std::map<float, Projectile> bullets;
	std::map<std::string, std::vector<Entity*>> collidables;




	void loadSound(std::string musicname, std::string filename);
	void playSound(std::string soundstring, int repeat);
	void loadMusic(std::string musicname, std::string filename);
	void playMusic(std::string musicstring, int repeat);

private:
	Camera* camera;
	SpriteManager spriteManager;
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	SoundManager* sm;
	SoundPlayer sp;
};

#endif