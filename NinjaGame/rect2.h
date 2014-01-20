//INCLUDE GUARDS
#pragma once
#ifndef FTW_RECT2_H
#define FTW_RECT2_H

//INCLUDE
#include <iostream>
#include "SDL.h"

//INCLUDE RELATIVE
#include "vec2.h"

//USING
using std::ostream;

//NAMESPACE
namespace ftw
{
	//RECTANGLE2 HEADER
	struct rect2
	{
	private:

		//FIELDS
		SDL_Rect data;

	public:

		//CONSTRUCTORS
		rect2();
		rect2(int x, int y);
		rect2(int x, int y, int w, int h);

		//PREDEFINED VALUES
		static const rect2 rect2::Empty() { return rect2(); }

		//FRIEND OPERATIONS
		friend ostream & rect2::operator << (ostream & os, const rect2 & r)
		{ return os << "[" << r.data.x << ", " << r.data.y << ", " << r.data.w << ", " << r.data.h << "]"; }

		//SDL RECTANGLE HANDLE
		const SDL_Rect * Handle() const;

		//PROPERTY X | Y
		int GetX() const; void SetX(int x);
		int GetY() const; void SetY(int y);

		//PROPERTY POSITION VECTOR
		const vec2 GetPosition() const;
		void SetPosition(int x, int y);
		void SetPosition(const vec2 & pos);


		//PROPERTY WIDTH | HEIGHT
		int GetW() const; void SetW(int w);
		int GetH() const; void SetH(int h);

		//PROPERTY DIMENSION VECTOR
		const vec2 GetDimension() const;
		void SetDimension(int w, int h);
		void SetDimention(const vec2 & dim);
	};
}

//END GUARDS
#endif