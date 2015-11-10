#pragma once
struct Rect
{
	double x, y, width, height;


	// default constracter
	Rect() : x(0), y(0), width(0), height(0) {}

	Rect(const double x, const double y, const double width, const double height) : x(x), y(y), width(width), height(height)
	{

	}

	Vec2 center() const
	{
		return Vec2(x + width / 2, y + height / 2);
	}

	Size<double> size() const
	{
		return Size<double>(width, height);
	}

	Vec2 pos() const
	{
		return Vec2(x, y);
	}

	Rect &padding(const double x, const double y)
	{
		this->x += x;
		this->y += y;
		width -= x * 2;
		height -= y * 2;
		return *this;
	}

};
