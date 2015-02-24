#include <iostream>
#include <sstream>
#include <Windows.h>
#include <SDL.h>
#include "res_path.h"
#include "cleanup.h"
#include "SDL_image.h"
#include "Sprite.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 900;


/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void logSDLError(std::ostream &os, const std::string &msg){
	os << msg << " error: " << SDL_GetError() << std::endl;
	std::ostringstream errMsg;
	errMsg << " error: " << SDL_GetError() << std::endl;
	OutputDebugString(errMsg.str().c_str());
}

/**
* Loads an image into a texture on the rendering device
* @param file The image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren){
	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
	if (texture == nullptr){
		logSDLError(std::cout, "LoadTexture");
	}
	return texture;
}



bool Engine::init()
{

}



int Engine::exec(int argc, char **argv){

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::ostringstream debugMsg;
		debugMsg << "SDL_Init Error: " << SDL_GetError() << std::endl;
		OutputDebugString(debugMsg.str().c_str());
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
		logSDLError(std::cout, "IMG_Init");
		SDL_Quit();
		return 1;
	}

	////Initialize SDL
	//if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	//{
	//	logSDLError(std::cout, "VIDEO/AUDIO_Init");
	//	SDL_Quit();
	//	return 1;
	//}

	SDL_Window *window = SDL_CreateWindow("Sprite Demo", 800, 100, SCREEN_WIDTH,
		SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		logSDLError(std::cout, "CreateWindow");
		SDL_Quit();
		return 1;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		logSDLError(std::cout, "CreateRenderer");
		cleanup(window);
		SDL_Quit();
		return 1;
	}

	const std::string resPath = getResourcePath("SpriteDemo");

	// Load texture for background
	SDL_Texture *background = loadTexture(resPath + "castle.png", renderer);
	if (background == nullptr){
		cleanup(background, renderer, window);
		IMG_Quit();
		SDL_Quit();
		return 1;
	}

	Sprite* spriteBG = new Sprite(SCREEN_WIDTH, SCREEN_HEIGHT, renderer);
	spriteBG->setPos(0,0);
	spriteBG->setScale(1.1, 1.1);
	int bgFrame = spriteBG->makeFrame(background, 0, 0);

	// Load spritesheet texture for player sprite
	SDL_Texture *spritesheet = loadTexture(resPath + "link.png", renderer);
	if (spritesheet == nullptr){
		cleanup(spritesheet, renderer, window);
		IMG_Quit();
		SDL_Quit();
		return 1;
	}

	// Create the player sprite
	Sprite* sprite1 = new Sprite(90, 90, renderer);

	// Add frames into sprite1
	sprite1->addFrameToSequence("default", sprite1->makeFrame(spritesheet, 0, 0));	// Default left
	sprite1->addFrameToSequence("default", sprite1->makeFrame(spritesheet, 0, 90));	// Default right
	sprite1->addFrameToSequence("default", sprite1->makeFrame(spritesheet, 0, 180));// Default up
	sprite1->addFrameToSequence("default", sprite1->makeFrame(spritesheet, 0, 270));// Default down

	sprite1->addFrameToSequence("walk left", sprite1->makeFrame(spritesheet, 90, 0));
	sprite1->addFrameToSequence("walk left", sprite1->makeFrame(spritesheet, 180, 0));
	sprite1->addFrameToSequence("walk left", sprite1->makeFrame(spritesheet, 270, 0));
	sprite1->addFrameToSequence("walk left", sprite1->makeFrame(spritesheet, 360, 0));

	sprite1->addFrameToSequence("walk right", sprite1->makeFrame(spritesheet, 90, 90));
	sprite1->addFrameToSequence("walk right", sprite1->makeFrame(spritesheet, 180, 90));
	sprite1->addFrameToSequence("walk right", sprite1->makeFrame(spritesheet, 270, 90));
	sprite1->addFrameToSequence("walk right", sprite1->makeFrame(spritesheet, 360, 90));

	sprite1->addFrameToSequence("walk up", sprite1->makeFrame(spritesheet, 90, 180));
	sprite1->addFrameToSequence("walk up", sprite1->makeFrame(spritesheet, 180, 180));
	sprite1->addFrameToSequence("walk up", sprite1->makeFrame(spritesheet, 270, 180));
	sprite1->addFrameToSequence("walk up", sprite1->makeFrame(spritesheet, 360, 180));

	sprite1->addFrameToSequence("walk down", sprite1->makeFrame(spritesheet, 90, 270));
	sprite1->addFrameToSequence("walk down", sprite1->makeFrame(spritesheet, 180, 270));
	sprite1->addFrameToSequence("walk down", sprite1->makeFrame(spritesheet, 270, 270));
	sprite1->addFrameToSequence("walk down", sprite1->makeFrame(spritesheet, 360, 270));

	// Load sound files
	Mix_Chunk *walkingSound = NULL;
	walkingSound = Mix_LoadWAV("21_sound_effects_and_music/scratch.wav");
	if (walkingSound == NULL)
	{
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}


	int x = SCREEN_WIDTH / 2 ;
	int y = SCREEN_HEIGHT / 2;
	sprite1->setPos(x, y);

	SDL_Event e;
	bool quit = false;
	std::string spriteFrameSequence = "default";
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	// MAIN GAME LOOP -----------------------------------------
	while (!quit){

		// Poll all events in event queue
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			// Check all one-time keypress events
			if (e.type == SDL_KEYDOWN){
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
				if (e.key.keysym.sym == SDLK_r)
				{
					sprite1->setAngle(0.0);
				}
				if (e.key.keysym.sym == SDLK_KP_1)
				{
					sprite1->setScale(1.0, 1.0);
				}
			}
			if (e.type == SDL_KEYUP){
				spriteFrameSequence = "default";
			}
		}

		// Continuous-response (held down) keys
		if (currentKeyStates[SDL_SCANCODE_A])
		{
			sprite1->movex(-4);
			spriteFrameSequence = "walk left";
			Mix_PlayChannel(-1, walkingSound, 0);
		}
		if (currentKeyStates[SDL_SCANCODE_D])
		{
			sprite1->movex(4);
			spriteFrameSequence = "walk right";
		}
		if (currentKeyStates[SDL_SCANCODE_W])
		{
			sprite1->movey(-4);
			spriteFrameSequence = "walk up";
		}
		if (currentKeyStates[SDL_SCANCODE_S])
		{
			sprite1->movey(4);
			spriteFrameSequence = "walk down";
		}
		// Rotating
		if (currentKeyStates[SDL_SCANCODE_Q])
		{
			sprite1->rotate(-5);
		}
		if (currentKeyStates[SDL_SCANCODE_E])
		{
			sprite1->rotate(5);
		}
		// Scaling
		if (currentKeyStates[SDL_SCANCODE_LEFT])
		{
			sprite1->changeScale(-0.05, 0.00);
		}
		if (currentKeyStates[SDL_SCANCODE_RIGHT])
		{
			sprite1->changeScale(0.05, 0.00);
		}
		if (currentKeyStates[SDL_SCANCODE_UP])
		{
			sprite1->changeScale(0.00, 0.05);
		}
		if (currentKeyStates[SDL_SCANCODE_DOWN])
		{
			sprite1->changeScale(0.00, -0.05);
		}


		//Render the scene
		SDL_RenderClear(renderer);
		spriteBG->show(bgFrame);
		sprite1->show(spriteFrameSequence.c_str());
		SDL_RenderPresent(renderer);
	}

	cleanup(background, spritesheet, renderer, window);
	Mix_FreeChunk(walkingSound);
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();

	SDL_Quit();

	return 0;
}
