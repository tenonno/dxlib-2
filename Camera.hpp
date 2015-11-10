#pragma once

class Camera
{

public:

	/// <summary> •`‰æ‹——£‚ðŽw’è‚µ‚Ü‚· </summary>
	static void Distance(const double near, const double far)
	{
		SetCameraNearFarD(near, far);
	}

	static void Set(const Vec3 &pos, const Vec3 &look, const Vec3 up = Vec3(0, 1, 0))
	{
		SetCameraPositionAndTargetAndUpVecD(pos, look, up);
	}

	static void Center(const double x, const double y)
	{
		SetCameraScreenCenterD(x, y);
	}


	static Matrix GetViewMatrix()
	{
		return GetCameraViewMatrix();
	}


};
