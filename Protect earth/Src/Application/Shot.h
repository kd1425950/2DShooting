#pragma once
#include "Mouse.h"

class SHOT
{
private:
	static const int bulletNum = 20;

	Math::Vector2 m_bullet[bulletNum];

	float m_bulletScale[bulletNum];

	bool m_bulletFlg[bulletNum];

	int shotWait;

	Math::Matrix m_scale[bulletNum];
	Math::Matrix m_trans[bulletNum];
	Math::Matrix m_mat[bulletNum];

	KdTexture* m_tex[bulletNum];

public:
	SHOT();
	~SHOT();

	void Init(MOUSE *mouse);
	void Update(MOUSE* mouse);
	void Draw();

	void SetTex(KdTexture* tex) 
	{
		for(int b=0;b<bulletNum;b++)
		{
			m_tex[b] = tex;
		}
	}
};