//INCLUDE HEADER
#include "rect2.h"

//NAMESPACE
namespace ftw
{
	//CONSTRUCTORS
	rect2::rect2()
	{
		data.x = data.y = 0;
		data.w = data.h = 0;
	}

	rect2::rect2(int x, int y)
	{
		data.x = x;
		data.y = y;
		data.w = data.h = 0;
	}

	rect2::rect2(int x, int y, int w, int h)
	{
		data.x = x;
		data.y = y;
		data.w = w;
		data.h = h;
	}

	//SDL RECTANGLE HANDLE
	const SDL_Rect * rect2::Handle() const { return &data; }

	//PROPERTY X | Y
	int rect2::GetX() const { return data.x; }
	void rect2::SetX(int x) { data.x = x; }
	int rect2::GetY() const { return data.y; }
	void rect2::SetY(int y) { data.y = y; }

	//PROPERTY POSITION VECTOR
	const vec2 rect2::GetPosition() const { return vec2((float)data.x, (float)data.y); }
	void rect2::SetPosition(int x, int y) { data.x = x; data.y = y; }
	void rect2::SetPosition(const vec2 & pos) { data.x = (int)pos.x; data.y = (int)pos.y; }

	//PROPERTY WIDTH | HEIGHT
	int rect2::GetW() const { return data.w; }
	void rect2::SetW(int w) { data.w = w; }
	int rect2::GetH() const { return data.h; }
	void rect2::SetH(int h) { data.h = h; }

	//PROPERTY DIMENSION VECTOR
	const vec2 rect2::GetDimension() const { return vec2((float)data.w, (float)data.h); }
	void rect2::SetDimension(int w, int h) { data.w = w; data.h = h; }
	void rect2::SetDimention(const vec2 & dim) { data.w = (int)dim.x; data.h = (int)dim.y; }
}