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
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#define RESOURCE_PATH	"Group Game Engine"
#define WIDTH_RATIO		0.75
#define HEIGHT_RATIO	0.75


enum directions { LEFT, RIGHT, UP, DOWN };
enum message_type {USER_INPUT, COLLISION, INTERACTION};

/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void logSDLError(std::ostream &os, const std::string &msg);


std::string exePath();

#endif