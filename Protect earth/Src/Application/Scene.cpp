#include "main.h"
#include "Scene.h"
#include "SceneManager.h"
#include "TitleScene.h"

void Scene::Draw2D()
{
	SCENEM.Draw();
}

void Scene::Update()
{
	SCENEM.Update();
}

void Scene::Init()
{
	SCENEM.ChangeState(new TitleScene());
}

void Scene::Release()
{
	SCENEM.Release();
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
