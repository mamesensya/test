#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���@�F�@�Q�[�����C��
class CSceneMainSecond :public CScene
{
public:
	CSceneMainSecond();
	~CSceneMainSecond();
	void InitScene();//�Q�[�����C���̏��������\�b�h
	void Scene();//�Q�[�����C���̎��s�����\�b�h
	int GetEnemy() {
		return GetenemyMax;
	}

private:
	int GetenemyMax = 0;
};