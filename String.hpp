#pragma once

#include <string>

class String : public std::basic_string<wchar_t>
{

	using my_type = String;
	using my_base = std::basic_string<wchar_t>;

public:

	// construct empty string
	String() noexcept : my_base()
	{
		_Tidy();
	}

	// construct by copying _Right
	String(const String& _Right) : my_base(_Right._Getal().select_on_container_copy_construction())
	{
		_Tidy();
		assign(_Right, 0, npos);
	}

	// construct by moving _Right
	String(my_type &&_Right) noexcept : my_base(std::move(_Right._Getal()))
	{
		_Tidy();
		_Assign_rv(std::forward<my_type>(_Right));
	}

	String(const wchar_t *_Ptr)
		: my_base()
	{	// construct from [_Ptr, <null>)
		_Tidy();
		assign(_Ptr);


	}

	String(const std::wstring &ws) : my_base(ws)
	{

	}

};



template<typename T>
inline String ToString(const T value)
{
	return std::to_wstring(value);
}