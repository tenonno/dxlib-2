#pragma once


#include <String.hpp>
#include <MainWindow.hpp>

#undef MessageBox

class MessageBox
{
public:

	static void Show(const String &text) 
	{
		MessageBoxW(MainWindow::GetHandle(), text.c_str(), nullptr, MB_OK);
	}



	static void Show(String text, String caption) 
	{
		MessageBoxW(MainWindow::GetHandle(), text.c_str(), caption.c_str(), MB_OK);
	}

};