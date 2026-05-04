#include "Score.h"

void Score::Update()
{
	scoreMat5 = Math::Matrix::CreateTranslation(-600, -340, 0);
	scoreMat4 = Math::Matrix::CreateTranslation(-600 + 32, -340, 0);
	scoreMat3 = Math::Matrix::CreateTranslation(-600 + 64, -340, 0);
	scoreMat2 = Math::Matrix::CreateTranslation(-600 + 96, -340, 0);
	scoreMat1 = Math::Matrix::CreateTranslation(-600 + 128, -340, 0);

	scoreStringMat = Math::Matrix::CreateTranslation(-600, -300, 0);
}

void Score::Draw()
{
	int num5 = m_score / 10000;

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


	int num4 = m_score % 10000 / 1000;

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


	int num3 = m_score % 10000 % 1000 / 100;

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


	int num2 = m_score % 10000 % 1000 % 100 / 10;
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

	int num1 = m_score % 10000 % 1000 % 100 % 10;
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
}

void Score::Init()
{
	m_score = 0;

	scoreTex.Load("Texture/ScoreNumber.png");
	scoreStringTex.Load("Texture/ScoreString.png");

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
}

void Score::Release()
{
	scoreTex.Release();
}
