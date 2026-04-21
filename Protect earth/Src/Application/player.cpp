#include "player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init(MOUSE *mouse)
{
	m_player = mouse->GetPos();
	reticleScale = 1.5f;
}

void Player::Update(MOUSE* mouse)
{
	m_player = mouse->GetPos();

	m_trans = Math::Matrix::CreateTranslation(m_player.x, m_player.y, 0);
	m_scale = Math::Matrix::CreateScale(reticleScale, reticleScale, 0);
	m_mat = m_scale * m_trans;
}

void Player::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}
