//INCLUDE GUARDS
#pragma once
#ifndef GAME_HELPERS_H
#define GAME_HELPERS_H

//NAMESPACE
namespace helper
{
	template<typename T>
	inline T const & min(T const & a, T const & b)
	{ return a < b ? a : b; }

	template<typename T>
	inline T const & max(T const & a, T const & b)
	{ return a < b ? b : a; }

	template<typename T>
	inline T const & clamp(T const & val, T const & min, T const & max)
	{ return val < min ? min : val > max ? max : val; }

	template<typename T>
	inline T const & lerp(T const & v1, T const & v2, T const & t)
	{ return v1 + ((v2 - v1) * t); }

	template<typename T>
	inline T const & barycentric(T const & v1, T const & v2, T const & v3, T const & t1, T const & t2)
	{ return v1 + ((v2 - v1) * t1) + ((v3 - v1) * t2); }
}

//END GUARDS
#endif