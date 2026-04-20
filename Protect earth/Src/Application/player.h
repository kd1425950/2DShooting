#pragma once
#include"Mouse.h"

class Player
{
private:

	Math::Vector2 m_player;

	float reticleScale;

	KdTexture* m_tex;

	Math::Matrix m_scale;
	Math::Matrix m_trans;
	Math::Matrix m_mat;

public:
	Player();
	~Player();

	void Init(MOUSE *mouse);
	void Update(MOUSE* mouse);
	void Draw();

	void SetTex(KdTexture* tex) { m_tex = tex; }
};