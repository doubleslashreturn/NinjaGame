//INCLUDE HEADER
#include "color.h"

//NAMESPACE
namespace ftw
{
	//CONSTRUCTORS
	color::color()
	{
		data.r = 0;
		data.g = 0;
		data.b = 0;
		data.a = 255;
	}

	color::color(Uint8 r, Uint8 g, Uint8 b)
	{
		data.r = r;
		data.g = g;
		data.b = b;
		data.a = 255;
	}

	color::color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		data.r = r;
		data.g = g;
		data.b = b;
		data.a = a;
	}

	//PROPERTY R | G | B | A
	Uint8 color::GetR() const { return data.r; }
	void color::SetR(Uint8 r) { data.r = r; }
	void color::SetR(float r) { data.r = clamp((int)(r * 255), 0, 255); }

	Uint8 color::GetG() const { return data.g; }
	void color::SetG(Uint8 g) { data.g = g; }
	void color::SetG(float g) { data.g = clamp((int)(g * 255), 0, 255); }

	Uint8 color::GetB() const { return data.b; }
	void color::SetB(Uint8 b) { data.b = b; }
	void color::SetB(float b) { data.b = clamp((int)(b * 255), 0, 255); }

	Uint8 color::GetA() const { return data.a; }
	void color::SetA(Uint8 a) { data.a = a; }
	void color::SetA(float a) { data.a = clamp((int)(a * 255), 0, 255); }

	//HANDLE
	const SDL_Color * color::Handle() const { return &data; }
}