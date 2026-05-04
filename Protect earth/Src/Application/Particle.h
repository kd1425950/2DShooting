#pragma once

class Particle
{
public:

	Particle(Math::Vector2 pos, float size, bool repet, KdTexture* tex);
	~Particle() {}

	void Init();
	void Update();
	void Draw();

	float Rand() { return rand() % 20 - 10; }

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
	KdTexture m_pTex;
};
