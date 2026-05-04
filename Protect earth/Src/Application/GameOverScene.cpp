#include "GameOverScene.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "Mouse.h"
#include "KeyManager.h"
#include "main.h"

void GameOverScene::Update()
{
	mouse->Update();

	if (changeTitleFlg)
	{
		m_alpha += m_alphaAdd;
		if (m_alpha >= 1.0f)
		{
			m_alpha = 1.0f;
			SCENEM.ChangeState(new TitleScene());
			return;
		}
	}
	else if (changeRetryFlg)
	{
		m_alpha += m_alphaAdd;
		if (m_alpha >= 1.0f)
		{
			m_alpha = 1.0f;
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

		if (mouse->GetPos().x > retryL &&
			mouse->GetPos().x < retryR &&
			mouse->GetPos().y > retryB &&
			mouse->GetPos().y < retryT)
		{
			retryScale += retryScaleAdd;
			if (retryScale >= 1.3f || retryScale <= 0.8f)
			{
				retryScaleAdd *= -1;
			}

			if (KEYM.PushLbutton())
			{
				changeRetryFlg = true;
			}
		}
		else
		{
			retryScale = 1.0f;
			retryScaleAdd = 0.02f;
		}


		if (mouse->GetPos().x > titleL &&
			mouse->GetPos().x < titleR &&
			mouse->GetPos().y > titleB &&
			mouse->GetPos().y < titleT)
		{
			titleScale += titleScaleAdd;
			if (titleScale >= 1.3f || titleScale <= 0.8f)
			{
				titleScaleAdd *= -1;
			}
			
			if (KEYM.PushLbutton())
			{
				changeTitleFlg = true;
			}
		}
		else
		{
			titleScale = 1.0f;
			titleScaleAdd = 0.02f;
		}
	}

	scoreMat5 = Math::Matrix::CreateTranslation(0 - 64, 50, 0);
	scoreMat4 = Math::Matrix::CreateTranslation(0 - 32, 50, 0);
	scoreMat3 = Math::Matrix::CreateTranslation(0, 50, 0);
	scoreMat2 = Math::Matrix::CreateTranslation(0 + 32, 50, 0);
	scoreMat1 = Math::Matrix::CreateTranslation(0 + 64, 50, 0);

	scoreStringMat = Math::Matrix::CreateTranslation(0, 100, 0);

	gameOverMat = Math::Matrix::CreateTranslation(0, 200, 0);

	gameoverbackMat = Math::Matrix::CreateTranslation(0, 0, 0);

	Math::Matrix scale, trans;
	scale = Math::Matrix::CreateScale(titleScale, titleScale, 1.0f);
	trans = Math::Matrix::CreateTranslation(title.x, title.y, 0);
	TitleStringMat = scale * trans;

	scale = Math::Matrix::CreateScale(retryScale, retryScale, 1.0f);
	trans = Math::Matrix::CreateTranslation(retry.x, retry.y, 0);
	RetryMat = scale * trans;
}

void GameOverScene::Draw()
{
	SHADER.m_spriteShader.SetMatrix(gameoverbackMat);
	SHADER.m_spriteShader.DrawTex(&gameOverBackTex, Math::Rectangle{ 0,0,1280,720 }, 1.0f);

	int num5 = score / 10000;

	if (num5 < 6 && num5 != 0)
	{
		scoreXCut5 = num5 - 1;
		scoreYCut5 = 0;
	}

	else if (num5 == 0)
	{
		scoreXCut5 = 4;
		scoreYCut5 = 1;
	}
	else
	{
		scoreXCut5 = num5 - 6;
		scoreYCut5 = 1;
	}
	SHADER.m_spriteShader.SetMatrix(scoreMat5);
	SHADER.m_spriteShader.DrawTex(&scoreTex, Math::Rectangle{ scoreXCut5 * 32,scoreYCut5 * 32,32,32 }, 1.0f);


	int num4 = score % 10000 / 1000;

	if (num4 < 6 && num4 != 0)
	{
		scoreXCut4 = num4 - 1;
		scoreYCut4 = 0;
	}

	else if (num4 == 0)
	{
		scoreXCut4 = 4;
		scoreYCut4 = 1;
	}
	else
	{
		scoreXCut4 = num4 - 6;
		scoreYCut4 = 1;
	}
	SHADER.m_spriteShader.SetMatrix(scoreMat4);
	SHADER.m_spriteShader.DrawTex(&scoreTex, Math::Rectangle{ scoreXCut4 * 32,scoreYCut4 * 32,32,32 }, 1.0f);


	int num3 = score % 10000 % 1000 / 100;

	if (num3 < 6 && num3 != 0)
	{
		scoreXCut3 = num3 - 1;
		scoreYCut3 = 0;
	}

	else if (num3 == 0)
	{
		scoreXCut3 = 4;
		scoreYCut3 = 1;
	}
	else
	{
		scoreXCut3 = num3 - 6;
		scoreYCut3 = 1;
	}
	SHADER.m_spriteShader.SetMatrix(scoreMat3);
	SHADER.m_spriteShader.DrawTex(&scoreTex, Math::Rectangle{ scoreXCut3 * 32,scoreYCut3 * 32,32,32 }, 1.0f);


	int num2 = score % 10000 % 1000 % 100 / 10;
	if (num2 < 6 && num2 != 0)
	{
		scoreXCut2 = num2 - 1;
		scoreYCut2 = 0;
	}
	else if (num2 == 0)
	{
		scoreXCut2 = 4;
		scoreYCut2 = 1;
	}
	else
	{
		scoreXCut2 = num2 - 6;
		scoreYCut2 = 1;
	}

	SHADER.m_spriteShader.SetMatrix(scoreMat2);
	SHADER.m_spriteShader.DrawTex(&scoreTex, Math::Rectangle{ scoreXCut2 * 32,scoreYCut2 * 32,32,32 }, 1.0f);

	int num1 = score % 10000 % 1000 % 100 % 10;
	if (num1 < 6 && num1 != 0)
	{
		scoreXCut1 = num1 - 1;
		scoreYCut1 = 0;
	}
	else if (num1 == 0)
	{
		scoreXCut1 = 4;
		scoreYCut1 = 1;
	}
	else
	{
		scoreXCut1 = num1 - 6;
		scoreYCut1 = 1;
	}
	SHADER.m_spriteShader.SetMatrix(scoreMat1);
	SHADER.m_spriteShader.DrawTex(&scoreTex, Math::Rectangle{ scoreXCut1 * 32,scoreYCut1 * 32,32,32 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(scoreStringMat);
	SHADER.m_spriteShader.DrawTex(&scoreStringTex, Math::Rectangle{ 0,0,87,30 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(gameOverMat);
	SHADER.m_spriteShader.DrawTex(&GameOverTex, Math::Rectangle{ 0,0,431,96 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(TitleStringMat);
	SHADER.m_spriteShader.DrawTex(&TitleStringTex, Math::Rectangle{ 0, 0, 160,55 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(RetryMat);
	SHADER.m_spriteShader.DrawTex(&RetryTex, Math::Rectangle{ 0, 0, 160,64 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);

	Math::Color color = { 0,0,0,m_alpha };
	SHADER.m_spriteShader.DrawBox(0, 0, 640, 360, &color, true);
}

void GameOverScene::Init()
{
	gameOverBackTex.Load("Texture/collapseCity.png");
	GameOverTex.Load("Texture/GAME OVER.png");
	scoreTex.Load("Texture/ScoreNumber.png");
	scoreStringTex.Load("Texture/ScoreString.png");
	TitleStringTex.Load("Texture/TitleString.png");
	RetryTex.Load("Texture/Retry.png");

	score = SCENEM.GetScore();

	mouse = new MOUSE;
	mouse->Init();

	scoreXCut1 = 0;
	scoreXCut2 = 0;
	scoreXCut3 = 0;
	scoreXCut4 = 0;
	scoreXCut5 = 0;

	scoreYCut1 = 0;
	scoreYCut2 = 0;
	scoreYCut3 = 0;
	scoreYCut4 = 0;
	scoreYCut5 = 0;

	title = { 0,-50 };
	retry = { 5,-150 };

	titleRadius = { 80.0f,27.5f };
	retryRadius = { 80.0f,32.0f };

	titleR = title.x + titleRadius.x;
	titleL = title.x - titleRadius.x;
	titleT = title.y + titleRadius.y;
	titleB = title.y - titleRadius.y;

	retryR = retry.x + retryRadius.x;
	retryL = retry.x - retryRadius.x;
	retryT = retry.y + retryRadius.y;
	retryB = retry.y - retryRadius.y;

	titleScale = 1.0f;
	retryScale = 1.0f;

	titleScaleAdd = 0.02f;
	retryScaleAdd = 0.02f;

	m_alpha = 1.0f;
	m_alphaAdd = 0.03f;

	changeTitleFlg = false;
	changeRetryFlg = false;
}

void GameOverScene::Release()
{
	GameOverTex.Release();
	gameOverBackTex.Release();
	scoreTex.Release();
	scoreStringTex.Release();

	if (mouse)
	{
		delete mouse;
	}
}
