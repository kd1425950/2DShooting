#include "Meteo.h"

void METEO::Init()
{
	m_pos = { -53,1280 };
	m_move = { 0,0 };

	meteoScale = 1.0f;
	meteoFlg = true;
}

void METEO::Update()
{
	m_pos += m_move;

	m_move.y -= 2;

	if (m_move.y <= -2)
	{
		m_move.y = -2;
	}

	if (m_pos.y <= -200)
	{
		meteoFlg = false;
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