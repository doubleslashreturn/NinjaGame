//INCLUDE GUARDS
#pragma once
#ifndef FTW_COLOR_H
#define FTW_COLOR_H

//INLCUDE
#include <iostream>
#include "SDL.h"

//INCLUDE RELATIVE
#include "helpers.h"

//USING
using std::ostream;
using helper::clamp;

//NAMESPACE
namespace ftw
{
	//COLOR HEADER
	class color
	{
	private:

		//FIELDS
		SDL_Color data;

	public:

		//CONSTRUCTORS
		color();
		color(Uint8 r, Uint8 g, Uint8 b);
		color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

		//PREDEFINED VALUES
		static const color Black() { return color(0, 0, 0); }
		static const color Red() { return color(255, 0, 0); }
		static const color Green() { return color(0, 255, 0); }
		static const color Blue() { return color(0, 0, 255); }
		static const color White() { return color(255, 255, 255); }

		//FRIEND FUNCTION
		friend ostream & operator << (ostream & os, const color & c)
		{ return os << "[" << int(c.data.r) << ", " << (int)c.data.g << ", " << (int)c.data.b << ", " << (int)c.data.a << "]"; }

		//PROPERTY R | G | B | A
		Uint8 GetR() const; void SetR(Uint8 r); void SetR(float r);
		Uint8 GetG() const; void SetG(Uint8 g); void SetG(float g);
		Uint8 GetB() const; void SetB(Uint8 b); void SetB(float b);
		Uint8 GetA() const; void SetA(Uint8 a); void SetA(float a);

		//HANDLE
		const SDL_Color * Handle() const;
	};
}

//END GUARDS
#endif