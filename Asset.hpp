#pragma once


template<class T>
class Asset
{
	static std::map<String, T> list;
	String name;



public:

	// release
	static void Release(const String &name)
	{


		for (auto &_sub : _get_subname_list())
		{
			if (_sub.first == name)
			{

				_sub.swap

			}

			_sub.first
		}

	}

	// 
	static std::map<String, String> _get_subname_list()
	{
		static std::map<String, String> a;
		return a;
	}


	static void Alias()
	{

	}

	// _Ref _new 
	static void _rename(const String &_d, const String &_new)
	{
		static std::map<String, String> _rename_list;

		_rename_list[_new] = _d;

	}

	// test const
	Asset(const String &name, bool __rename)
	{

		// 


		return;

		static std::map<String, String> _rename_list;

		_rename_list.find(name)

	}

	Asset(const String &name) : name(name)
	{

		// _test
		{

		}

	}

	T &operator()()
	{
		return Asset<T>::list[name];
	}

	template<typename... Args>
	static void Register(const String &name, Args... args)
	{
		Asset<T>::list[name] = T(args...);
	}

};

template<class T>
std::map<String, T> Asset<T>::list;