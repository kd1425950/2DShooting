#pragma once
#include "Mouse.h"
#include "Meteo.h"
#include "Particle.h"

class SHOT
{
private:

	Math::Vector2 m_bullet;

	float m_bulletScale;

	float bulletRadius;

	float bulletR = m_bullet.x + bulletRadius;
	float bulletL = m_bullet.x - bulletRadius;
	float bulletT = m_bullet.y + bulletRadius;
	float bulletB = m_bullet.y - bulletRadius;

	bool m_bulletFlg;

	int shotWait;

	float shotAnim;

	bool keyFlg;

	Math::Matrix m_scale;
	Math::Matrix m_trans;
	Math::Matrix m_mat;

	KdTexture* m_tex;

public:
	SHOT();
	~SHOT();

	void Init(MOUSE *mouse);
	void Update(MOUSE* mouse);
	void Draw();

	void BulletMeteoHit(METEO *meteo/*,Particle *par*/);

	void SetTex(KdTexture* tex) { m_tex = tex; }
};