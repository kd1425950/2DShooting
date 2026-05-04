#include "Skill.h"
#include "Meteo.h"
#include "GameScene.h"
#include "SceneManager.h"

void SKILL::Update()
{
	std::vector<METEO*> meteo = game->GetMeteo();

	for (auto m : meteo)
	{
		Math::Vector2 meteoMove = m->GetMove();

		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
   			meteoMove.y = -0.5f;
			m->SetMove(meteoMove);
		}
	}

	skillMat = Math::Matrix::CreateScale(0.7f, 0.7f, 0) * Math::Matrix::CreateTranslation(500, -310, 0);
	spaceMat = Math::Matrix::CreateScale(0.7f, 0.7f, 0) * Math::Matrix::CreateTranslation(500, -230, 0);
}

void SKILL::Draw()
{
	Math::Rectangle skillRect = { 0,0,128,128 };
	Math::Rectangle spaceRect = { 0,0,128,64 };
	
	
	SHADER.m_spriteShader.SetMatrix(skillMat);
	SHADER.m_spriteShader.DrawTex(&skillTex,skillRect,1.0f);

	SHADER.m_spriteShader.SetMatrix(spaceMat);
	SHADER.m_spriteShader.DrawTex(&spaceTex,spaceRect,1.0f);
}

void SKILL::Init()
{
	skillTex.Load("Texture/slomotionUI.png");
	spaceTex.Load("Texture/spaceUI.png");

	game = static_cast<GameScene*>(SCENEM.GetState());
}

void SKILL::Release()
{
	skillTex.Release();
	spaceTex.Release();
}
