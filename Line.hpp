#pragma once
class Line
{
	Vec2 pos[2];
public:

	Line(const Vec2 &v1, const Vec2 &v2)
	{
		pos[0] = v1;
		pos[1] = v2;
	}


	void draw(const Color &color)
	{

		VERTEX2D vertices[2];

		for (auto &vertex : vertices)
		{
			vertex.rhw = 1;
			vertex.dif = color;
		}

		vertices[0].pos = Vec3(pos[0].x, pos[0].y, 0);
		vertices[1].pos = Vec3(pos[1].x, pos[1].y, 0);

		DrawPrimitive2D(vertices, 2, DX_PRIMTYPE_LINELIST, DX_NONE_GRAPH, false);

	}

	void draw(const Color &c1, const Color &c2)
	{

		VERTEX2D vertices[2];

		for (auto &vertex : vertices)
		{
			vertex.rhw = 1;
		}

		vertices[0].dif = c1;
		vertices[1].dif = c2;

		vertices[0].pos = Vec3(pos[0].x, pos[0].y, 0);
		vertices[1].pos = Vec3(pos[1].x, pos[1].y, 0);

		DrawPrimitive2D(vertices, 2, DX_PRIMTYPE_LINELIST, DX_NONE_GRAPH, false);

	}

};
