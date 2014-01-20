//INCLUDE HEADER
#include "keyboard.h"

//NAMESPACE
namespace ftw
{
	//CONSTRUCTOR
	Keyboard::Keyboard()
	{
		this->next = SDL_GetKeyboardState(&size);
		this->last = new Uint8[size];
		this->Update();
	}

	//DECONSTRUCTOR
	Keyboard::~Keyboard()
	{
		delete[] this->last;
		this->last = NULL;
		this->next = NULL;
	}

	//PRESS
	bool Keyboard::Press(Uint8 key) const { return next[key] && !last[key]; }

	//PRESSED
	bool Keyboard::Pressed(Uint8 key) const { return next[key] && last[key]; }

	//RELEASE
	bool Keyboard::Release(Uint8 key) const { return !next[key] && last[key]; }

	//RELEASED
	bool Keyboard::Released(Uint8 key) const { return !next[key] && !last[key]; }

	//UPDATE
	void Keyboard::Update()
	{
		memcpy(last, next, size);
		SDL_PumpEvents();
		next = SDL_GetKeyboardState(NULL);
	}
}