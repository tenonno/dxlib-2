#pragma once
class Line3D
{

	Vec3 pos[2];

public:

	Line3D(const Vec3 &pos1, const Vec3 &pos2) : pos{ pos1, pos2 }
	{
	}


	void draw(const Color &color)
	{
		DrawLine3D(pos[0], pos[1], color);
	}


};
