#pragma once


enum class DrawMode
{
	Nearest = DX_DRAWMODE_NEAREST,
	Bilinear = DX_DRAWMODE_BILINEAR,
	Anisotropic = DX_DRAWMODE_ANISOTROPIC
};


class AntiAlias
{

public:


	static void UseMultiSample(const int32 samples, const int32 quality)
	{
		SetFullSceneAntiAliasingMode(samples, quality);
		SetCreateDrawValidGraphMultiSample(samples, quality);
	}


	static void SetDrawMode(const DrawMode mode)
	{
		DxLib::SetDrawMode(static_cast<int>(mode));
	}

};
