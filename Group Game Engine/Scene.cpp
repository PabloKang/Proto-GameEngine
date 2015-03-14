#include "Scene.h"
#include "Camera.h"
#include "Player.h"


Scene::Scene()
{
	sceneName = "Scene";

	std::vector<Entity*> shipEnts;
	std::vector<Entity*> bulEnts;

	collidables.insert(std::pair<std::string, std::vector<Entity*>>("Ship", shipEnts));
	collidables.insert(std::pair<std::string, std::vector<Entity*>>("Bullet", bulEnts));
}

//change everytyhing to using a map.
Scene::Scene(Camera* cam) : camera(cam)
{
	sceneName = "Scene";

	std::vector<Entity*> shipEnts;
	std::vector<Entity*> bulEnts;

	collidables.insert(std::pair<std::string, std::vector<Entity*>>("Ship", shipEnts));
	collidables.insert(std::pair<std::string, std::vector<Entity*>>("Bullet", bulEnts));
}


Scene::~Scene(){

}


void Scene::init(Camera* cam)
{
	camera = cam;

	// Initialize all textures:
	spriteManager.add_texture("hornet", spriteManager.loadTexture("hornet_body.gif", camera->renderer));
	//spriteManager.add_texture("turret", spriteManager.loadTexture("hornet_turret.gif", camera->renderer));
	//spriteManager.add_texture("thrust", spriteManager.loadTexture("hornet_thrust.gif", camera->renderer));
	spriteManager.add_texture("background", spriteManager.loadTexture("cloudy_starfield_bg.jpg", camera->renderer));

	Sprite background = Sprite(0, 1, SDL_Rect{ 0, 0, camera->width, camera->height },camera->renderer);
	background.makeFrame(spriteManager.get_texture("background"), -1, 1);
	background.addFrameToSequence("default", 0);

	//// Initialize all entities:
	//Player hornet = Player(0, 1, "Ship", spriteManager.get_texture("hornet"), SDL_Rect{ camera->width / 2, camera->height / 2, 128, 128 }, SDL_Rect{ 0, 0, 128, 128 }, camera->renderer);
	//hornet.turret = Sprite(1, 2, SDL_Rect{ camera->width / 2, camera->height / 2, 128, 128 }, camera->renderer);
	Player hornet = Player(1, 0, "Ship", spriteManager.get_texture("hornet"), SDL_Rect{ camera->width/2, camera->height/2, 128, 128 }, SDL_Rect{ 0, 0, 128, 128 }, camera->renderer);
	//Player hornet = Player(0, 1, "Ship", spriteManager.loadTexture("hornet_body_small.gif", camera->renderer), SDL_Rect{ 300, 300, 128, 128 }, SDL_Rect{ 0, 0, 128, 128 }, camera->renderer);
	
	sprites.insert(std::pair<int, Sprite>(background.id, background));
	sprites.insert(std::pair<int, Sprite>(hornet.id, hornet));
	//sprites.insert(std::pair<int, Sprite>(hornet.id, hornet.turret));
}


std::string Scene::exec()
{
	SDL_Event e;
	bool quit = false;


	// MAIN GAME LOOP -----------------------------------------
	while (!quit){

		// Poll all events in event queue
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
				break;
			}
			// Check all one-time keypress events
			if (e.type == SDL_KEYDOWN){
				if (e.key.keysym.sym == SDLK_ESCAPE){
					quit = true;
				}
			}
		}


		// Clear the renderer
		SDL_RenderClear(camera->renderer);


	}
	return "NULL";
}


void Scene::addCollidable(Entity* entity)
{
	if (entity->collidable){
		collidables.at(entity->entityType).push_back(entity);
	}
}


void Scene::delCollidable(std::string type, int entID)
{
	for (unsigned int i = 0; i < collidables.at(type).size(); i++)
	{
		if (collidables.at(type).at(i)->id == entID)
		{
			collidables.at(type).erase(collidables.at(type).begin() + i);
			break;//so it doesn't erase more than one if there's a possible collision in entity ids
		}
	}
}


void Scene::collisionDetection()
{
	for (unsigned int i = 0; i < collidables.at("Ship").size(); i++)
	{
		for (unsigned int j = 0; j < collidables.at("Bullet").size(); j++)
		{
			Entity* currShip = collidables.at("Ship").at(i);
			Entity* currBull = collidables.at("Bullet").at(j);
			SDL_Point bullet = currBull->center;

			int shipLeft = currShip->hitBox.x,
				shipRight = currShip->hitBox.x + currShip->hitBox.w,
				shipTop = currShip->hitBox.y,
				shipBottom = currShip->hitBox.y + currShip->hitBox.h;

			if ((bullet.x > shipLeft && bullet.x < shipRight) && (bullet.y > shipTop && bullet.y < shipBottom))
			{
				currShip->curHealth -= currBull->curHealth;
				if (currShip->curHealth <= 0) {
					delCollidable(currShip->entityType, currShip->id);
					sprites.erase(currShip->id);
					// TODO - Render explosion ////////////////////////////////////////////////////////////
				}

				delCollidable(currBull->entityType, currBull->id);
				sprites.erase(currBull->id);
			}
		}
	}

}


void Scene::update()//goes through the sprites map and calls draw on it. 
{//goes through the sprites and calls all of the updates for them. call the updates for entities instead?
	if (sprites.size() > 0) {
		collisionDetection();
		for (std::map<int, Sprite>::iterator it = sprites.begin(); it != sprites.end(); it++)
		{
			if (it->second.type == PLAYER) {
				Sprite * sprite = &it->second;
				Player * player = static_cast<Player*>(sprite);
				player->update(currentKeyStates);
				camera->queueSprite(*player);
				camera->queueSprite(player->turret);
			}
			else {
				it->second.update();
				camera->queueSprite(it->second);
			}
		}
		camera->draw();
	}
}


void Scene::addSprite(Sprite sprite)
{
	sprites.insert(std::pair<int, Sprite>(sprite.id, sprite));
}//adds a sprite into the mapping. Uses it's spriteID in order to map it. 


void Scene::delSprite(int id)
{
	sprites.erase(id);
}//removes a sprite based on it's ID in the mapping.


Sprite& Scene::getSprite(int id)
{
	return sprites.at(id);
}//get a sprite given it's ID in the mapping
