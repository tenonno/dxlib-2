#pragma once
#pragma once




class Fence : public Primitive
{

	double height;

public:

	/// <summary> çÚÇåXÇØÇ‹Ç∑ </summary>
	void tilt(const Matrix &mat)
	{


		auto w2 = Vec3(0, height, 0).transform(mat);

		w2.y -= height;


		for (const auto i : Rep(5))
		{
			vertices[i * 2 + 1].pos = VAdd(vertices[i * 2 + 1].pos, (VECTOR)w2);
		}

	}



	/// <summary> è„ñ ÇÃî¬Çê∂ê¨ÇµÇ‹Ç∑ </summary>
	Plane fillTop()
	{
		return Plane(vertices[1].pos, vertices[7].pos, vertices[3].pos, vertices[5].pos);
	}

	/// <summary> â∫ñ ÇÃî¬Çê∂ê¨ÇµÇ‹Ç∑ </summary>
	Plane fillBottom()
	{
		return Plane(vertices[0].pos, vertices[6].pos, vertices[2].pos, vertices[4].pos);
	}


	Fence(const Size<double> &size, const double height)
	{
		*this = Fence(Vec3(0), size, height);
	}


	Fence(const Vec3 &pos, const Size<double> &size, const double height) : height(height)
	{

		double w = size.width / 2, h = size.height / 2;

		std::vector<Vec3> list = { Vec3(w, 0, -h),Vec3(-w, 0, -h),  Vec3(-w, 0, h), Vec3(w, 0, h) };

		double c = 0;

		for (auto &_pos : list)
		{
			VERTEX3D vertex;

			vertex.pos = pos + _pos;

			vertex.dif = Color(1);
			vertex.spc = Color(0);

			vertex.u = static_cast<double>(c), vertex.v = 1;

			vertices.emplace_back(vertex);


			vertex.pos += (VECTOR)Vec3(0, height, 0);

			vertex.u = static_cast<double>(c), vertex.v = 0;

			vertices.emplace_back(vertex);

			c += 1.0 / 4.0;

		}

		auto v1 = *(vertices.begin() + 0);
		auto v2 = *(vertices.begin() + 1);

		v1.u = v2.u = c;

		vertices.emplace_back(v1);
		vertices.emplace_back(v2);

		/*

		for (const auto i : Rep(vertices.size() / 2 - 1))
		{


		auto vertex = vertices[i * 4 + 2];

		vertex.u = 0, vertex.v = 1;



		vertices.insert(vertices.begin() + (i * 4 + 2 + 0), vertex);


		vertex = vertices[i * 4 + 2 + 1];

		vertex.u = 0, vertex.v = 0;

		vertices.insert(vertices.begin() + (i * 4 + 2 + 1), vertex);


		}

		*/




	}


};