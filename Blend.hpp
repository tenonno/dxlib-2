#pragma once


enum class BlendType
{
	None = DX_BLENDMODE_NOBLEND,
	Add = DX_BLENDMODE_ADD,
	Alpha = DX_BLENDMODE_ALPHA,
	Mul = DX_BLENDMODE_MUL
};

class BlendMode
{
public:

	static void Clear()
	{
		Set(BlendType::None, 0);
	}

	static void Set(const BlendType type, double value)
	{
		
		SetDrawBlendMode(static_cast<int>(type), ToInt8(value));
	}

	static BlendType GetType()
	{
		int type;
		GetDrawBlendMode(&type, nullptr);
		return static_cast<BlendType>(type);
	}

	static double GetValue()
	{
		int value;
		GetDrawBlendMode(nullptr, &value);
		return value / (double)0xff;
	}

};