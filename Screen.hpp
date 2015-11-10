#pragma once

class Screen : public Texture
{


	std::map<uint32, Screen> mipmap;


public:


	/// <summary> ハンドルからスクリーンを生成します </summary>
	Screen(const dxlib_handle handle) : Texture(handle) {}

	Screen() : Texture(dxlib_null) {}

	Screen(const uint32 width, const uint32 height, bool alpha = true)
	{
		handle = MakeScreen(width, height, alpha);
	}

	// 仮実装
	template<class... ArgsType>
	void _filter(int type, ArgsType ...args)
	{
		GraphFilter(handle, type, args...);

	}


	void _update_mipmap(const std::initializer_list<uint32> &sizes)
	{

		for (auto size : sizes)
		{

			_copyExtend(_mipmap(size));

		}

	}

	void _copyExtend(Screen &screen)
	{

		SwapScreen::Begin(screen.handle);

		ClearDrawScreen();

		DrawExtendGraph(0, 0, screen.getSize().width, screen.getSize().height, handle, true);

		SwapScreen::End();

	}


	Screen _mipmap(const uint32 size)
	{
		if (mipmap.find(size) == mipmap.end()) {

			mipmap[size] = Screen(size, size, false);

		}

		return mipmap[size];
	}


	void set()
	{
		SetDrawScreen(handle);
	}


	void clear()
	{
		ClearDrawScreen();
	}

};
