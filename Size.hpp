#pragma once

template<typename type = int32>
struct Size
{
	type width, height;

	Size() : width(0), height(0)
	{

	}

	Size(const type width, const type height) : width(width), height(height)
	{

	}


	Size<type> operator*(const double value) const
	{
		return Size<type>(width * value, height * value);
	}

	void operator/=(const double value) const
	{
		width /= value;
		height /= value;
	}

};

using SizeF = Size<double>;
