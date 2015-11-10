#pragma once





class DivTexture
{

	Vector<Texture> textures;

public:

	DivTexture()
	{

	}

	void use3D()
	{


		for (auto &texture : textures)
		{
			texture.use3D(false);
		}


	}

	DivTexture(const String &source, const uint32 all, const uint32 x, const uint32 y)
	{
		using namespace boost::filesystem;


		//MessageBox::Show(path(source).stem().string());


		dxlib_handle handle, width, height;

		GetGraphSize(handle = LoadGraph(source.c_str()), &width, &height);

		DeleteGraph(handle);

		std::vector<dxlib_handle> handles(all);

		LoadDivGraph(source.c_str(), all, x, y, (int)((double)width / x), (int)((double)height / y), &handles[0]);


		for (auto handle : handles)
		{
			textures.emplace_back(Texture(handle));
		}




	}

	//	/// <summary> 

	/// <param name="pos"> 0 から 1 の再生位置 </param>
	/// <param name="frame"> 最終フレーム </param>
	/*
	Texture operator()(const double pos, const uint32 frame)
	{

	return Texture(handles[(uint32)(handles.size() / (double)frame * (1.0 / frame * pos))]);

	}
	*/


	Texture operator()(uint32 pos, const uint32 frame)
	{

		return (*this)[static_cast<uint32>(textures.size() / (double)frame * pos)];

		//		return Texture(handles[(uint32)(handles.size() / (double)frame * (1.0 / frame * pos))]);

	}



	Texture operator[](const uint32 index)
	{
		return textures[index % textures.size()];
	}


};




using DivTextureAsset = Asset<DivTexture>;





