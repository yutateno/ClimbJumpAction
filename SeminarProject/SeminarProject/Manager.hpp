#pragma once
#include "BaseMove.hpp"
#include "LoadThread.hpp"
#include "MainMove2.hpp"


class Manager
{
private:
	ESceneNumber e_preScene;		// ���O�̃V�[��
	ESceneNumber e_nowScene;		// ���̃V�[��


	BaseMove* p_baseMove;			// �V�[���̊��N���X
	LoadThread* p_loadThread;		// ���[�h�̃N���X


	void SceneChange();				// �V�[����؂�ւ���


	// ���[�u�Q�Ɋւ���
	const int max2 = 7;
	std::string move2str[7];
	ELOADFILE load2[7];


	int antiAliasScreen;



public:
	Manager();			// �R���X�g���N�^
	~Manager();			// �f�X�g���N�^

	void Update(const unsigned __int8 controllNumber);		// ���C���v���Z�X
};