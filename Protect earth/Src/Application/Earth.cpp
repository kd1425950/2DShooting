#include "Earth.h"

void Earth::Init()
{
	earthTex.Load("Texture/BackGround.png");
	hpTex.Load("Texture/HP.png");

	earthHp = 100;
}

void Earth::Update()
{
	earthMat = Math::Matrix::CreateTranslation(0, 0, 0);
	hpMat = Math::Matrix::CreateTranslation(-384, 270, 0);
}

void Earth::Draw()
{
	SHADER.m_spriteShader.SetMatrix(earthMat);
	SHADER.m_spriteShader.DrawTex(&earthTex, Math::Rectangle(0, 0, 1280, 720), 1.0f);

	SHADER.m_spriteShader.SetMatrix(hpMat);

	switch (earthHp)
	{
	case 100:
		SHADER.m_spriteShader.DrawTex(&hpTex, Math::Rectangle(0, 0, 512, 60), 1.0f);
		break;
	case 90:
		SHADER.m_spriteShader.DrawTex(&hpTex, Math::Rectangle(0, 62, 512, 60), 1.0f);
		break;
	case 80:
		SHADER.m_spriteShader.DrawTex(&hpTex, Math::Rectangle(0, 124, 512, 60), 1.0f);
		break;
	case 70:
		SHADER.m_spriteShader.DrawTex(&hpTex, Math::Rectangle(0, 186, 512, 60), 1.0f);
		break;
	case 60:
		SHADER.m_spriteShader.DrawTex(&hpTex, Math::Rectangle(0, 248, 512, 60), 1.0f);
		break;
	case 50:
		SHADER.m_spriteShader.DrawTex(&hpTex, Math::Rectangle(0, 310, 512, 60), 1.0f);
		break;
	case 40:
		SHADER.m_spriteShader.DrawTex(&hpTex, Math::Rectangle(0, 372, 512, 60), 1.0f);
		break;
	case 30:
		SHADER.m_spriteShader.DrawTex(&hpTex, Math::Rectangle(0, 434, 512, 60), 1.0f);
		break;
	case 20:
		SHADER.m_spriteShader.DrawTex(&hpTex, Math::Rectangle(0, 496, 512, 60), 1.0f);
		break;
	case 10:
		SHADER.m_spriteShader.DrawTex(&hpTex, Math::Rectangle(0, 558, 512, 60), 1.0f);
		break;
	default:
		SHADER.m_spriteShader.DrawTex(&hpTex, Math::Rectangle(0, 620, 512, 60), 1.0f);
		break;
	}
}

void Earth::Release()
{
	earthTex.Release();
}
