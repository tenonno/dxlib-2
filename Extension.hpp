#pragma once



/// <summary> double ‚ð”äŠr‚·‚é‰‰ŽZŽq </summary>
class Rough : private boost::equality_comparable<Rough>, private boost::less_than_comparable<Rough>
{
	double value;

public:

	Rough(const double value) : value(value) {}

	/// <summary> ’l‚ðŽæ“¾‚µ‚Ü‚· </summary>
	double get() const
	{
		return std::round(value * 1000);
	}

	bool operator==(const Rough& x) const
	{
		return get() == x.get();
	}

	bool operator<(const Rough &x) const
	{
		return get() < x.get();
	}

};



struct Vertex2D
{

	Vec2 pos;
	double rhw = 1;
	Color color;
	UV uv;

	Vertex2D()
	{

	}

};

struct Vertices2D
{

	std::vector<Vertex2D> vertices;

	std::unique_ptr<VERTEX2D[]> buffer;

	auto begin()
	{
		return vertices.begin();
	}
	auto end()
	{
		return vertices.end();
	}

	Vertices2D(const uint32 size) : vertices(size), buffer(new VERTEX2D[size])
	{

	}


	Vertex2D &operator[](const uint32 index)
	{
		return vertices[index];
	}

	VERTEX2D *operator&() const
	{


		for (auto i : Rep(vertices.size()))
		{
			buffer[i].pos = Vec3(vertices[i].pos.x, vertices[i].pos.y, 0);
			buffer[i].dif = vertices[i].color;
			buffer[i].rhw = (float)vertices[i].rhw;
			buffer[i].u = (float)vertices[i].uv.u;
			buffer[i].v = (float)vertices[i].uv.v;
		}



		return buffer.get();
	}

	uint32 size() const
	{
		return vertices.size();
	}

};






class Particles
{


};
class Particle
{
public:

	Texture tex;

	Vec3 pos;

	struct Status
	{
		Vec3 pos, move, grv;
		double size;
		double angle;
		uint32 count = 0;
		double speed;
		Vec3 d_pos;
	};

	std::vector<Status> particles;

	struct
	{
		uint32 begin, end;
	} fadeOut;

	uint32 count;

	void create(const Vec3 &pos, const Vec3 &random, const Vec3 &move, const Vec3 &grv, const uint32 number)
	{
		particles.resize(number);

		this->pos = pos;

		count = 0;

		for (auto &particle : particles)
		{

			double x = Random(-random.x, random.x), y = Random(-random.y, random.y), z = Random(-random.z, random.z);

			particle.pos = pos + Vec3(x, y, z);

			particle.size = 0.02 + Random(0, 0.05);

			particle.move = move* Random(0.8, 1.2);

			particle.speed = Random(0.8, 1.2);
			particle.angle = Random(0, Math::PI2);

			particle.grv = Vec3(Random(0.0002), -0.002, 0);
			particle.count = 0;
		}
	}

	void update()
	{
		for (auto &particle : particles)
		{
			particle.pos += particle.move;
			particle.count++;
			particle.pos += particle.grv*particle.count*particle.speed;

			particle.d_pos = particle.pos;
		}




		count++;
	}

	void scale(const Vec3 &scale)
	{

		for (auto &particle : particles)
		{

			Vec3 a = particle.pos - pos;

			a *= scale;


			particle.d_pos = pos + a;

		}

	}

	void draw(const Texture &tex)
	{

		ZBuffer::Off();

		double addValue = 1;

		if (count >= fadeOut.begin)
		{

			addValue = 1 - 1.0 / (fadeOut.end - fadeOut.begin) * (count - fadeOut.begin);
		}

		BlendMode::Set(BlendType::Add, addValue);

		for (auto &particle : particles)
		{

			Billboard(particle.d_pos, particle.size, particle.angle, tex);



		}
		BlendMode::Clear();



	}

};