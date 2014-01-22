//INCLUDE GUARDS
#pragma once
#ifndef FTW_GAME_H
#define FTW_GAME_H

//INCLUDE
#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

//INCLUDE RELATIVE
#include "global.h"
#include "keyboard.h"

//USING
using std::string;

//NAMESPACE
namespace ftw
{
	//GAME HEADER
	class Game
	{
	private:

		//FIELDS
		string name;
		int width;
		int height;

		//CHECK FIELDS
		bool gameover;
		bool initializedSDL;
		bool initialized;
		bool loaded;

		//INIT SDL
		bool InitSDL();

		//QUIT SDL
		void QuitSDL();

	protected:

		//INITIALIZE
		virtual bool Init();

		//LOAD
		virtual bool Load();

		//UPDATE
		virtual void Update();

		//RENDER
		virtual void Render();

		//UNLOAD
		virtual bool Unload();

	public:

		//CONSTRUCTOR
		Game();
		Game(const string & name);
		Game(const string & name, int width, int height);

		//DECONSTRUCTOR
		virtual ~Game();

		//RUN
		int Run();
	};
}

//END GUARDS
#endif