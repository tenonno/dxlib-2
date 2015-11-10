#pragma once
namespace SwapScreen
{

	dxlib_handle target;


	void Begin(const dxlib_handle handle)
	{

		target = GetDrawScreen();

		SetDrawScreen(handle);

	}

	void End()
	{
		SetDrawScreen(target);
	}



};
