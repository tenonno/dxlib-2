#pragma once


inline auto command(const String &command)
{

	const uint32 buffer_size = 0x400;

	std::vector<String> result;

	FILE *file = _wpopen(command.c_str(), L"r");

	wchar_t buffer[buffer_size] = {};

	while (fgetws(buffer, buffer_size, file)) {

		result.emplace_back(buffer);

	}


	_pclose(file);
	return result;
}


template<uint8 Digit>
struct Version
{

	uint8 values[Digit];

	String toString(const String &delim) const
	{
		return Join(values, delim);
	}

};


struct Float4 : FLOAT4
{
	Float4(const Vec3 &vec) :FLOAT4{ (float)vec.x,(float)vec.y,(float)vec.z,0 }
	{
	}
};


class ShaderCompiler
{
	String source;
	String type;
	Version<2> ver;

public:

	ShaderCompiler(const String &source, const String &type, const  Version<2> &ver) : source(source), type(type), ver(ver)
	{
	}


	Vector<String> compile() const
	{
		using namespace boost::filesystem;

		String _command;

		// cd
		_command += L"cd " + path(source).parent_path().wstring() + L" & ";

		_command += L"ShaderCompiler.exe /T" + type + L"_";

		_command += ver.toString(L"_") + L" " + path(source).filename().wstring();


		return command(_command);
	}

};



class Shader
{
protected:

	dxlib_handle handle = dxlib_null;

	String source;

	std::time_t time = 0;

	Vector<String> _result;


public:

	bool exists() const
	{
		boost::system::error_code error;
		bool result = boost::filesystem::exists(source, error);
		return result && !error;
	}


	Shader(const String &_source) : source(_source)
	{
	}

	virtual void load() {}

	void release()
	{
		DeleteShader(handle);
	}

	void update()
	{
		using namespace boost::filesystem;

		std::chrono::system_clock::from_time_t(time);


		// É\Å[ÉXÇ™ë∂ç›ÇµÇ»Ç¢èÍçá
		if (!exists())
		{
			return;
		}

		std::time_t _time = last_write_time(source);

		if (time < _time)
		{
			time = _time;

			release();
			load();

		}

	}

	void compile(const String &type, const Version<2> &ver)
	{
		_result = ShaderCompiler(source, type, ver).compile();
	}

	Vector<String> result()
	{
		return _result;
	}

	virtual void use() = 0;

};


class VertexShader : public Shader
{
	Version<2> ver;
public:

	void use() override
	{
		SetUseVertexShader(handle);
	}

	VertexShader(const String &source, const Version<2> &ver = { 3, 0 }) : Shader(source), ver(ver)
	{
	}

	void _const(const uint32 index, const FLOAT4 &float4)
	{
		SetVSConstF(index, float4);
	}

	void load() override
	{
		using namespace boost::filesystem;
		compile(L"vs", ver);
		handle = LoadVertexShader((path(source).parent_path().wstring() + L"/" + path(source).stem().wstring() + L".vso").c_str());
	}
};


class PixelShader : public Shader
{
	Version<2> ver;
public:

	void use() override
	{
		SetUsePixelShader(handle);
	}

	PixelShader(const String &source, const Version<2> &ver = { 3, 0 }) : Shader(source), ver(ver)
	{
	}

	void load() override
	{
		using namespace boost::filesystem;
		compile(L"ps", ver);
		handle = LoadPixelShader((path(source).parent_path().wstring() + L"/" + path(source).stem().wstring() + L".pso").c_str());



	}
};

