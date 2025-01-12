﻿//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitboxManager.h"
#include "GameHead.h"
#include "CObjAngleBullet.h"



//使用するゲームスペース
using namespace GameL;


//コンストラクタ
CObjAngleBullet::CObjAngleBullet(float x, float y, float r)
{
    m_x = x;
    m_y = y;
    m_r = r;
}


//イニシャライズ
void CObjAngleBullet::Init()
{


    //スクロールした分のベクトルを取得
    CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
    m_scroll_map_x = block->GetSX();
    m_scroll_map_y = block->GetSY();

    
    //当たり判定用ヒットボックスを作成
    Hits::SetHitBox(this, m_x+m_scroll_map_x, m_y+m_scroll_map_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY_BULLET, 1);
}


//アクション
void CObjAngleBullet::Action()
{

    //スクロールした分のベクトルを取得
    CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
    m_scroll_map_x = block->GetSX();
    m_scroll_map_y = block->GetSY();


    CHitBox* hit = Hits::GetHitBox(this);
    //移動
    m_vx = cos(3.14 / 180.0f * m_r);
    m_vy = sin(3.14 / 180.0f * m_r);
    
    m_x += m_vx;
    m_y += m_vy;

    mx += m_vx;
    my += m_vy;


    //HitBoxの内容を更新
   
    hit->SetPos(m_x + m_scroll_map_x, m_y + m_scroll_map_y);

    m_x += m_scroll_map_x;
    m_y += m_scroll_map_y;

    //壁と当たっているか調べる関数
    block->BlockHit(&m_x, &m_y, &m_up, &m_down, &m_reft, &m_right, &m_vx, &m_vy);

    m_x -= m_scroll_map_x;
    m_y -= m_scroll_map_y;

    //boolでtureなら当たり判定削除
    int data_base[4] =
    {
        m_up,m_down,m_reft,m_right
    }; 
    for (int i = 0; i <= 3; i++)
    {
        if (data_base[i] == true)
        {
            this->SetStatus(false);
            Hits::DeleteHitBox(this);
        }
    }
 

    //主人公と接触しているかどうか調べる
    if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
    {
        Effect* effect = new Effect(m_x, m_y,m_r);
        Objs::InsertObj(effect, OBJ_EFFECT, 20);

        this->SetStatus(false);//削除命令
        Hits::DeleteHitBox(this);//削除
    }
    //主人公（人）と接触しているか調べる
    else if (hit->CheckObjNameHit(OBJ_CHARA) != nullptr)
    {
        Effect* effect = new Effect(m_x, m_y,m_r);
        Objs::InsertObj(effect, OBJ_EFFECT, 20);

        this->SetStatus(false);//削除命令
        Hits::DeleteHitBox(this);//削除
    }
    ////弾丸と接触しているかを調べる
    //if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
    //{
    //	this->SetStatus(false);//自身に削除命令を出す
    //	Hits::DeleteHitBox(this);//弾丸が所有するHitBoxに削除する。
    //}

    else if (mx >= 500.0f || mx <= -500.0f || my >= 500.0f || my <= -500.0f)
    {
        this->SetStatus(false);//削除命令
        Hits::DeleteHitBox(this);//削除
    }

}


//ドロー
void CObjAngleBullet::Draw()
{
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };
    
    RECT_F src;//描画切り取り位置
    RECT_F dst;//描画表示位置

    //切り取り位置
    src.m_top = 0.0f;
    src.m_left = 0.0f;
    src.m_right = 200.0f;
    src.m_bottom = 200.0f;

    //表示位置
    dst.m_top = 0.0f + m_y + m_scroll_map_y;
    dst.m_left = 0.0f + m_x + m_scroll_map_x;
    dst.m_right = 32.0f + m_x + m_scroll_map_x;
    dst.m_bottom = 32.0f + m_y + m_scroll_map_y;
    
    Draw::Draw(2, &src, &dst,c, m_r);
           
}