#pragma once



namespace NS_System
{

	uint32 count = 0;

}

struct System
{

	static uint32 Count()
	{
		return NS_System::count;
	}

	static bool Update()
	{

		KeyStatus::Update();

		Debug::Clear();


		NS_System::count++;


		return !ProcessMessage();
	}


	static bool Initialize()
	{




		// ウィンドウ関連
		ChangeWindowMode(true);


		MainWindow::SetStyle(9);




		return DxLib_Init() != dxlib_error;
	}

	static void Exit()
	{
		DxLib_End();
	}

};

