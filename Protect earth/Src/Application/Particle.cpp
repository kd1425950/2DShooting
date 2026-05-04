#include "Particle.h"

Particle::Particle(Math::Vector2 pos, float size, bool repet, KdTexture* tex)
{
		m_pos = pos;
	//m_move = move;
	m_move.x = Rand();
	m_move.y = Rand();
	m_size = size;
	m_repet = repet;
	m_pTex.Load("Texture/MeteoBreak.png");
}

void Particle::Init()
{
	{
		//m_pos = { 0,0 };
		//m_move = { 0,0 };
		//m_size = 1;
		//m_Radius = 8;
		//m_rotate = 10;
		//m_lifespan = 0;
		//m_repet = false;
		////m_pTex = nullptr;
	}
}

void Particle::Update()
{
	m_pos += m_move;
	m_move.y -= Gravity;

	m_rotate++;

	if (m_pos.y <= -360)
	{
		m_repet = false;
	}

	Math::Matrix scale, rotate, trans;
	scale = Math::Matrix::CreateScale(m_size, m_size, 0);
	rotate = Math::Matrix::CreateRotationZ(ToRadians(m_rotate));
	trans = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);

	m_mat = scale * rotate * trans;
}

void Particle::Draw()
{
	if (!m_repet)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&m_pTex, Math::Rectangle(0, 0, 16, 16), 1.0f);
}
