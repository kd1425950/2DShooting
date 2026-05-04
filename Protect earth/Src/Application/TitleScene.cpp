#include "TitleScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "Mouse.h"
#include "KeyManager.h"
#include "main.h"

void TitleScene::Update()
{
	mouse->Update();

	if (changeFlg)
	{
		m_alpha += m_alphaAdd;
		if (m_alpha >= 1.0f)
		{
			m_alpha = 1.0f;
		}

		if (m_alpha >= 1.0f)
		{
			SCENEM.ChangeState(new GameScene());
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

		if (mouse->GetPos().x > playL &&
			mouse->GetPos().x < playR &&
			mouse->GetPos().y > playB &&
			mouse->GetPos().y < playT)
		{
			playScale += playScaleAdd;

			if (playScale >= 1.3f || playScale <= 0.8f)
			{
				playScaleAdd *= -1;
			}

			if (KEYM.PushLbutton())
			{
				changeFlg = true;
			}
		}
		else
		{
			playScale = 1.0f;
			playScaleAdd = 0.02f;
		}

		if (mouse->GetPos().x > exitL &&
			mouse->GetPos().x < exitR &&
			mouse->GetPos().y > exitB &&
			mouse->GetPos().y < exitT)
		{
			exitScale += exitScaleAdd;

			if (exitScale >= 1.3f || exitScale <= 0.8f)
			{
				exitScaleAdd *= -1;
			}

			if (KEYM.PushLbutton())
			{
				APP.End();
				return;
			}
		}
		else
		{
			exitScale = 1.0f;
			exitScaleAdd = 0.02f;
		}
	}



	Math::Matrix trans, scale;

	trans = Math::Matrix::CreateTranslation(0, 200, 0);
	scale = Math::Matrix::CreateScale(1.0f, 1.0f, 1.0f);
	titleMat = scale * trans;

	trans = Math::Matrix::CreateTranslation(0, 0, 0);
	scale = Math::Matrix::CreateScale(1.0f, 1.0f, 1.0f);
	titleBackMat = scale * trans;

	trans = Math::Matrix::CreateTranslation(play.x, play.y, 0);
	scale = Math::Matrix::CreateScale(playScale, playScale, 1.0f);
	PlayMat = scale * trans;

	trans = Math::Matrix::CreateTranslation(exit.x, exit.y, 0);
	scale = Math::Matrix::CreateScale(exitScale, exitScale, 1.0f);
	ExitMat = scale * trans;


}

void TitleScene::Draw()
{
	//背景描画
	SHADER.m_spriteShader.SetMatrix(titleBackMat);
	SHADER.m_spriteShader.DrawTex(&titleBackTex, Math::Rectangle(0, 0, 1280, 720), 1.0f);

	//タイトル描画
	SHADER.m_spriteShader.SetMatrix(titleMat);
	SHADER.m_spriteShader.DrawTex(&titleTex, Math::Rectangle(0, 0, 621, 83), 1.0f);

	//選択肢
	//Play
	SHADER.m_spriteShader.SetMatrix(PlayMat);
	SHADER.m_spriteShader.DrawTex(&PlayTex, Math::Rectangle(0, 0, 125, 59), 1.0f);

	//Exit
	SHADER.m_spriteShader.SetMatrix(ExitMat);
	SHADER.m_spriteShader.DrawTex(&ExitTex, Math::Rectangle(0, 0, 124, 56), 1.0f);


	SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);

	Math::Color color = { 0,0,0,m_alpha };
	SHADER.m_spriteShader.DrawBox(0,0,640,360,&color,true);
}

void TitleScene::Init()
{
	mouse = new MOUSE;
	mouse->Init();

	m_alpha = 1.0f;
	m_alphaAdd = 0.03f;

	titleTex.Load("Texture/Title.png");
	titleBackTex.Load("Texture/BackGround.png");
	PlayTex.Load("Texture/Play.png");
	ExitTex.Load("Texture/Exit.png");

	play = { 0,0 };
	exit = { 0,-100 };

	playScale = 1.0f;
	playScaleAdd = 0.02f;

	exitScale = 1.0f;
	exitScaleAdd = 0.02f;

	playRadiusX = 62.5f;
	exitRadiusX = 62.0f;

	playRadiusY = 29.5;
	exitRadiusY = 28.0f;

	playR = play.x + playRadiusX;
	playL = play.x - playRadiusX;
	playT = play.y + playRadiusY;
	playB = play.y - playRadiusY;

	exitR = exit.x + exitRadiusX;
	exitL = exit.x - exitRadiusX;
	exitT = exit.y + exitRadiusY;
	exitB = exit.y - exitRadiusY;

	changeFlg = false;
}

void TitleScene::Release()
{
	titleTex.Release();
	titleBackTex.Release();
	PlayTex.Release();
	ExitTex.Release();

	if (mouse)
	{
		delete mouse;
	}
}
