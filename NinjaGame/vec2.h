//INCLUDE GUARDS
#pragma once
#ifndef FTW_VEC2_H
#define FTW_VEC2_H

//INCLUDE
#include <iostream>
//#include <math.h>
#include <float.h>

//INCLUDE RELATIVE
#include "helpers.h"

//USING
using std::ostream;
using namespace helper;

//NAMESPACE
namespace ftw
{
	//vec2 HEADER
	struct vec2
	{
	public:

		//FIELDS
		float x, y;

		//CONSTRUCTORS
		vec2();
		vec2(float s);
		vec2(float x, float y);

		//MEMBER METHODS
		float LengthSq() const;
		float Length() const;
		const vec2 Skew();
		const vec2 Normalize();

		//PREDEFINED VALUES
		static const vec2 Zero()  { return vec2(0, 0); }
		static const vec2 One()   { return vec2(1, 1); }
		static const vec2 Unitx() { return vec2(1, 0); }
		static const vec2 Unity() { return vec2(0, 1); }

		//ASSINGMENT OPERATIONS
		vec2 & operator = (const vec2 & v) { x = v.x; y = v.y; return *this; }
		vec2 & operator = (const float & s) { x = s; y = s; return *this; }
		vec2 & operator - (void) { x = -x; y = -y; return *this; }

		//EQUALITY OPERATIONS
		bool operator == (const vec2 & v) const { return (x == v.x) && (y == v.y); }
		bool operator != (const vec2 & v) const { return !(*this == v); }

		//VECTOR TO THIS OPERATIONS
		vec2 & operator += (const vec2 & v) { x += v.x; y += v.y; return *this; }
		vec2 & operator -= (const vec2 & v) { x -= v.x; y -= v.y; return *this; }
		vec2 & operator *= (const vec2 & v) { x *= v.x; y *= v.y; return *this; }
		vec2 & operator /= (const vec2 & v) { x /= v.x; y /= v.y; return *this; }

		//VEC2 TO VEC2 OPERATIONS
		const vec2 operator + (const vec2 & v) const { vec2 r(*this); return r += v; }
		const vec2 operator - (const vec2 & v) const { vec2 r(*this); return r -= v; }
		const vec2 operator * (const vec2 & v) const { vec2 r(*this); return r *= v; }
		const vec2 operator / (const vec2 & v) const { vec2 r(*this); return r /= v; }

		//SCALER TO THIS OPERATIONS
		vec2 & operator += (const float & s) { x += s; y += s; return *this; }
		vec2 & operator -= (const float & s) { x -= s; y -= s; return *this; }
		vec2 & operator *= (const float & s) { x *= s; y *= s; return *this; }
		vec2 & operator /= (const float & s) { x /= s; y /= s; return *this; }

		//SCALER TO VEC2 OPERATIONS
		const vec2 operator + (const float & s) const { vec2 r(*this); return r += s; }
		const vec2 operator - (const float & s) const { vec2 r(*this); return r -= s; }
		const vec2 operator * (const float & s) const { vec2 r(*this); return r *= s; }
		const vec2 operator / (const float & s) const { vec2 r(*this); return r /= s; }

		//FRIEND OPERATIONS
		friend ostream & operator << (ostream & os, const vec2 & v)
		{ return os << "{" << v.x << ", " << v.y << "}"; }

		//STATIC ARITHMETIC
		static const vec2 Add (const vec2 & v1, const vec2 & v2) { return v1 + v2; }
		static const vec2 Sub (const vec2 & v1, const vec2 & v2) { return v1 - v2; }
		static const vec2 Mul (const vec2 & v1, const vec2 & v2) { return v1 * v2; }
		static const vec2 Div (const vec2 & v1, const vec2 & v2) { return v1 / v2; }

		static float DistanceSq (const vec2 & v1, const vec2 & v2)
		{ return (((v1.x - v2.x) * (v1.x - v2.x)) + ((v1.y - v2.y) * (v1.y - v2.y))); }

		static float Distance (const vec2 & v1, const vec2 & v2)
		{ return sqrt(DistanceSq(v1, v2)); }

		static float Dot (const vec2 & v1, const vec2 & v2)
		{ return ((v1.x * v2.x) + (v1.y * v2.y)); }

		static const vec2 Min (const vec2 & v1, const vec2 & v2)
		{ return vec2(::min(v1.x, v2.x), ::min(v1.y, v2.y)); }

		static const vec2 Max (const vec2 & v1, const vec2 & v2)
		{ return vec2(::max(v1.x, v2.x), ::max(v1.y, v2.y)); }

		static const vec2 Clamp (const vec2 & v, const vec2 & min, const vec2 & max)
		{ return vec2(::clamp(v.x, min.x, max.x), ::clamp(v.y, min.y, max.y)); }

		static const vec2 Lerp (const vec2 & v1, const vec2 & v2, float t)
		{ return vec2(::lerp(v1.x, v2.x, t), ::lerp(v1.y, v2.y, t)); }

		static const vec2 Barycentric (const vec2 & v1, const vec2 & v2, const vec2 & v3, float t1, float t2)
		{ return vec2(::barycentric(v1.x, v2.x, v3.x, t1, t2), ::barycentric(v1.y, v2.y, v3.y, t1, t2)); }
	};
}

//END GUARDS
#endif