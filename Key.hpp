#pragma once



enum KeyCode
{

	Key0 = KEY_INPUT_0,
	Key1 = KEY_INPUT_1,
	Key2 = KEY_INPUT_2,
	Key3 = KEY_INPUT_3,
	Key4 = KEY_INPUT_4,
	Key5 = KEY_INPUT_5,
	Key6 = KEY_INPUT_6,
	Key7 = KEY_INPUT_7,
	Key8 = KEY_INPUT_8,
	Key9 = KEY_INPUT_9,

	KeyEscape = KEY_INPUT_ESCAPE,

	KeyA = KEY_INPUT_A,
	KeyB = KEY_INPUT_B,
	KeyC = KEY_INPUT_C,
	KeyD = KEY_INPUT_D,
	KeyP = KEY_INPUT_P,

	KeyLControl = KEY_INPUT_LCONTROL,

	KeyT = KEY_INPUT_T,


	KeyS = KEY_INPUT_S,

	KeyUp = KEY_INPUT_UP,
	KeyDown = KEY_INPUT_DOWN,

	keyLeft = KEY_INPUT_LEFT,
	keyRight = KEY_INPUT_RIGHT,

	KeyV = KEY_INPUT_V,
	KeyZ = KEY_INPUT_Z,


	KeyReturn = KEY_INPUT_RETURN,

};


class KeyStatus
{

	static uint32 key[0x100];

public:

	static void Update()
	{
		char status[0x100];

		GetHitKeyStateAll(status);

		for (const auto i : Rep(0x100))
		{
			key[i] = status[i] ? key[i] + 1 : 0;
		}

	}

	static uint32 Get(const KeyCode keyCode)
	{
		return key[keyCode];
	}

};

uint32 KeyStatus::key[0x100];


class Key
{
protected:

	uint32 _count = 0;

	bool clicked, pressed;

public:


	bool _getClicked() const { return clicked; }
	__getter(_getClicked) bool Clicked;

	bool _getPressed() const { return pressed; }
	__getter(_getPressed) bool Pressed;


	Key() : _count(0), clicked(false), pressed(false)
	{

	}

	Key(const KeyCode keyCode)
	{

		_count = KeyStatus::Get(keyCode);

		clicked = _count == 1 ? true : false;
		pressed = _count ? true : false;

	}

	operator bool() const
	{
		return _count ? true : false;
	}

	/// <summary> text </summary>
	uint32 count() const
	{
		return _count;
	}



};


class MultiKey : public Key
{


private:

	template<typename T>
	void check(T keyCode)
	{

		uint32 __count = KeyStatus::Get(keyCode);

		_count = std::max(_count, __count);

		clicked = clicked && __count == 1 ? true : false;
		pressed = pressed && __count ? true : false;
	}

	template<typename T, typename ...Args>
	void check(T v, Args... args)
	{
		check(v);
		check(args...);
	}


public:


	template<typename ...Args>
	MultiKey(const Args... args)
	{

		clicked = true;
		pressed = true;

		check(args...);
	}



};

