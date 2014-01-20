//INCLUDE GUARDS
#pragma once
#ifndef FTW_SPRITE_H
#define FTW_SPRITE_H

//INCLUDE
#include <stdio.h>
#include <string>
#include "SDL.h"

//INCLUDE RELATIVE
#include "texture.h"
#include "rect2.h"

//USING
using std::string;

//NAMESPACE
namespace ftw
{
	//SPRITE HEADER
	class Sprite
	{
	protected:

		//FIELDS
		rect2 pos;
		rect2 clip;
		Texture * tex;

	public:

		//CONSTRUCTORS
		Sprite();
		Sprite(const rect2 & pos);
		Sprite(const rect2 & pos, const rect2 & clip);
		Sprite(const rect2 & pos, const rect2 & clip, const string & tex);

		//DECONSTRUCTOR
		~Sprite();

		//RENDER
		virtual void Render();
	};
}

//END GUARDS
#endif