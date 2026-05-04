#include "Shot.h"
#include "GameScene.h"
#include "Meteo.h"
#include "Particle.h"
#include "Score.h"
#include "SceneManager.h"
#include "KeyManager.h"

void SHOT::Init(MOUSE* mouse)
{
	game = static_cast<GameScene*>(SCENEM.GetState());
	m_bullet = mouse->GetPos();
	m_bulletScale = 2.0f;
	m_bulletFlg = false;
	
	shotWait = 0;
	shotAnim = 0;

	keyFlg = true;

	bulletRadius = 32;

	missileAttack = 1.0f;

	bulletR = mouse->GetPos().x + bulletRadius;
	bulletL = mouse->GetPos().x - bulletRadius;
	bulletT = mouse->GetPos().y + bulletRadius;
	bulletB = mouse->GetPos().y - bulletRadius;

}

void SHOT::Update(MOUSE* mouse)
{
	if (!m_bulletFlg)
	{	
		m_bullet = mouse->GetPos();

		bulletR = mouse->GetPos().x + bulletRadius;
		bulletL = mouse->GetPos().x - bulletRadius;
		bulletT = mouse->GetPos().y + bulletRadius;
		bulletB = mouse->GetPos().y - bulletRadius;
	}
	else
	{
		m_bullet = m_bullet;

		//m_bulletScale -= 0.03;
		shotAnim += 0.3;
		if (shotAnim >= 8)
		{
			shotAnim = 0;
			m_bulletFlg = false;
		}
	}
	
	if (!m_bulletFlg)
	{
		if (KEYM.PushLbutton())
		{
			if (keyFlg)
			{
				if (shotWait == 0)
				{
					m_bulletFlg = true;
					keyFlg = false;
				}
			}
		}
		else
		{
			keyFlg = true;
		}
	}


	m_scale = Math::Matrix::CreateScale(m_bulletScale, m_bulletScale, 0);
	m_trans = Math::Matrix::CreateTranslation(m_bullet.x, m_bullet.y, 0);
	m_mat = m_scale * m_trans;
	
	m_UIscale = Math::Matrix::CreateScale(0.7f, 0.7f, 0);
	m_UItrans = Math::Matrix::CreateTranslation(590, -310, 0);
	m_UImat = m_UIscale * m_UItrans;

	m_UIscale2 = Math::Matrix::CreateScale(0.7f, 0.7f, 0);
	m_UItrans2 = Math::Matrix::CreateTranslation(470, -310, 0);
	m_UImat2 = m_UIscale2 * m_UItrans2;
}

void SHOT::Draw()
{
	if (m_bulletFlg)
	{
		SHADER.m_spriteShader.SetMatrix(m_mat);
		SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle((int)shotAnim * 64, 0, 64, 64), 1.0f);
	}
	
	SHADER.m_spriteShader.SetMatrix(m_UImat);
	SHADER.m_spriteShader.DrawTex(m_uiTex, Math::Rectangle(0, 0, 128, 128), 1.0f);

	SHADER.m_spriteShader.SetMatrix(m_UImat2);
	SHADER.m_spriteShader.DrawTex(m_uiTex2, Math::Rectangle(0, 0, 128, 128), 1.0f);
}

void SHOT::BulletMeteoHit()
{
	std::vector <METEO*> meteo = game->GetMeteo();
	std::vector <Particle*>* par = game->GetParticle();
	Score* score = game->GetScore();

	for (auto m : meteo)
	{
		Math::Vector2 meteoP = m->GetPos();
		bool meteoF = m->GetFlg();
		float meteoRad = m->GetRadius();
		float meteoS = m->GetScale();
		int socreValue = score->GetScoreValue();

		float meteoR = meteoP.x + meteoRad;
		float meteoL = meteoP.x - meteoRad;
		float meteoT = meteoP.y + meteoRad;
		float meteoB = meteoP.y - meteoRad;

		if (m_bulletFlg && meteoF)
		{
			if (bulletR > meteoL && bulletL < meteoR && bulletT > meteoB && bulletB < meteoT &&
				shotAnim <= 2)
			{
				meteoS -= missileAttack;
				if (meteoS <= 0)
				{
					meteoS = 0;
					meteoF = false;
					m->SetFlg(meteoF);

					socreValue += 100;
					score->SetScoreValue(socreValue);

					for (int i = 0;i < 5;i++)
					{
						par->push_back(new Particle(meteoP, 1, true, game->GetParticleTex()));
					}
					par->pop_back();
				}
			}
		}
	}
}
