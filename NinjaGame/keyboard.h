//INCLUDE GUARDS
#pragma once
#ifndef FTW_KEYBOARD_H
#define FTW_KEYBOARD_H

//INCLUDE
#include <iostream>
#include <stdio.h>
#include "SDL.h"

//USING

//NAMESPACE
namespace ftw
{
	//KEYBOARD HEADER
	class Keyboard
	{
	private:

		//FIELDS
		const Uint8 * next;
		Uint8 * last;
		int size;

	public:

		//CONSTRUCTOR
		Keyboard();

		//DECONSTRUCTOR
		~Keyboard();

		//PRESS
		bool Press(Uint8 key) const;

		//PRESSED
		bool Pressed(Uint8 key) const;

		//RELEASE
		bool Release(Uint8 key) const;

		//RELEASED
		bool Released(Uint8 key) const;

		//UPDATE
		void Update();
	};
}

//END GUARDS
#endif