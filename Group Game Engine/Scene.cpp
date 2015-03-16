#include "Scene.h"
#include "Camera.h"
#include "Player.h"
#include "Projectile.h"


Scene::Scene()
{
	sceneName = "Scene";

	std::vector<Entity*> shipEnts;
	std::vector<Entity*> bulEnts;

	collidables.insert(std::pair<std::string, std::vector<Entity*>>("Ally", shipEnts));
	collidables.insert(std::pair<std::string, std::vector<Entity*>>("Enemy", bulEnts));
}

//change everytyhing to using a map.
Scene::Scene(Camera* cam, SoundManager* smr) : camera(cam), sp(smr), sm(smr)
{
	sceneName = "Scene";

	std::vector<Entity*> shipEnts;
	std::vector<Entity*> bulEnts;

	collidables.insert(std::pair<std::string, std::vector<Entity*>>("Ally", shipEnts));
	collidables.insert(std::pair<std::string, std::vector<Entity*>>("Enemy", bulEnts));
}


Scene::~Scene(){

}


void Scene::init(Camera* cam, SoundManager* sm)
{
	camera = cam;
	loadSound("shot", exePath() + "\\Resources\\Audio\\shot.wav");
	loadMusic("spaceTunes", exePath() + "\\Resources\\Audio\\space.mp3");
	// LOAD TEXTURES:
	spriteManager.add_texture("hornet", spriteManager.loadTexture("hornet_body_spritesheet.gif", camera->renderer));
	spriteManager.add_texture("background", spriteManager.loadTexture("background.gif", camera->renderer));
	spriteManager.add_texture("turret", spriteManager.loadTexture("hornet_turret_small.gif", camera->renderer));
	spriteManager.add_texture("bullet", spriteManager.loadTexture("turret_bullet.gif", camera->renderer));

	// INITIALIZE SPRITES:
	//background
	background = Sprite(0.0f, 0.0f, SDL_Rect{ 0, 0, camera->width, camera->height }, camera->renderer, sm);
	background.addFrameToSequence("default", background.makeFrame(spriteManager.get_texture("background"), -1, 1));
	//player
	hornet = Player(1.0f, 1.0f, "Ally", spriteManager.get_texture("hornet"), SDL_Rect{ camera->width / 2, camera->height / 2, 128, 128 }, SDL_Rect{ camera->width / 2, camera->height / 2, 128, 128 }, camera->renderer, sm);
	hornet.turret = Sprite(1.1f, 1.1f, SDL_Rect{ camera->width / 2, camera->height / 2, 128, 128 }, camera->renderer, sm);
	hornet.turret.center = { 128 * (70.5 / 128.f), 64 };
	hornet.turret.addFrameToSequence("default", hornet.turret.makeFrame(spriteManager.get_texture("turret"), 0, 0));
	addCollidable(&hornet);
}


std::string Scene::exec()
{
	SDL_Event e;
	bool quit = false;
	int cooldown = 0;
	playMusic("spaceTunes",-1);

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
			// Player commands while their ship is alive
			if (hornet.alive) {
				if (currentKeyStates[SDL_SCANCODE_SPACE] && cooldown > 5) {
					float bullID = 2.0f + (0.0001 * (bullets.size() + 1));
					SDL_Rect bullRect{ hornet.turret.spriteRect.x + hornet.turret.center.x - 6, hornet.turret.spriteRect.y + hornet.turret.center.y - 6, 12, 12 };
					Projectile* bullet = new Projectile(bullID, 2.0f, "Ally", spriteManager.get_texture("bullet"), bullRect, bullRect, 20, hornet.turret.angle, camera->renderer);
					bullets.insert(std::pair<float, Projectile>(bullID, *bullet));
					addCollidable(bullet);
					playSound("shot", 0);
					cooldown = 0;
				}
				else{
					cooldown++;
				}
			}
		}

		// Update and render the scene
		update();
		SDL_RenderPresent(camera->renderer);

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


void Scene::delCollidable(std::string type, float entID)
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
	for (unsigned int i = 0; i < collidables.at("Ally").size(); i++)
	{
		for (unsigned int j = 0; j < collidables.at("Enemy").size(); j++)
		{
			Entity* currAlly = collidables.at("Ally").at(i);
			Entity* currEnemy = collidables.at("Enemy").at(j);

			int allyLeft = currAlly->hitBox.x,
				allyRight = currAlly->hitBox.x + currAlly->hitBox.w,
				allyTop = currAlly->hitBox.y,
				allyBottom = currAlly->hitBox.y + currAlly->hitBox.h;

			int enemyLeft = currEnemy->hitBox.x,
				enemyRight = currEnemy->hitBox.x + currEnemy->hitBox.w,
				enemyTop = currEnemy->hitBox.y,
				enemyBottom = currEnemy->hitBox.y + currEnemy->hitBox.h;

			if ((allyLeft <= enemyRight && allyRight >= enemyLeft) && (allyTop <= enemyBottom && allyBottom >= enemyTop))
			{
				currAlly->curHealth -= currEnemy->maxHealth;
				currEnemy->curHealth -= currAlly->maxHealth;
				
				if (currAlly->curHealth <= 0) {
					currAlly->alive = false;
					delCollidable(currAlly->entityType, currAlly->id);
					// TODO - Render explosion ////////////////////////////////////////////////////////////
				}
				if (currEnemy->curHealth <= 0) {
					currEnemy->alive = false;
					delCollidable(currEnemy->entityType, currEnemy->id);
					// TODO - Render explosion ////////////////////////////////////////////////////////////
				}
				std::cout << "OUCH!!\n";
			}
		}
	}

}


void Scene::update() 
{
	// Check for collisions
	collisionDetection();

	// LAYER 0: Background
	background.draw("default");

	// LAYER 1: Player
	if (hornet.alive) {
		hornet.update(currentKeyStates);
		hornet.draw();
	}

	// LAYER 2: Projectiles
	if (!bullets.empty())
	{
		typedef std::map<float, Projectile> bulletMap;
		for (bulletMap::iterator it = bullets.begin(); it != bullets.end(); ++it) {
			it->second.update();
			it->second.draw("default");
		}
	}

	// Draw the camera
	camera->draw();
}


void Scene::loadSound(std::string soundname, std::string filename)
{
	sm->loadSound(soundname, filename);
}
void Scene::playSound(std::string soundstring, int repeat)
{
	sp.playSound(soundstring, repeat);
}

void Scene::loadMusic(std::string musicname, std::string filename)
{
	sm->loadMusic(musicname, filename);
}
void Scene::playMusic(std::string musicstring, int repeat)
{
	sp.changeVolume(10);
	sp.playMusic(musicstring, repeat);
}