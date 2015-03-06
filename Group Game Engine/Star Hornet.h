#ifndef STAR_HORNET_H
#define STAR_HORNET_H

// Standard includes
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <SDL.h>

// SDL includes
#include "res_path.h"
#include "cleanup.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"


enum directions { LEFT, RIGHT, UP, DOWN };

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

#endif