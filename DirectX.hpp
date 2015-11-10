#pragma once


enum class D3DVersion
{
	D3D9 = DX_DIRECT3D_9,
	D3D9EX = DX_DIRECT3D_9EX,
	D3D11 = DX_DIRECT3D_11,
};


class DirectX
{

public:


	static void UseVersion(const D3DVersion version)
	{
		SetUseDirect3DVersion(static_cast<int>(version));
	}

	static void Graphic(const uint32 width, const uint32 height, const uint8 colors)
	{
		SetGraphMode(width, height, colors);
	}

};