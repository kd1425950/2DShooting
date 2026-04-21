#include "Meteo.h"

void METEO::Init()
{
	m_pos = { 0,0 };
	m_move = { 0,0 };

	meteoScale = 1.0f;
}

void METEO::Update()
{
	Math::Matrix trans = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	Math::Matrix scale = Math::Matrix::CreateScale(meteoScale, meteoScale, 0);
	m_mat = scale * trans;
}

void METEO::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}
