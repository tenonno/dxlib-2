#pragma once

#include <boost/algorithm/clamp.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <boost/lexical_cast.hpp>



template<typename T, typename V>
inline T Cast(const V value) 
{
	return boost::lexical_cast<T>(value);
}

template<typename T>
inline String Join(const T &vec, const String &delim)
{
	String result;
	for (auto &_vec : vec)
	{
		if (!result.empty()) result += delim;

		result += ToString(_vec);
	}
	return result;
}



template<typename T>
inline T Clamp(const T value, const T min, const T max)
{
	return std::min(std::max(min, value), max);
}



int32 ToInt8(const double value)
{
	return static_cast<int32>(Clamp(value, 0.0, 1.0) * 255.0);
}




inline auto Rep(const int32 n)
{
	return boost::irange(0, n);
}

inline auto Rep(const int32 begin, const uint32 n)
{
	return boost::irange<uint32>(begin, begin + n);
}


/// <summary> ’l‚ª”ÍˆÍ“à‚ÉŽû‚Ü‚Á‚Ä‚¢‚é‚©Šm”F‚µ‚Ü‚· </summary>
template<typename range, typename type>
bool InRange(const range &range, const type &value)
{
	return range.begin <= value && range.end >= value;
}

