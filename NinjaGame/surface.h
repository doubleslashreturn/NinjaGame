//INCLUDE GUARDS
#pragma once
#ifndef FTW_SURFACE_H
#define FTW_SURFACE_H

//INCLUDE
#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

//INCLUDE RELATIVE
#include "global.h"

//USING
using std::string;

//NAMESPACE
namespace ftw
{
	//SURFACE HEADER
	class Surface
	{
	private:

		//FIELDS
		SDL_Surface * surf;
		int width;
		int height;

	public:

		//CONSTRUCTORS
		Surface();
		Surface(const string & filename);

		//DECONSTRUCTOR
		~Surface();

		//PROPERTY WIDTH | HEIGHT
		int GetWidth() const;
		int GetHeight() const;

		//CREATE
		bool Create(const string & filename);

		//CREATE TEXTURE
		SDL_Texture * CreateTexture();

		//DESTORY
		void Destory();

		//RENDER
		void Render();
	};
}

//END GUARDS
#endif