//INCLUDE HEADER
#include "vec2.h"

//NAMESPACE
namespace ftw
{
	//CONSTRUCTOR
	vec2::vec2() : x(0), y(0) { }
	vec2::vec2(float s) : x(s), y(s) { }
	vec2::vec2(float x, float y) : x(x), y(y) { }

	//LENGTH SQUARED
	float vec2::LengthSq() const { return ((x * x) + (y * y)); }

	//LENGTH
	float vec2::Length() const { return sqrt(LengthSq()); }

	//SKEW PRODUCT
	const vec2 vec2::Skew() { x -= y; y += x; x -= y; return vec2(*this); }

	//NORMALIZE
	const vec2 vec2::Normalize()
	{
		float len = LengthSq();
		if(len < FLT_EPSILON)
		{
			x = y = 0.0f;
			return vec2(*this);
		}
		else
		{
			float invLen = sqrt(len);
			x *= invLen;
			y *= invLen;
			return vec2(*this);
		}
	}
}