#include "Manager.hpp"


void Manager::SceneChange()
{
	switch (e_nowScene)
	{
	case ESceneNumber::SECONDLOAD:
		p_loadThread = new LoadThread();
		break;


	case ESceneNumber::SECONDMOVE:
		p_baseMove = new MainMove2(p_loadThread->GetFile());
		p_baseMove->SetScene(e_nowScene);
		POINTER_RELEASE(p_loadThread);
		break;

	default:
		break;
	}
}

Manager::Manager()
{
	e_preScene = ESceneNumber::SECONDLOAD;
	e_nowScene = ESceneNumber::SECONDLOAD;

	move2str[0] = "media\\�X�e�[�W���f��\\move1_hantei.myn";
	move2str[1] = "media\\swordCLPH\\clph_sword_all.myn";
	move2str[2] = "media\\paneru\\paneru.myn";
	move2str[3] = "media\\kaidan\\kaidan.myn";
	move2str[4] = "media\\kaidan\\kaidan_hantei.myn";
	move2str[5] = "media\\�X��\\Gaitou.myn";
	move2str[6] = "media\\�X�J�C�{�b�N�X\\SkyDome.myn";
	load2[0] = ELOADFILE::mv1model;
	load2[1] = ELOADFILE::mv1model;
	load2[2] = ELOADFILE::mv1model;
	load2[3] = ELOADFILE::mv1model;
	load2[4] = ELOADFILE::mv1model;
	load2[5] = ELOADFILE::mv1model;
	load2[6] = ELOADFILE::mv1model;


	p_baseMove = NULL;
	p_loadThread = NULL;

	p_loadThread = new LoadThread();


	SetCreateDrawValidGraphMultiSample(4, 4);			// 4x4�̃A���`�G�C���A�V���O���[�h�ɂ���
	antiAliasScreen = MakeScreen(1920, 1080, false);	// �A���`�G�C���A�V���O�p�̉�ʂ��쐬
	SetCreateDrawValidGraphMultiSample(0, 0);			// ���ɖ߂�
}


Manager::~Manager()
{
	GRAPHIC_RELEASE(antiAliasScreen);
	POINTER_RELEASE(p_baseMove);
	POINTER_RELEASE(p_loadThread);
}

void Manager::Update(const unsigned __int8 controllNumber)
{
	if (e_nowScene == e_preScene)		// ���̃V�[���ƒ��O�̃V�[��������
	{if (e_preScene == ESceneNumber::SECONDLOAD)
		{
			p_loadThread->Process(max2, move2str, load2);		// ���[�h������
			if (p_loadThread->GetNum() >= max2)		// ���[�h���I��������
			{
				if (KeyData::Get(KEY_INPUT_Z) == 1)			// �I�������ꑀ��
				{
					e_nowScene = ESceneNumber::SECONDMOVE;
				}
			}
		}
		else
		{
			// �A���`�G�C���A�X��ʂɑ΂��ĕ`�揈�����s��
			SetDrawScreen(antiAliasScreen);
			ClearDrawScreen();
			p_baseMove->CameraProcess();
			p_baseMove->Draw();
			p_baseMove->Process(controllNumber);
			e_nowScene = p_baseMove->GetScene();


			// �A���`�G�C���A�X��ʂɕ`�悵�����̂𗠉�ʂɏ�������
			SetDrawScreen(DX_SCREEN_BACK);
			DrawGraph(0, 0, antiAliasScreen, false);
			p_baseMove->CameraProcess();				// SetDrawScreen���s���ƃJ�����̐ݒ肪�Ȃ��Ȃ�̂ōĐݒ���s��
			ScreenFlip();
		}
	}
	else
	{
		SceneChange();
		e_preScene = e_nowScene;
	}
}