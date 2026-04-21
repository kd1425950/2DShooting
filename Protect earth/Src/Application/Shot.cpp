#include "Shot.h"

SHOT::SHOT()
{
}

SHOT::~SHOT()
{
}

void SHOT::Init(MOUSE* mouse)
{
	m_bullet = mouse->GetPos();
	m_bulletScale = 1.5f;
	m_bulletFlg = false;
	
	shotWait = 0;
	shotAnim = 0;
}

void SHOT::Update(MOUSE* mouse)
{
	if (!m_bulletFlg)
	{	
		m_bullet = mouse->GetPos();
	}
	else
	{
		m_bullet = m_bullet;
		//m_bulletScale -= 0.03;
		shotAnim++;
		if (shotAnim >= 512)
		{
			shotAnim = 0;
			m_bulletFlg = false;
		}
	}
	

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (shotWait == 0)
		{
			if(!m_bulletFlg)
			{
				m_bulletFlg = true;
			}
		}
	}

	m_scale = Math::Matrix::CreateScale(m_bulletScale, m_bulletScale, 0);
	m_trans = Math::Matrix::CreateTranslation(m_bullet.x, m_bullet.y, 0);
	m_mat = m_scale * m_trans;
	
}

void SHOT::Draw()
{
	if (m_bulletFlg)
	{
		SHADER.m_spriteShader.SetMatrix(m_mat);
		SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle((int)shotAnim * 64, 0, 64, 64), 1.0f);
	}
	
}
