#pragma once
#include "Meteo.h"

class Particle
{
public:

	Particle(){}
	~Particle() {}

	void Init();
	void Update();
	void Draw();

	float Rand() { return rand() % 20 - 10; }

	void SetTex(KdTexture* tex) { m_pTex = tex; }

	void Par(Math::Vector2 pos, Math::Vector2 move, float size, bool repet);

private:
	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Matrix m_mat;
	const float Gravity = 0.2;
	float m_size;
	float m_rotate;
	float m_Radius;
	float m_lifespan;
	bool m_repet;
	KdTexture* m_pTex;
};
