#include "Shot.h"

SHOT::SHOT()
{
}

SHOT::~SHOT()
{
}

void SHOT::Init(MOUSE* mouse)
{
	for(int b=0;b<bulletNum;b++)
	{
		m_bullet[b] = mouse->GetPos();
		m_bulletScale[b] = 1.5f;
		m_bulletFlg[b] = false;
	}
	shotWait = 0;
}

void SHOT::Update(MOUSE* mouse)
{
	for (int b = 0;b < bulletNum;b++)
	{
		if (!m_bulletFlg[b])
		{
			
			m_bullet[b] = mouse->GetPos();
			
		}
		else
		{
			
			m_bullet[b] = m_bullet[b];
			m_bulletScale[b] -= 0.03;
			
		}
	}

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (shotWait == 0)
		{
			for (int b = 0;b < bulletNum;b++)
			{
				if(!m_bulletFlg[b])
				{
					m_bulletFlg[b] = true;
					shotWait = 10;
					break;
				}
			}
		}
	}

	for (int b = 0;b < bulletNum;b++)
	{
		if (m_bulletScale[b] <= 0)
		{
			m_bulletFlg[b] = false;
			m_bulletScale[b] = 1.0f;
		}
	}

	shotWait--;
	if (shotWait <= 0)
	{
		shotWait = 0;
	}

	for (int b = 0;b < bulletNum;b++)
	{
		m_scale[b] = Math::Matrix::CreateScale(m_bulletScale[b], m_bulletScale[b], 0);
		m_trans[b] = Math::Matrix::CreateTranslation(m_bullet[b].x, m_bullet[b].y, 0);
		m_mat[b] = m_scale[b] * m_trans[b];
	}
}

void SHOT::Draw()
{
	for (int b = 0;b < bulletNum;b++)
	{
		if (m_bulletFlg[b])
		{
			SHADER.m_spriteShader.SetMatrix(m_mat[b]);
			SHADER.m_spriteShader.DrawTex(m_tex[b], Math::Rectangle(0, 0, 64, 64), 1.0f);
		}
	}
}
