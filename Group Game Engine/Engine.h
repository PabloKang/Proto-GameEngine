#pragma once

#include "Star Hornet.h"


// GAME WINDOW AND RENDERER
SDL_Window* window;
SDL_Renderer *renderer;


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