#pragma once
class Renderer
{

public:

	static void SetBackScreen()
	{
		SetDrawScreen(DX_SCREEN_BACK);
	}

	static void SetScreen(const Screen &screen)
	{
		SetDrawScreen(screen.getHandle());
	}

	static void Flip()
	{
		ScreenFlip();
	}

	static void Clear()
	{
		ClearDrawScreen();
	}

};
