#pragma once

class METEO
{
public:

	METEO(){}
	~METEO(){}

	void Init();
	void Update();
	void Draw();

	void SetTex(KdTexture* tex) { m_tex = tex; }

private:

	Math::Vector2 m_pos;
	Math::Vector2 m_move;

	float meteoScale;

	bool meteoFlg;

	Math::Matrix m_mat;

	KdTexture *m_tex;
};