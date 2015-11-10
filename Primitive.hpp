#pragma once

struct Vertex3D : public VERTEX3D
{

	void setPos(const Vec3 &pos)
	{
		this->pos = (VECTOR)pos;
	}

	void setUV(const UV &uv)
	{
		u = (float)uv.u;
		v = (float)uv.v;
	}


};




class Primitive
{
protected:
	std::vector<VERTEX3D> vertices;

	uint32 type = DX_PRIMTYPE_TRIANGLESTRIP;

public:



	/// <summary> プリミティブの中心を取得します </summary>
	Vec3 center()
	{
		Vec3 center(0);

		for (const auto &vertex : vertices)
		{
			center += vertex.pos;
		}

		return center / vertices.size();
	}

	/// <summary> 頂点の平均ベクトルを取得します </summary>
	Vec3 average(std::initializer_list<uint32> indexes)
	{
		Vec3 total;

		for (uint32 index : indexes)
		{
			total += vertices[index].pos;
		}

		return total / indexes.size();
	}


	/// <summary> スケールを設定します </summary>
	Primitive &scale(const Vec3 &scale)
	{
		for (auto &vertex : vertices)
		{
			vertex.pos.x *= (float)scale.x;
			vertex.pos.y *= (float)scale.y;
			vertex.pos.z *= (float)scale.z;
		}

		return *this;
	}

	/// <summary> 頂点色を指定します </summary>
	void color(const Color &color)
	{
		for (auto &vertex : vertices)
		{
			vertex.dif = color;
		}
	}

	Vec3 max()
	{
		Vec3 max(0);

		for (const auto &vertex : vertices)
		{

			max.x = std::max<double>(max.x, vertex.pos.x);
			max.y = std::max<double>(max.y, vertex.pos.y);
			max.z = std::max<double>(max.z, vertex.pos.z);
		}

		return max;
	}

	/// <summary> 全ての頂点に UV を加算します</summary>
	void addUV(UV uv)
	{
		for (auto &vertex : vertices)
		{
			vertex.u += (float)uv.u;
			vertex.v += (float)uv.v;
		}
	}

	void draw(const Texture &tex)
	{

		DrawPrimitive3D(&vertices[0], vertices.size(), type, tex.getHandle(), true);

	}

	/// <summary> TextureAsset を使用して描画します </summary>
	void draw(const String &name)
	{
		draw(TextureAsset2(name)());
	}

	/// <summary> 色を指定して描画します </summary>
	void draw(const Color &color)
	{
		this->color(color);

		DrawPrimitive3D(&vertices[0], vertices.size(), type, DX_NONE_GRAPH, false);

		this->color(Color(1));
	}

	Vec3 vertex(const uint32 index)
	{
		return vertices[index].pos;
	}

	Primitive &transform(const Matrix &mat)
	{


		for (auto &vertex : vertices)
		{

			vertex.pos = VTransform(vertex.pos, mat);

		}

		return *this;

	}
	void move(Vec3 &vec)
	{

		for (auto &vertex : vertices)
		{
			vertex.pos += (VECTOR)vec;
		}

	}


};