#include "TitleScene.h"
#include "SceneManager.h"
#include "GameScene.h"

void TitleScene::Update()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		SCENEM.ChangeState(new GameScene());
		return;
	}
}

void TitleScene::Draw()
{
	//背景描画
	SHADER.m_spriteShader.SetMatrix(Math::Matrix::CreateTranslation(0, 0, 0));
	SHADER.m_spriteShader.DrawTex(&titleBackTex, Math::Rectangle(0, 0, 1280, 720), 1.0f);

	//タイトル描画
	SHADER.m_spriteShader.SetMatrix(Math::Matrix::CreateTranslation(0, 200, 0));
	SHADER.m_spriteShader.DrawTex(&titleTex, Math::Rectangle(0, 0, 621, 83), 1.0f);
}

void TitleScene::Init()
{
	m_alpha = 0.0f;
	m_alphaAdd = 0.01f;

	titleTex.Load("Texture/Title.png");
	titleBackTex.Load("Texture/BackGround.png");
}

void TitleScene::Release()
{
	titleTex.Release();
	titleBackTex.Release();
}
