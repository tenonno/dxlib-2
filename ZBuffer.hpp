#pragma once

struct ZBuffer
{

	static void Use(const bool use)
	{
		SetUseZBuffer3D(use);
		SetWriteZBuffer3D(use);
	}

	static void On()
	{
		Use(true);
	}

	static void Off()
	{
		Use(false);
	}

};