#pragma once


class Debug
{

public:

	static void Clear()
	{
		clsDx();
	}

	
	
	template<typename... Args>
	static void Log(const Args... args)
	{

		printfDx((Format(args...) + L'\n').c_str());
		
	}

	static void SetFontSize(const int32 size)
	{
		SetLogFontSize(size);
	}



};