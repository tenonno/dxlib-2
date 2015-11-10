#pragma once

#include <sstream>

template<typename T, typename... Args>
void Format(std::wstringstream &stream, const T value, const Args... args)
{

	stream << value;

	Format(stream, args...);

}

template<typename T>
void Format(std::wstringstream &stream, const T value)
{
	stream << value;
}


template<typename... Args>
String Format(const Args... args)
{

	std::wstringstream stream;

	Format(stream, args...);

	return stream.str();
}
