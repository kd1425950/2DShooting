#pragma once
#include "player.h"
#include "Mouse.h"
#include "Shot.h"
#include "Meteo.h"
#include "Particle.h"

class Scene
{
private:


	// テクスチャ ・・・ 画像データ
	KdTexture playerTex;
	KdTexture shotTex;
	KdTexture meteoTex;
	KdTexture backTex;
	KdTexture particleTex;

	Math::Matrix backMat;

	//インスタンス
	Player player;
	MOUSE mouse;
	SHOT shot;
	METEO meteo;
	Particle particle;

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
