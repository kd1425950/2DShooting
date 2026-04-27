#include "Meteo.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "Earth.h"

void METEO::Init()
{
	game = static_cast<GameScene*>(SCENEM.GetState());

	m_pos = { RandX(),RandY()};
	m_move = { 0,0 };

	meteoScale = 1.0f;
	meteoFlg = true;

	meteoAttack = 10.0f;
}

void METEO::Update()
{
	m_pos += m_move;
	meteoScale = 1.0f;
	m_move.y -= 2;

	if (m_move.y <= -2)
	{
		m_move.y = -20;
	}

	if(meteoFlg)
	{
		if (m_pos.y <= -200)
		{
			meteoFlg = false;
			int hp = game->GetEarth()->GetHp();
			hp -= meteoAttack;
			if (hp <= 0)
			{
				hp = 0;
			}
			game->GetEarth()->SetHp(hp);
		}
	}

	if((rand() % 100 + 1) <= 2)
	{
		if (!meteoFlg)
		{
			meteoFlg = true;
			m_pos = { RandX(),RandY() };
		}
	}

	Math::Matrix trans = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	Math::Matrix scale = Math::Matrix::CreateScale(meteoScale, meteoScale, 0);
	m_mat = scale * trans;
}

void METEO::Draw()
{
	if(meteoFlg)
	{
		SHADER.m_spriteShader.SetMatrix(m_mat);
		SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
	}
}