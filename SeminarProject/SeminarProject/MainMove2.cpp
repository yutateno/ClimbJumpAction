#include "MainMove2.hpp"



void MainMove2::ShadowDraw()
{
	BaseMove::ShadowCharaSetUpBefore();
	p_character->Draw();
	for (int i = 0; i != 10; ++i)
	{
		p_stageStairs[i]->Draw();
	}
	for (int i = 0; i != 30; ++i)
	{
		p_stageStreetLight[i]->Draw();
	}
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i]->Draw();
	}
	BaseMove::ShadowCharaSetUpAfter();


	BaseMove::ShadowAnotherCharaSetUpBefore();
	for (int i = 0; i != 10; ++i)
	{
		p_stageStairs[i]->Draw();
	}
	for (int i = 0; i != 30; ++i)
	{
		p_stageStreetLight[i]->Draw();
	}
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i]->Draw();
	}
	BaseMove::ShadowAnotherCharaSetUpAfter();


	BaseMove::ShadowNoMoveDrawBefore();
	BaseMove::ShadowAnotherCharaDrawBefore();
	BaseMove::ShadowCharaDrawBefore();
	p_stage->Draw();
	for (int i = 0; i != 10; ++i)
	{
		p_stageStairs[i]->Draw();
	}
	for (int i = 0; i != 30; ++i)
	{
		p_stageStreetLight[i]->Draw();
	}
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i]->Draw();
	}
	p_character->Draw();
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
}


MainMove2::MainMove2(const std::vector<int> v_file)
{
	// ポインタNULL初期化
	p_camera					 = NULL;
	p_character					 = NULL;
	p_stage						 = NULL;
	for (int i = 0; i != 10; ++i)
	{
		p_stageStairs[i]		 = NULL;
	}
	for (int i = 0; i != 30; ++i)
	{
		p_stageStreetLight[i]	 = NULL;
	}
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i]		 = NULL;
	}


	// ポインタ初期化
	for (int i = 0; i != 10; ++i)
	{
		p_stageStairs[i] = new StageStairs(v_file[EFILE::stairs], v_file[EFILE::stage], VGet(-100.0f*i, 0.0f, -1000.0f));
	}
	p_stage		 = new Stage(v_file[EFILE::stage]);
	p_character	 = new CharacterSword(v_file[EFILE::characterAttack], v_file[EFILE::stage], v_file[EFILE::stairsColl], v_file[EFILE::block]);
	p_camera	 = new Camera(p_character->GetArea(), v_file[EFILE::stage]);
	for (int i = 0; i != 30; ++i)
	{
		p_stageStreetLight[i] = new StageStreetLight(v_file[EFILE::streetLight], v_file[EFILE::stage], VGet(250.0f*i, 0.0f, -100.0f*i));
	}
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i] = new StagePaneru(v_file[EFILE::block], v_file[EFILE::stage], VGet(1000.0f * i, 100.0f*i, 100.0f*i));
	}


	// スカイボックス読み込み
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBox]);


	// 階段のあたり判定
	for (int i = 0; i != 10; ++i)
	{
		p_character->SetStairsArea(p_stageStairs[i]->GetArea(), i);
	}

	// パネルのあたり判定
	for (int i = 0; i != 10; ++i)
	{
		p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
	}

	BaseMove::ShadowNoMoveSetUpBefore();
	p_stage->Draw();
	BaseMove::ShadowNoMoveSetUpAfter();
}


MainMove2::~MainMove2()
{
	for (int i = 0; i != 10; ++i)
	{
		POINTER_RELEASE(p_stagePaneru[i]);
	}
	for (int i = 0; i != 30; ++i)
	{
		POINTER_RELEASE(p_stageStreetLight[i]);
	}
	for (int i = 0; i != 10; ++i)
	{
		POINTER_RELEASE(p_stageStairs[i]);
	}
	POINTER_RELEASE(p_camera);
	POINTER_RELEASE(p_character);
	POINTER_RELEASE(p_stage);
}


// 描画
void MainMove2::Draw()
{
	BaseMove::SkyBoxDraw();


	ShadowDraw();


	p_character->Draw();
}


// メインプロセス
void MainMove2::Process(const unsigned __int8 controllNumber)
{
	p_character->Process(controllNumber, p_camera->GetAngle());		// キャラクターのプロセスを呼ぶ


	p_camera->Process(p_character->GetArea(), controllNumber);		// カメラのプロセスを呼ぶ


	BaseMove::ShadowArea(p_character->GetArea());

	BaseMove::SkyBoxProcess(p_character->GetArea());
}


void MainMove2::CameraProcess()
{
	p_camera->SetUp();		// カメラのプロセスを呼ぶ
}