#include "main.h"
#include "Scene.h"
#include "player.h"
#include "Mouse.h"
#include "Shot.h"
#include "Meteo.h"
#include "Particle.h"

void Scene::Draw2D()
{
	SHADER.m_spriteShader.SetMatrix(backMat);
	SHADER.m_spriteShader.DrawTex(&backTex, Math::Rectangle(0, 0, 1280, 720), 1.0f);

	//for(int m=0;m<meteoNum;m++)
	//{
	//	meteo[m]->Draw();
	//}]
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
	//for(int p=0;p<particleNum;p++)
	//{
	//	particle[p]->Draw();
	//}
}

void Scene::Update()
{
	player->Update(mouse);
	shot->Update(mouse);

	//for (int m = 0;m < meteoNum;m++)
	//{
	//	meteo[m]->Update();
	//}

	for (auto m : meteo)
	{
		m->Update();
	}

	//for (int p = 0;p < particleNum;p++)
	//{
	//	particle[p]->Update();
	//}

	for(auto p:particle)
	{
		p->Update();
	}
	mouse->Update();

	shot->BulletMeteoHit();
	

	backMat = Math::Matrix::CreateTranslation(0, 0, 0);
}

void Scene::Init()
{
	srand(timeGetTime());

	player = new Player();
	shot = new SHOT();
	//for(int m=0;m<meteoNum;m++)
	//{
	//	meteo[m] = new METEO();
	//}
	for (int m = 0;m < meteoNum;m++)
	{
		METEO* met = new METEO();
		meteo.push_back(met);
	}
	//for(int p=0;p<particleNum;p++)
	//{
	//	particle[p] = new Particle();
	//}
	for (int p = 0;p < particleNum ; p++)
	{
		Particle* part = new Particle();
		particle.push_back(part);
	}
	mouse = new MOUSE();

	player->Init(mouse);
	playerTex.Load("Texture/reticle.png");
	player->SetTex(&playerTex);

	shot->Init(mouse);
	shotTex.Load("Texture/explosion.png");
	shot->SetTex(&shotTex);

	//for (int m = 0;m < meteoNum;m++)
	//{
	//	meteo[m]->Init();
	//	meteoTex[m].Load("Texture/meteo.png");
	//	meteo[m]->SetTex(&meteoTex[m]);
	//}

	for (auto m : meteo)
	{
		m->Init();
		meteoTex.Load("Texture/meteo.png");
		m->SetTex(&meteoTex);
	}

	//for (int p = 0;p < particleNum;p++)
	//{
	//	particle[p]->Init();
	//	particleTex[p].Load("Texture/MeteoBreak.png");
	//	particle[p]->SetTex(&particleTex[p]);
	//}

	for(auto p:particle)
	{
		p->Init();
		particleTex.Load("Texture/MeteoBreak.png");
		p->SetTex(&particleTex);
	}


	backTex.Load("Texture/BackGround.png");

	mouse->Init();
}

void Scene::Release()
{
	// 画像の解放処理
	playerTex.Release();
	shotTex.Release();
	backTex.Release();

	//for (int m = 0;m < meteoNum;m++)
	//{
	//	meteoTex[m].Release();
	//}
	meteoTex.Release();
	//for (int p = 0;p < particleNum;p++)
	//{
	//	particleTex[p].Release();
	//}
	particleTex.Release();

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

	for(auto p:particle)
	{
		if (p)
		{
			delete p;
		}
	}

	if (mouse)
	{
		delete mouse;
	}
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
