#pragma once
#include "player.h"
#include "Mouse.h"
#include "Shot.h"

class Scene
{
private:

	// テクスチャ ・・・ 画像データ
	KdTexture playerTex;
	KdTexture shotTex;
	KdTexture backTex;

	Math::Matrix backMat;

	//インスタンス
	Player player;
	MOUSE mouse;
	SHOT shot;

public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();

	// GUI処理
	void ImGuiUpdate();

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
