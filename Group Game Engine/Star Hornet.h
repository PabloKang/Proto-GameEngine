#ifndef STAR_HORNET_H
#define STAR_HORNET_H

// Standard includes
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <SDL.h>

// SDL includes
//#include "res_path.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"


enum directions { LEFT, RIGHT, UP, DOWN };
enum message_type {USER_INPUT, COLLISION, INTERACTION};


// GAME HARDWARE
struct Hardware
{
public:
	SDL_Window*		window;
	SDL_Renderer*	renderer;
	std::string		resPath;
	int				screenWidth;
	int				screenHeight;

	Hardware(){}
	Hardware(SDL_Window* win, SDL_Renderer* ren, std::string res, int width, int height) 
		: window(win), renderer(ren), resPath(res), screenWidth(width), screenHeight(height){}
};


/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void logSDLError(std::ostream &os, const std::string &msg);

#endif