#pragma once

using color_code = unsigned int;



struct Color
{

	double r, g, b, a;

	Color()  {}

	Color(const double r, const double g, const double b, const double a = 1.0) : r(r), g(g), b(b), a(a) {}
	Color(const double color, const double a = 1.0) : r(color), g(color), b(color), a(a) {}

	operator color_code() const
	{
		return GetColor(ToInt8(r), ToInt8(g), ToInt8(b));
	}

	operator COLOR_U8() const
	{
		return GetColorU8(ToInt8(r), ToInt8(g), ToInt8(b), ToInt8(a));
	}

};


struct ColorX16
{
	uint8 r, g, b, a;

	ColorX16(const uint8 r, const uint8 g, const uint8 b, const uint8 a = 0xff) : r(r), g(g), b(b), a(a) {}




};

