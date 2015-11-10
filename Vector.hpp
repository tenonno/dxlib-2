#pragma once

enum _Vec
{
	_x, _y, _z, _w, _xy, _xz
};

struct Vec2
{
	double x, y;

	Vec2() {}
	Vec2(const double x, const double y) : x(x), y(y) {}


	Vec2 operator+(const Vec2 &vec)const
	{
		return Vec2(x + vec.x, y + vec.y);
	}

	Vec2 operator-(const Vec2 &vec) const
	{
		return Vec2(x - vec.x, y - vec.y);
	}

};



struct __vec3
{

	union
	{
		double x, y, z;

	};

};

struct Vec3
{
	double x, y, z;

	Vec3() : x(0), y(0), z(0) {}


	Vec2 xy() { return Vec2(x, y); }
	Vec2 xz() { return Vec2(x, z); }




	Vec3(const double x, const double y) : x(x), y(y), z(0)
	{

	}
	Vec3(const VECTOR &vec) : x(vec.x), y(vec.y), z(vec.z)
	{

	}

	/// <summary> 
	Vec3(const double value) : x(value), y(value), z(value) {}

	Vec3(const double x, const double y, const double z) : x(x), y(y), z(z)
	{

	}

	Vec3 &normalize()
	{
		return *this = VNorm(*this);
	}

	Vec3 transform(const Matrix &mat)
	{
		return VTransform((VECTOR)*this, mat);
	}

	operator VECTOR_D() const
	{
		return VGetD(x, y, z);
	}

	operator VECTOR() const
	{
		return VConvDtoF(*this);
	}

	Vec3 operator-(const Vec3 &vec) const
	{
		return Vec3(x - vec.x, y - vec.y, z - vec.z);
	}

	Vec3 operator+(const Vec3 &vec) const
	{
		return Vec3(x + vec.x, y + vec.y, z + vec.z);
	}

	Vec3 operator+=(const Vec3 &vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}

	Vec3 operator*(const double value)const
	{
		return Vec3(x * value, y * value, z * value);
	}

	Vec3 operator*=(const Vec3 &vec)
	{
		x *= vec.x;
		y *= vec.y;
		z *= vec.z;
		return *this;
	}

	Vec3 operator*=(const double value)
	{
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	Vec3 operator/(const double value)
	{
		return Vec3(x / value, y / value, z / value);
	}

	Vec3 operator/=(const double value)
	{
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

};


struct VectorConvert
{

	static Vec3 ToScreen(const Vec3 &world)
	{
		return ConvWorldPosToScreenPos(world);
	}



};

//ConvScreenPosToWorldPos




struct UV
{
	double u, v;

	UV(const double u, const double v) : u(u), v(v)
	{}


	UV() {}

	operator Vec2()
	{
		return Vec2(u, v);
	}

};


void operator+=(VECTOR &v1, VECTOR &v2)
{
	v1 = VAdd(v1, v2);
}
