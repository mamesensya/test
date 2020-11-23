//使用するヘッダーファイル

#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

//変数の値を監視するためのDrawFont
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "Objblock.h"
#include"Objbreakblock.h"

//デバッグ用にインクルードするヘッダー
#include "GameL\DrawFont.h"
#include"GameL/HitBoxManager.h"

//使用するネームスペース

using namespace GameL;

CObjBlock::CObjBlock(int map[60][80])
{
	memcpy(m_map, map, sizeof(int) * (60 * 80));
}

//イニシャライズ
void CObjBlock::Init()

{
	m_scroll = 0.0f;
	m_scroll2 = 0.0f;
}

//アクション
void CObjBlock::Action()
{
	//	主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//右方スクロールライン
	if (hx < 80)
	{
		hero->SetX(80);
		m_scroll -= hero->GetVX();
	}

	//左方スクロールライン
	if (hx > 300)
	{
		hero->SetX(300);
		m_scroll -= hero->GetVX();
	}
	//上方スクロールライン
	if (hy < 80)
	{
		hero->SetY(80);
		m_scroll2 -= hero->GetVY();
	}

	//下方スクロールライン
	if (hy > 300)
	{
		hero->SetY(300);
		m_scroll2 -= hero->GetVY();
	}

	//敵出現ライン
	//主人公の位置＋500を敵出現ラインにする
	float line = hx + (-m_scroll) + 500;
	
	//敵出現ラインを要素番号化
	int ex = ((int)line) / 64;

	//敵出現ラインの列を検索
	for (int i = 0; i < 80; i++)
	{
		//列の中から4を探す
		if (m_map[i][ex] == 4)
		{
			//4があれば、敵を出現
			CObjEnemy* obje = new CObjEnemy(ex * 64.0f, i * 64.0f);
			Objs::InsertObj(obje, OBJ_ENEMY, 50);

			//敵出現場所の値を0にする
			m_map[i][ex] = 0;
		}

		//列の中から6を探す
		if (m_map[i][ex] == 6)
		{
			//6があれば、散弾敵を出現
			CObjEnemy3* obje = new CObjEnemy3(ex * 64.0f, i * 64.0f);
			Objs::InsertObj(obje, OBJ_ENEMY3, 51);

			//敵出現場所の値を0にする
			m_map[i][ex] = 0;
		}
		//列の中から5を探す
		if (m_map[i][ex] == 5)
		{
			//5があれば、ボスを出現
			CObjBoss* obje = new CObjBoss(ex * 64.0f, i * 64.0f);
			Objs::InsertObj(obje, OBJ_BOSS, 51);

			//敵出現場所の値を0にする
			m_map[i][ex] = 0;
		}
		//列の中から7を探す
		if (m_map[i][ex] == 7)
		{
			//7があれば、ボス2を出現
			CObjEnemy3* obje = new CObjEnemy3(ex * 64.0f, i * 64.0f);
			Objs::InsertObj(obje, OBJ_ENEMY3, 51);

			//敵出現場所の値を0にする
			m_map[i][ex] = 0;
		}
		//列の中から3を探す
		if (m_map[i][ex] == 3)
		{
			//3があれば、壊れる壁を出現
			CObjbreakblock* obj_break_block = new CObjbreakblock(ex * 64.0f, i * 64.0f);
			Objs::InsertObj(obj_break_block, OBJ_BREAK_BLOCK, 17);


			//敵出現場所の値を0にする
			m_map[i][ex] = 0;
		}
		//列の中から2を探す
		if (m_map[i][ex] == 2)
		{
			//2があれば箱を出現
			CObjBox* obj_box = new CObjBox(ex*64.0f,i*64.0f);
			Objs::InsertObj(obj_box, OBJ_BOX, 11);

			//敵出現場所の値を0にする
			m_map[i][ex] = 0;
		}
	}
}

