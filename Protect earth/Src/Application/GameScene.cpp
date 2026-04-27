#include "GameScene.h"
#include "ResultScene.h"
#include "SceneManager.h"
#include "player.h"
#include "Mouse.h"
#include "Shot.h"
#include "Meteo.h"
#include "Particle.h"
#include "Skill.h"
#include "Earth.h"

void GameScene::Update()
{
	player->Update(mouse);

	shot->Update(mouse);

	for (auto m : meteo)
	{
		m->Update();
	}

	for (auto p : particle)
	{
		p->Update();
	}
	
	skill->Update();

	mouse->Update();

	shot->BulletMeteoHit();

	earth->Update();
}

void GameScene::Draw()
{
	earth->Draw();

	for (auto m : meteo)
	{
		m->Draw();
	}

	player->Draw();

	shot->Draw();

	for (auto p : particle)
	{
		p->Draw();
	}

	skill->Draw();
}

void GameScene::Init()
{
	srand(timeGetTime());

	player = new Player();
	shot = new SHOT();

	for (int m = 0;m < meteoNum;m++)
	{
		METEO* met = new METEO();
		meteo.push_back(met);
	}

	for (int p = 0;p < particleNum; p++)
	{
		Particle* part = new Particle();
		particle.push_back(part);
	}

	skill = new SKILL();

	earth = new Earth();

	mouse = new MOUSE();

	//プレイヤー初期化
	player->Init(mouse);
	playerTex.Load("Texture/reticle.png");
	player->SetTex(&playerTex);

	//ショット初期化
	shot->Init(mouse);
	shotTex.Load("Texture/explosion.png");
	shot->SetTex(&shotTex);

	//隕石初期化
	for (auto m : meteo)
	{
		m->Init();
		meteoTex.Load("Texture/meteo.png");
		m->SetTex(&meteoTex);
	}

	//パーティクル初期化
	for (auto p : particle)
	{
		p->Init();
		particleTex.Load("Texture/MeteoBreak.png");
		p->SetTex(&particleTex);
	}

	skill->Init();

	earth->Init();

	//背景初期化
	backTex.Load("Texture/BackGround.png");

	//マウス初期化
	mouse->Init();
}

void GameScene::Release()
{
	// 画像の解放処理
	playerTex.Release();
	shotTex.Release();
	backTex.Release();
	meteoTex.Release();
	particleTex.Release();
	earth->Release();
	skill->Release();

	//インスタンス解放
	if (player)
	{
		delete player;
	}

	if (shot)
	{
		delete shot;
	}

	for (auto m : meteo)
	{
		if (m)
		{
			delete m;
		}
	}

	for (auto p : particle)
	{
		if (p)
		{
			delete p;
		}
	}

	delete skill;

	delete earth;

	if (mouse)
	{
		delete mouse;
	}
}
