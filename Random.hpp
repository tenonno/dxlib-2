#pragma once

#include <random>

inline std::mt19937 &MT19937()
{
	static std::random_device random;
	static std::mt19937 mt19937(random());
	return mt19937;
}



inline double Random(const double min, const double max)
{
	return std::uniform_real_distribution<double>(min, max)(MT19937());
}


inline double Random(const double range)
{
	return Random(-range, range);
}

template<typename T>
inline T Random2(T, T);


template<>
inline double Random2<double>(const double min, const double max)
{
	return std::uniform_real_distribution<double>(min, max)(MT19937());
}



template<>
inline int32 Random2<int32>(int32 min, int32 max)
{
	return std::uniform_int_distribution<int32>(min, max)(MT19937());
}
