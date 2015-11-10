#pragma once

class Model
{

	dxlib_handle handle = dxlib_null;


public:

	Model(const String &source)
	{
		handle = MV1LoadModel(source.c_str());
	}

	Model &setPos(const Vec3 &pos)
	{
		MV1SetPosition(handle, pos);
	}


	Model &setScale(const double scale)
	{
		MV1SetScale(handle, Vec3(scale));

		return (*this);
	}

	uint32 getFrameNum()
	{
		return MV1GetFrameNum(handle);
	}

	Vec3 getMaxVertexPos()
	{
		Vec3 max(0, 0, 0);
		
		for (int32 index : Rep(getFrameNum()))
		{
//			MV1GetFrameMaxVertexLocalPosition

		}

	}


	Vec3 _getPos() { return MV1GetPosition(handle); }
	void _setPos(const Vec3 &pos) { MV1SetPosition(handle, pos); }
	__property(_getPos, _setPos) Vec3 Pos;



	void draw() const
	{
		MV1DrawModel(handle);
	}

};