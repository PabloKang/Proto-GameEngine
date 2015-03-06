#ifndef ENGINE_H
#define ENGINE_H

#include "Star Hornet.h"

// GAME HARDWARE
struct Hardware 
{
public:
	SDL_Window *window;
	SDL_Renderer* renderer;
};

Hardware hardware;


class Engine
{
public:
	std::string resPath;

	// Engine State Data


	// Engine Constructors
	Engine(SDL_Window* win, SDL_Renderer *ren);
	~Engine();

	// Engine Functions
	bool	init();
	int		exec();
};

#endif