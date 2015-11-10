#pragma once

#include "DxLib.h"

#include <cstdint>

#include <thread>
#include <functional>
#include <array>
#include <map>
#include <memory>
#include <tuple>
#include <regex>
#include <utility>
#include <algorithm>


// boost


#include <boost/filesystem.hpp>
#include <boost/operators.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>


/// <summary> property </summary>
#define __property(_get, _set) __declspec(property(get = _get, put = _set)) 

#define __getter(_get) __declspec(property(get = _get)) 
#define __setter(_set) __declspec(property(put = _set)) 


using int8 = std::int8_t;
using uint8 = std::uint8_t;
using int16 = std::int16_t;
using uint16 = std::uint16_t;
using int32 = std::int32_t;
using uint32 = std::uint32_t;


const int32 null = 0;



using dxlib_handle = int32;

const dxlib_handle dxlib_error = -1;
const dxlib_handle dxlib_null = -1;

#undef max
#undef min
#undef near
#undef far
void Main();


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	Main();
	return 0;
}












#include <Container.hpp>
#include <String.hpp>


#include <Algorithm.hpp>


#include <Color.hpp>

#include <Math.hpp>




#include <Random.hpp>


#include <Format.hpp>


#include <Size.hpp>

#include <MessageBox.hpp>

#include <MainWindow.hpp>




#include <Key.hpp>


#include <Debug.hpp>


#include <ZBuffer.hpp>


#include <Matrix.hpp>


#include <Blend.hpp>


// ベクトル
#include <Vector.hpp>


#include <Rect.hpp>

// アセット管理
#include <Asset.hpp>

// 動的テクスチャの差し替え
#include <SwapScreen.hpp>
// テクスチャ
#include <Texture.hpp>
// 分割テクスチャ
#include <DivTexture.hpp>
// 動的テクスチャ
#include <Screen.hpp>

#include <Primitive.hpp>

#include <Plane.hpp>
#include <Fence.hpp>

// カメラ
#include <Camera.hpp>

#include <Box.hpp>
#include <Line.hpp>
#include <Line3D.hpp>

#include <Font.hpp>

#include <Sound.hpp>

#include <System.hpp>

#include <Scene.hpp>
#include <Billboard.hpp>
#include <DirectX.hpp>
#include <Renderer.hpp>
#include <AntiAlias.hpp>
#include <Extension.hpp>

#include <Model.hpp>

#include <Shader.hpp>

#include <Light.hpp>