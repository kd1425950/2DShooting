#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	SHADER.m_spriteShader.SetMatrix(backMat);
	SHADER.m_spriteShader.DrawTex(&backTex, Math::Rectangle(0, 0, 1280, 720), 1.0f);

	player.Draw();
	shot.Draw();
}

void Scene::Update()
{
	player.Update(&mouse);
	shot.Update(&mouse);
	mouse.Update();

	backMat = Math::Matrix::CreateTranslation(0, 0, 0);
}

void Scene::Init()
{
	player.Init(&mouse);
	playerTex.Load("Texture/reticle.png");
	player.SetTex(&playerTex);

	shot.Init(&mouse);
	shotTex.Load("Texture/explosion.png");
	shot.SetTex(&shotTex);

	backTex.Load("Texture/BackGround.png");

	mouse.Init();
}

void Scene::Release()
{
	// 画像の解放処理
	playerTex.Release();
	shotTex.Release();
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
