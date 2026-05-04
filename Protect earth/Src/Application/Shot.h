#pragma once
#include "Mouse.h"

class GameScene;
class METEO;
class Particle;

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

	float missileAttack;

	Math::Matrix m_scale;
	Math::Matrix m_trans;
	Math::Matrix m_mat;

	Math::Matrix m_UIscale;
	Math::Matrix m_UItrans;
	Math::Matrix m_UImat;

	Math::Matrix m_UIscale2;
	Math::Matrix m_UItrans2;
	Math::Matrix m_UImat2;

	KdTexture* m_tex;
	KdTexture* m_uiTex;
	KdTexture* m_uiTex2;

	GameScene* game;

public:
	SHOT() {}
	~SHOT() {}

	void Init(MOUSE* mouse);
	void Update(MOUSE* mouse);
	void Draw();

	void BulletMeteoHit();

	void SetTex(KdTexture* tex) { m_tex = tex; }
	void SetTexUI(KdTexture* uiTex) { m_uiTex = uiTex; }
	void SetTexUI2(KdTexture* uiTex2) { m_uiTex2 = uiTex2; }
};