#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjPenetrateBullet : public CObj {
public:
	CObjPenetrateBullet(float x, float y, float r);
	~CObjPenetrateBullet() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	float m_r;
	int interval;

	bool  intervalEnable;

	bool m_up;
	bool m_reft;
	bool m_right;
	bool m_down;



	float m_scroll_map_x{ 0 };
	float m_scroll_map_y{ 0 };
};