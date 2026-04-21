#pragma once
#include "Mouse.h"

class SHOT
{
private:

	Math::Vector2 m_bullet;

	float m_bulletScale;

	bool m_bulletFlg;

	int shotWait;

	float shotAnim;

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

	void SetTex(KdTexture* tex) { m_tex = tex; }
};