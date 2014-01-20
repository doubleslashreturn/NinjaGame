//INCLUDE GUARDS
#pragma once
#ifndef FTW_TEXTURE_H
#define FTW_TEXTURE_H

//INCLUDE
#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

//INCLUDE RELATIVE
#include "global.h"
#include "surface.h"
#include "rect2.h"

//USING
using std::string;

//NAMESPACE
namespace ftw
{
	//TEXTURE HEADER
	class Texture
	{
	private:

		//FIELDS
		SDL_Texture * tex;
		int width;
		int height;

	public:

		//CONSTRUCTORS
		Texture();
		Texture(const string & filename);

		//DECONSTRUCTOR
		~Texture();

		//CREATE
		bool Create(const string & filename);

		//DESTORY
		void Destory();

		//PROPERTY WIDTH | HEIGHT
		int GetWidth() const;
		int GetHeight() const;

		//RENDER
		void Render(const rect2 & pos, const rect2 & clip);
	};
}

//END GUARDS
#endif