//INCLUDE GUARDS
#pragma once
#ifndef FTW_GLOBAL_H
#define FTW_GLOBAL_H

//INCLUDE
#include <string>
#include "SDL.h"

//USING
using std::string;

//NAMESPACE
namespace ftw
{
	//FTW GLOBAL CONSTANTS
	extern const string GAME_NAME;
	extern const int RES_W;
	extern const int RES_H;

	//FTW GLOBAL POINTERS
	extern SDL_Window * window;
	extern SDL_Renderer * device;
}

//END GUARDS
#endif