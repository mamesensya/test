//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "Objbreakblock.h"
#include"ObjUserInterface.h"
#include"ObjHero.h"



//使用するネームスペース
using namespace GameL;




//コンストラクタ
CObjbreakblock::CObjbreakblock(float x, float y )
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjbreakblock::Init()
{

	//ボックスの当たり判定
	//主人公の位置取得
	//CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//float hx = hero->GetX();
	//float hy = hero->GetY();
	////マップの要素にアクセス
	//for (int i = 0; i < MAP_Y; i++)
	//{
	//	for (int j = 0; j < MAP_X; j++)
	//	{
	//		//要素番号を座標に変更
	//		float x = j * 64.0f;
	//		float y = i * 64.0f;

	//		//主人公とボックスの当たり判定
	//		if ((hx+64.0f>x)&&(hx<x+64.0f)&&(hy+64.0f>y)&&(hy<y+64.0f))
	//		{
	//			//当たっている場合
	//			hero->SetX(hx);
	//			hero->SetY(0.0f);
	//		}
	//	}
	//}

	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_BREAK_BLOCK, 1);
}

//アクション
void CObjbreakblock::Action()
{

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	CObjUserInterface* count = (CObjUserInterface*)Objs::GetObj(OBJ_USERINTERFACE);
	int Enemycount = count->GetEM();
	

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();
	

	CHitBox* hit = Hits::GetHitBox(this);

	
	int data_base[3] =
	{
		OBJ_ENEMY,
		OBJ_ENEMY3,
		OBJ_GHOST,
	};
	//敵を全員倒したらしたら壁を削除
	if (m_hit == true)
	{
		{

		}
		
		for (int i = 0; i < 3; i++)
		{
			if (hit->CheckObjNameHit(data_base[i]) == nullptr)
			{
				//壁を削除
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
			}
		}
	}
}

//ドロー
void CObjbreakblock::Draw()
{
	float c[4] = { 1.0f,4.0f,2.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 320.0f;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = 64.0f;
	//描画位置の設定
	dst.m_top = 0.0f + m_y + m_scroll_map_y;
	dst.m_left = 0.0f + m_x + m_scroll_map_x;
	dst.m_right = 64.0f + m_x + m_scroll_map_x;
	dst.m_bottom = 64.0f + m_y + m_scroll_map_y;

	//描画
	Draw::Draw(17, &src, &dst, c, 0.0f);
}





