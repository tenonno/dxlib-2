#pragma once
class Box
{
	Vec2 min, max;
public:


	Box(const Rect &rect)
	{
		min = Vec2(rect.x, rect.y);
		max = min + Vec2(rect.width, rect.height);
	}

	Box &padding(const double padding)
	{
		min.x += padding;
		min.y += padding;
		max.x -= padding * 2;
		max.y -= padding * 2;
		return *this;
	}

	Box(const Vec2 &min, const Vec2 &max) : min(min), max(max)
	{
	}

	Box(const Vec2 &pos, const Size<double> &size)
	{
		min = pos;
		max = Vec2(pos.x + size.width, pos.y + size.height);
	}


	Box(const Vec2 &center, const double width, const double height)
	{
		min = center - Vec2(width / 2, height / 2);
		max = center + Vec2(width / 2, height / 2);

	}
	Box(const double x, const double y, const double width, const double height)
	{
		min = Vec2(x, y);
		max = Vec2(x + width, y + height);

	}


	void draw(const Color &color)
	{
		VERTEX2D vertices[4];


		for (auto &vertex : vertices)
		{
			vertex.rhw = 1;
			vertex.dif = color;
		}

		vertices[0].pos = Vec3(max.x, max.y, 0);
		vertices[1].pos = Vec3(max.x, min.y, 0);
		vertices[2].pos = Vec3(min.x, max.y, 0);
		vertices[3].pos = Vec3(min.x, min.y, 0);

		DrawPrimitive2D(vertices, 4, DX_PRIMTYPE_TRIANGLESTRIP, DX_NONE_GRAPH, false);


	}

};
