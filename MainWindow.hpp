#pragma once

class MainWindow
{

public:

	static void SetTitle(const String &title)
	{
		SetMainWindowText(title.c_str());
	}

	static void SetAlways(const bool value)
	{
		SetAlwaysRunFlag(value);
	}



	static void SetStyle(const uint8 style)
	{
		SetWindowStyleMode(style);
	}


	static HWND GetHandle()
	{
		return GetMainWindowHandle();
	}

	static Size<uint32> Size()
	{
		int width, height;
		GetWindowSize(&width, &height);

		return{ (uint32)width, (uint32)height };
	}



};