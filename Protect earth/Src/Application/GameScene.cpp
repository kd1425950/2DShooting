#include "GameScene.h"
#include "ResultScene.h"
#include "GameOverScene.h"
#include "SceneManager.h"
#include "player.h"
#include "Mouse.h"
#include "Shot.h"
#include "Meteo.h"
#include "Particle.h"
#include "Skill.h"
#include "Earth.h"
#include "Score.h"

void GameScene::Update()
{
	if (changeGOFlg)
	{
		m_alpha += m_alphaAdd;
		if (m_alpha >= 1.0f)
		{
			m_alpha = 1.0f;
			SCENEM.ChangeState(new GameOverScene());
			return;
		}
	}
	else if (changeResultFlg)
	{
		m_alpha += m_alphaAdd;
		if (m_alpha >= 1.0f)
		{
			m_alpha = 1.0f;
			SCENEM.ChangeState(new ResultScene());
			return;
		}
	}
	else
	{
		m_alpha -= m_alphaAdd;
		if (m_alpha <= 0.0f)
		{
			m_alpha = 0.0f;
		}
	}

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

	if (earth->Update())
	{
		changeGOFlg = true;
	}

	score->Update();

	frame--;
	Time = frame / 60;

	Timer();

	if (frame <= 0.0f)
	{
		frame = 0.0f;
		changeResultFlg = true;
	}

	std::string minFilename = "Texture/" + std::to_string(min) + ".png";
	minTex.Load(minFilename);

	std::string secFilename = "Texture/" + std::to_string(sec) + ".png";
	secTex.Load(secFilename);

	std::string sec10Filename = "Texture/" + std::to_string(sec10) + ".png";
	sec10Tex.Load(sec10Filename);


	Math::Matrix scale, trans;

	//分
	scale = Math::Matrix::CreateScale(1.3, 1.5, 0);
	trans = Math::Matrix::CreateTranslation(460, 320, 0);
	minMat = scale * trans;

	//秒(1の位)
	scale = Math::Matrix::CreateScale(1.3, 1.5, 0);
	trans = Math::Matrix::CreateTranslation(610, 320, 0);
	secMat = scale * trans;

	//秒(10の位)
	scale = Math::Matrix::CreateScale(1.3, 1.5, 0);
	trans = Math::Matrix::CreateTranslation(560, 320, 0);
	sec10Mat = scale * trans;

	//：
	scale = Math::Matrix::CreateScale(1.3, 1.5, 0);
	trans = Math::Matrix::CreateTranslation(510, 310, 0);
	semiMat = scale * trans;

}

void GameScene::Draw()
{
	earth->Draw();

	for (auto m : meteo)
	{
		m->Draw();
	}

	score->Draw();

	player->Draw();

	shot->Draw();

	for (auto p : particle)
	{
		p->Draw();
	}

	//skill->Draw();

	SHADER.m_spriteShader.SetMatrix(minMat);
	SHADER.m_spriteShader.DrawTex(&minTex, Math::Rectangle(0, 0, 36, 64), 1);

	SHADER.m_spriteShader.SetMatrix(sec10Mat);
	SHADER.m_spriteShader.DrawTex(&sec10Tex, Math::Rectangle(0, 0, 36, 64), 1);

	SHADER.m_spriteShader.SetMatrix(secMat);
	SHADER.m_spriteShader.DrawTex(&secTex, Math::Rectangle(0, 0, 36, 64), 1);

	SHADER.m_spriteShader.SetMatrix(semiMat);
	SHADER.m_spriteShader.DrawTex(&semiTex, Math::Rectangle(0, 0, 36, 64), 1);


	SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);

	Math::Color color = { 0,0,0,m_alpha };
	SHADER.m_spriteShader.DrawBox(0, 0, 640, 360, &color, true);
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

	//for (int p = 0;p < particleNum; p++)
	//{
	//	Particle* part = new Particle();
	//	particle.push_back(part);
	//}

	skill = new SKILL();

	earth = new Earth();

	mouse = new MOUSE();

	score = new Score();

	//プレイヤー初期化
	player->Init(mouse);
	playerTex.Load("Texture/reticle.png");
	player->SetTex(&playerTex);

	//ショット初期化
	shot->Init(mouse);
	shotTex.Load("Texture/explosion.png");
	shotUiTex.Load("Texture/Magnum.png");
	shotUiTex2.Load("Texture/missileUI.png");
	shot->SetTex(&shotTex);
	shot->SetTexUI(&shotUiTex);
	shot->SetTexUI2(&shotUiTex2);

	//隕石初期化
	for (auto m : meteo)
	{
		m->Init();
		meteoTex.Load("Texture/meteo.png");
		m->SetTex(&meteoTex);
	}

	//スキル初期化
	skill->Init();

	//アース初期化
	earth->Init();

	//スコア初期化
	score->Init();

	//背景初期化
	//backTex.Load("Texture/BackGround.png");

	//マウス初期化
	mouse->Init();

	//アニメーション用アルファ値
	m_alpha = 1.0f;
	m_alphaAdd = 0.03f;

	//シーン遷移フラグ
	changeGOFlg = false;
	changeResultFlg = false;

	//タイム処理初期化
	frame = 10860.0f;
	//frame = 600;
	Time = 0.0f;

	sec = 0.0f;
	sec10 = 0.0f;
	min = 0.0f;

	std::string minFilename = "Texture/" + std::to_string(min) + ".png";
	minTex.Load(minFilename);

	std::string secFilename = "Texture/" + std::to_string(sec) + ".png";
	secTex.Load(secFilename);

	std::string sec10Filename = "Texture/" + std::to_string(sec10) + ".png";
	sec10Tex.Load(sec10Filename);

	semiTex.Load("Texture/semi.png");
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
	score->Release();
	minTex.Release();
	secTex.Release();
	sec10Tex.Release();

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

	delete score;

	if (mouse)
	{
		delete mouse;
	}
}

void GameScene::Timer()
{
	min = Time / 60;
	mod = Time % 60;
	sec10 = mod / 10;
	sec = mod - 10 * sec10;
}
