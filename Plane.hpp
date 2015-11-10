#pragma once


enum class Axis
{
	X, Y, Z

};


class Plane : public Primitive
{


public:


	Plane(const Rect &rect, const Axis axis)
	{

		if (axis == Axis::Z)
		{

			auto center = rect.center();
			*this = Plane(Vec3(center.x, 0, center.y), rect.size());
		}
		// 未実装
		else
		{
			MessageBox::Show(L"plane2 axis error");
		}

	}

	Plane(const Vec3 &pos, const Size<double> &size, const Axis axis)
	{



	}



	/// <summary> UV.v の範囲を設定します </summary>
	void uvRangeV(const double min, const double max) {

		vertices[0].v = vertices[2].v = (float)min;
		vertices[1].v = vertices[3].v = (float)max;
	}

	/// <summary> ２つのベクトルと横幅から板を生成します </summary>
	Plane(const Vec3 &_v1, const Vec3 &_v2, const double thick)
	{

		auto v1 = _v1;
		auto v2 = _v2;

		if (v1.z > v2.z)
		{
			std::swap(v1, v2);
		}



		VERTEX3D vertex;
		vertex.dif = Color(1);
		vertex.spc = Color(0);

		Vec3 _thick(thick / 2, 0, 0);

		// 1
		vertex.pos = v1 + _thick;
		vertex.u = vertex.v = 1;
		vertices.emplace_back(vertex);

		// 2
		vertex.pos = v2 + _thick;
		vertex.u = 1, vertex.v = 0;
		vertices.emplace_back(vertex);

		// 3
		vertex.pos = v1 - _thick;
		vertex.u = 0, vertex.v = 1;
		vertices.emplace_back(vertex);

		// 4
		vertex.pos = v2 - _thick;
		vertex.u = vertex.v = 0;
		vertices.emplace_back(vertex);
	}


	/// <summary> ２つのベクトルと２つの横幅から板を生成します </summary>
	/// <param name="t1"> 上部の太さ </param>
	Plane(const Vec3 &_v1, const Vec3 &_v2, const double t1, const double t2)
	{

		auto v1 = _v1;
		auto v2 = _v2;

		if (v1.z > v2.z)
		{
			std::swap(v1, v2);
		}


		Vec3 _t1(t1 / 2, 0, 0);
		Vec3 _t2(t2 / 2, 0, 0);


		*this = Plane(v1 + _t2, v2 + _t1, v1 - _t2, v2 - _t1);

	}


	/// <summary> ４つの頂点から板を生成します </summary>
	Plane(const Vec3 v1, const Vec3 v2, const Vec3 v3, const Vec3 v4)
	{

		vertices.reserve(4);


		VERTEX3D vertex;
		vertex.dif = Color(1);
		vertex.spc = Color(0);

		// 1
		vertex.pos = v1;
		vertex.u = vertex.v = 1;
		vertices.emplace_back(vertex);

		// 2
		vertex.pos = v2;
		vertex.u = 1, vertex.v = 0;
		vertices.emplace_back(vertex);

		// 3
		vertex.pos = v3;
		vertex.u = 0, vertex.v = 1;
		vertices.emplace_back(vertex);

		// 4
		vertex.pos = v4;
		vertex.u = vertex.v = 0;
		vertices.emplace_back(vertex);

	}


	Plane(const Vec3 &pos, const Size<double> &size) {

		*this = Plane(pos, size.width, size.height);

	}


	Plane(const Vec3 &pos, const double width, const double height)
	{
		double w = width / 2, h = height / 2;

		VERTEX3D vertex;
		vertex.dif = Color(1);
		vertex.spc = Color(0);


		// 1
		vertex.pos = pos + Vec3(w, 0, -h);
		vertex.u = vertex.v = 1;
		vertices.emplace_back(vertex);

		// 2
		vertex.pos = pos + Vec3(w, 0, h);
		vertex.u = 1, vertex.v = 0;
		vertices.emplace_back(vertex);

		// 3
		vertex.pos = pos + Vec3(-w, 0, -h);
		vertex.u = 0, vertex.v = 1;
		vertices.emplace_back(vertex);

		// 4
		vertex.pos = pos + Vec3(-w, 0, h);
		vertex.u = vertex.v = 0;
		vertices.emplace_back(vertex);
	}


	Plane(const double width, const double height)
	{
		*this = Plane(Vec3(0), width, height);
	}




};
