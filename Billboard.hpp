#pragma once

class Billboard
{

public:

	Billboard(const Vec3 &pos, const double size, const double angle, const Texture &tex, const UV &uv = UV(0.5, 0.5))
	{

		DrawBillboard3D(pos, (float)uv.u, (float)uv.v, (float)size, (float)angle, tex.getHandle(), true);

	}

};