//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	////背景表示
	//src.m_top = 0.0f;
	//src.m_left = 0.0f;
	//src.m_right = 800.0f;
	//src.m_bottom = 560.0f;
	//dst.m_top = 0.0f+m_scroll2;
	//dst.m_left = 0.0f+m_scroll;
	//dst.m_right = 800.0f+m_scroll;
	//dst.m_bottom = 600.0f+m_scroll2;
	//Draw::Draw(3, &src, &dst, c, 0.0f);





	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (m_back[i][j] == 0 )
			{
				//表示位置の設定
				dst.m_top = i * 600.0f + m_scroll2;
				dst.m_left = j * 800.0f + m_scroll;
				dst.m_right = dst.m_left + 800.0;
				dst.m_bottom = dst.m_top + 600.0;
				






				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 800.0f;
				src.m_bottom =600.0f;
				

				//描画
				Draw::Draw(3, &src, &dst, c, 0.0f);
			}
		}
	}






	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 320.0f;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = 64.0f;



	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 7 && m_map[i][j] != 6 && m_map[i][j] != 5 &&m_map[i][j]!=4&& m_map[i][j] != 3 && m_map[i][j] != 2)
			{
				//表示位置の設定
				dst.m_top = i * 64.0f + m_scroll2;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;
				if (m_map[i][j] == 2)
				{
					;
				}
				else if(m_map[i][j]==3)
				{
					;
				}
				else if (m_map[i][j] == 4)
				{
					;
				}
				else if (m_map[i][j] == 5)
				{
					;
				}
				else if (m_map[i][j] == 6)
				{
					;
				}
				else if (m_map[i][j] == 7)
				{
					;
				}
				else
				{
					src.m_top = 0.0f;
					src.m_left = 320.0f;
					src.m_right = src.m_left + 64.0f;
					src.m_bottom = 64.0f;
				}

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}
		}
	}
}


//BlockHit関数
//引数1 float* x        :判定を行うobjectのX位置
//引数2 float* y        :判定を行うobjectのY位置
//引数3 bool* up        :上下左右判定の上部分に当たっているかどうかを返す
//引数4 bool* down      :下部分に当たっているかを返す
//引数5 bool* left      :左部分に当たっているかを返す
//引数6 bool* right     :右部分に当たっているかを返す
//引数7 float* vx       :左右判定時の反発による移動方向・力の値を変えて返す
//引数8 float* vy       :上下判定時による移動方向・力の値を変えて返す
void CObjBlock::BlockHit(
	float* x, float* y, bool* up, bool* down,
	bool* left, bool* right, float* vx, float* vy
)
{

	*up = false;
	*down = false;
	*left = false;
	*right = false;


	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (m_map[i][j] == 1)
			{
				//要素番号を座標に変換
				float bx = j * 64.0f;
				float by = i * 64.0f;

				//主人公とブロックのあたり判定
				if ((*x + (-m_scroll) + 64.0f > bx) && (*x + (-m_scroll) < bx + 64.0f) && (*y + (-m_scroll2) + 64.0f > by) && (*y + (-m_scroll2) < by + 64.0f))
				{
					//上下左右の判定

					//vectorのさくせい
					float rvx = (*x + (-m_scroll)) - bx;
					float rvy = (*y + (-m_scroll2)) - by;

					//長さを求める
					float len = sqrt(rvx * rvx + rvy * rvy);

					float r = atan2(rvy, rvx);
					r = r * 180.0f / 3.14f;


					if (r < 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					if (len < 88.0f)
					{


						//角度で上下左右を判定
						if ((r < 45 && r>0) || r > 315)
						{
							//右
							*right = true;
							*x = bx + 64.0f + (m_scroll);
							*vx = -(*vx) * 0.1f;


						}
						if (r > 45 && r < 135)
						{
							//上
							*down = true;
							*y = by - 64.0f + (m_scroll2);
							*vy = -(*vy)*0.1f;



						}
						if (r > 135 && r < 225)
						{
							//左
							*left = true;
							*x = bx - 64.0f + (m_scroll);
							*vx = -(*vx) * 0.1f;




						}
						if (r > 225 && r < 315)
						{
							//下
							*up = true;
							*y = by + 64.0f + (m_scroll2);
							*vy = -(*vy) * 0.1f;

							
						}

					}

				}




			}



		}
	}

}