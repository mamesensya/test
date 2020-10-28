//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//初期化メソッド
void CSceneMain::InitScene()
{
	Draw::LoadImage(L"red.jpg", 0, TEX_SIZE_512);
	//敵の弾（BB弾）
	Draw::LoadImageW(L"EnemyBB.png", 2, TEX_SIZE_512);


	//敵戦車
	Draw::LoadImageW(L"敵_戦車2.png", 1, TEX_SIZE_512);
	CObjEnemy* obj_enemy = new CObjEnemy(350,250);
	Objs::InsertObj(obj_enemy, OBJ_ENEMY, 50);

	//主人公グラフィック読み込み
	Draw::LoadImageW(L"主人公_戦車.png", 0, TEX_SIZE_512);
	//主人公
	CObjHero* obj = new CObjHero(0,0);
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//鬼
	Draw::LoadImageW(L"仮おに.jpg", 4, TEX_SIZE_512);
	CObjGhost* obj_ghost = new CObjGhost();
	Objs::InsertObj(obj_ghost, OBJ_GHOST, 4);


	Draw::LoadImageW(L"hako.png", 13, TEX_SIZE_512);

	Draw::LoadImageW(L"yuka.png", 3, TEX_SIZE_512);

	Draw::LoadImageW(L"大豆.jpg", 14, TEX_SIZE_512);
	//CObjBlock* obj_block = new CObjBlock;
	//Objs::InsertObj(obj_block, OBJ_BLOCK, 9);

	

}

//実行中メソッド
void CSceneMain::Scene()
{

}