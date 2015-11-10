#pragma once

class Texture
{
protected:

	dxlib_handle handle;

public:

	/// <summary> ハンドルから画像を生成します </summary>
	Texture(const dxlib_handle handle) : handle(handle) {}


	Texture() : handle(DX_NONE_GRAPH) {}

	Texture(const String &file, const uint32 width, const uint32 height)
	{
		handle = LoadGraph(file.c_str());
		resize(width, height);


	}

	/// <summary> 画像のサイズを取得します </summary>
	Size<uint32> getSize()
	{
		int width, height;
		GetGraphSize(handle, &width, &height);

		return Size<uint32>(width, height);
	}

	/// <summary> 反転した画像を複製します </summary>
	Texture copyMirror()
	{

		auto size = getSize();

		dxlib_handle texture = MakeScreen(size.width, size.height, true);

		SwapScreen::Begin(texture);


		DrawTurnGraph(0, 0, handle, true);


		SwapScreen::End();
		return Texture(texture);
	}


	/// <summary> 回転した画像を複製します </summary>
	Texture copyRotate(const double radian)
	{

		auto size = getSize();

		dxlib_handle texture = MakeScreen(size.width, size.height, true);

		SwapScreen::Begin(texture);

		DrawRotaGraph(size.width *0.5, size.height*0.5, 1, radian, handle, true);


		SwapScreen::End();
		return Texture(texture);
	}


	/// <summary> 画像を 3D で扱えるように修正します </summary>
	Texture &use3D(bool alpha = true) {


		uint32 width = getSize().width, height = getSize().height;

		uint32 size = std::max(width, height);


		// そのままでもいい場合
		if (width == height && size >= 8 && (size - 1 & size))
		{
			return *this;
		}



		int count = 3;


		while (true)
		{

			uint32 _ = static_cast<uint32>(std::pow(2, count++));

			if (_ >= size)
			{
				size = _ < 8 ? 8 : _;
				break;
			}

		}




		dxlib_handle screen = MakeScreen(size, size, alpha);

		SetDrawScreen(screen);

		DrawExtendGraph(0, 0, size, size, handle, alpha);



		DeleteGraph(handle);


		return *this = Texture(screen);
	}



	Texture(const String &file)
	{
		handle = LoadGraph(file.c_str());
	}

	void draw(const double x, const double y)
	{
		DrawGraphF((float)x, (float)y, handle, true);
	}


	void draw(const double x1, const double y1, const double x2, const double y2)
	{
		DrawExtendGraphF(static_cast<double>(x1), static_cast<double>(y1), static_cast<double>(x2), static_cast<double>(y2), handle, true);
	}


	/// <summary> 座標とサイズを指定して描画します </summary>
	void draw(const Vec2 &pos, const Size<double> &size)
	{
		DrawExtendGraphF(pos.x, pos.y, pos.x + size.width, pos.y + size.height, handle, true);
	}

	/// <summary> 範囲を指定して描画します </summary>
	void draw(const Rect &rect)
	{
		draw(rect.pos(), rect.size());
	}

	void drawCenter(const Vec2 &center, const Size<double> &size)
	{
		draw(Vec2(center.x - size.width / 2, center.y - size.height / 2), size);
	}

	/// <summary> 中心座標とサイズから描画します </summary> 
	void draw(const Vec2 &center, const double width, const double height)
	{

		Vec2 min(center.x - width / 2, center.y - height / 2);
		Vec2 max(center.x + width / 2, center.y + height / 2);
		DrawExtendGraphF(min.x, min.y, max.x, max.y, handle, true);

	}

	dxlib_handle getHandle() const
	{
		return handle;
	}

	void resize(const uint32 width, const uint32 height)
	{
		dxlib_handle screen = MakeScreen(width, height, true);



		auto _ = GetDrawScreen();


		SetDrawScreen(screen);

		DrawExtendGraph(0, 0, width, height, handle, true);

		SetDrawScreen(_);


		DeleteGraph(handle);

		handle = screen;

	}

};






#include <map>

namespace NS_TextureAsset
{

	std::map<String, Texture> list;

}
class TextureAsset
{

	String name;

public:

	/// <summary> 全てのテクスチャ情報を表示します </summary>
	static void PrintStatus()
	{


		for (auto &texture : NS_TextureAsset::list)
		{
			/*
			console::log(
			texture.first + L" -> size[" + ToString(texture.second.getSize().width) + L", " + ToString(texture.second.getSize().height) + L"]\n"
			);
			*/

		}


	}





	void operator=(const String &file)
	{

	}


	void set(const String &file, const bool use3D = false)
	{

		if (NS_TextureAsset::list.find(name) == NS_TextureAsset::list.end()) {

			NS_TextureAsset::list[name] = Texture(file);


			if (use3D)
			{
				NS_TextureAsset::list[name].use3D();

			}


		}

	}


	void set(const String &file, const Size<uint32> size)
	{

		if (NS_TextureAsset::list.find(name) == NS_TextureAsset::list.end()) {

			NS_TextureAsset::list[name] = Texture(file, size.width, size.height);

		}

	}



	Texture get()
	{
		if (NS_TextureAsset::list.find(name) != NS_TextureAsset::list.end()) {

			return NS_TextureAsset::list[name];

		}
		return Texture();
	}



	TextureAsset(const String &name) : name(name)
	{

		if (name.empty())
		{
			throw "aaa";
		}

	}



};


using TextureAsset2 = Asset<Texture>;
