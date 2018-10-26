#pragma once
#include "BaseMove.hpp"
#include "LoadThread.hpp"
#include "MainMove2.hpp"


class Manager
{
private:
	ESceneNumber e_preScene;		// 直前のシーン
	ESceneNumber e_nowScene;		// 今のシーン


	BaseMove* p_baseMove;			// シーンの基底クラス
	LoadThread* p_loadThread;		// ロードのクラス


	void SceneChange();				// シーンを切り替える


	// ムーブ２に関する
	const int max2 = 7;
	std::string move2str[7];
	ELOADFILE load2[7];


	int antiAliasScreen;



public:
	Manager();			// コンストラクタ
	~Manager();			// デストラクタ

	void Update(const unsigned __int8 controllNumber);		// メインプロセス
};