#pragma once

// インクルードファイル
#include "InputKey.hpp"
#include "InputPad.hpp"
#include <math.h>


// マクロ

// directx関係でよくある解放マクロ
#define SAFE_RELEASE(p) { if(p!=NULL) { (p)->Release(); (p)=NULL; } }

// ポインタ用解放マクロ
#define POINTER_RELEASE(p) { if(p!=NULL) {delete (p); (p)=NULL; } }

// 2D関連画像解放マクロ
#define GRAPHIC_RELEASE(p) { if(p!=-1) { DeleteGraph(p); (p)=-1; } }

// 3D関連画像解放マクロ
#define MODEL_RELEASE(p) { if(p!=-1) { MV1DeleteModel(p); (p)=-1; } }

// 音解放マクロ
#define SOUND_RELEASE(p) { if(p!=-1) { StopSoundMem(p); DeleteSoundMem(p); (p)=-1; } }

// 光源ハンドル解放マクロ
#define LIGHT_RELEASE(p) { if(p!=-1) { DeleteLightHandle(p); (p)=-1; } }

// シャドウマップ解放マクロ
#define SHADOW_MAP_RELEASE(p) { if(p!=-1) { DeleteShadowMap(p); (p)=-1; } }
