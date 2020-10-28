#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_HERO,
	OBJ_ENEMY,
	OBJ_ENEMY_BULLET,
	OBJ_BLOCK,
	OBJ_ANGLE_BULLET,
	OBJ_GHOST,
	OBJ_PENETRATE_BULLET,
	OBJ_HERO_HUMAN,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjHero.h"
#include"Enemy.h"
#include"CObjEnemyBullet.h"
#include"Objblock.h"
#include"CObjPlayerBullet.h"
#include"obj ghost.h"
#include "Enemy.h"
#include "CObjEnemyBullet.h"
#include "Objblock.h"
#include "CObjPlayerBullet.h"
#include "CObjpenetrateBullet.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------



//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneMain
//-----------------------------------------------