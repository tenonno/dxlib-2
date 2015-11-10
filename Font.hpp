#pragma once




class Font
{

	String name;
	int32 size;

	dxlib_handle handle = dxlib_null;

	static std::map<std::pair<String, int32>, dxlib_handle> fonts;

public:

	Font(const String &name, const uint32 size) : name(name), size(size)
	{

		auto key = std::make_pair(name, size);

		// ä˘ë∂
		if (fonts.find(key) != fonts.end())
		{
			handle = fonts[key];

			return;
		}

		fonts[key] = handle = CreateFontToHandle(name.c_str(), size, -1, DX_FONTTYPE_ANTIALIASING_8X8);

	}

	Size<uint32> getSize(const String &text)
	{
		uint32 width = GetDrawStringWidthToHandle(text.c_str(), text.length(), handle);

		return Size<uint32>(width, size);
	}

	void drawBackground(const double x, const double y, const String &text, const Color &color, const Color &background, double padding = 0)
	{

		auto size = getSize(text);

		Box(Vec2(x - padding, y - padding), Size<double>(size.width + padding * 2, size.height + padding * 2)).draw(background);

		draw(x, y, text, color);
	}

	void drawCenter(const double x, const double y, const String &text, const Color &color)
	{

		auto size = getSize(text);

		draw(x - size.width / 2.0, y - size.height / 2.0, text, color);

	}


	void draw(const double x, const double y, const String &text, const Color &color)
	{
		DrawStringFToHandle((float)x, (float)y, text.c_str(), color, handle);

	}

};

std::map<std::pair<String, int32>, dxlib_handle> Font::fonts;


namespace NS_Font
{


	std::map<String, std::map<uint32, dxlib_handle>> fonts;

	/// <summary> ÉtÉHÉìÉgÇéÊìæÇµÇ‹Ç∑ </summary>
	dxlib_handle Get(const String &name, const uint32 size)
	{

		if (fonts.find(name) != fonts.end())
		{

			if (fonts[name].find(size) != fonts[name].end())
			{
				return fonts[name][size];
			}
		}

		// ê∂ê¨
		return fonts[name][size] = CreateFontToHandle(name.c_str(), size, -1, DX_FONTTYPE_ANTIALIASING_8X8);

	}



}


class __Font
{
	String name;

	uint32 size;

	dxlib_handle handle;

public:


	__Font(const String &name, const uint32 size) : name(name), size(size)
	{
		handle = NS_Font::Get(name, size);

	}

	Size<uint32> getSize(const String &text)
	{
		uint32 width = GetDrawStringWidthToHandle(text.c_str(), text.length(), handle);

		return Size<uint32>(width, size);
	}

	void drawBackground(const double x, const double y, const String &text, const Color &color, const Color &background, double padding = 0)
	{

		auto size = getSize(text);

		Box(Vec2(x - padding, y - padding), Size<double>(size.width + padding * 2, size.height + padding * 2)).draw(background);

		draw(x, y, text, color);
	}

	void drawCenter(const double x, const double y, const String &text, const Color &color)
	{

		auto size = getSize(text);

		draw(x - size.width / 2.0, y - size.height / 2.0, text, color);

	}


	void draw(const double x, const double y, const String &text, const Color &color)
	{
		DrawStringFToHandle((float)x, (float)y, text.c_str(), color, handle);

	}


};
