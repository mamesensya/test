#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjAttack : public CObj {
public:
	CObjAttack(float x, float y, float r);
	~CObjAttack() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;//位置
	float m_y;
	float m_r;//角度

	int m_time{ 0 };//時間制御用
};