#pragma once

class GameScene;

class METEO
{
public:

	METEO(){}
	~METEO(){}

	void Init();
	void Update();
	void Draw();

	void SetTex(KdTexture* tex) { m_tex = tex; }

	Math::Vector2 GetPos() { return m_pos; }
	Math::Vector2 GetMove() { return m_move; }

	void SetMove(Math::Vector2 move) { m_move = move; }

	bool GetFlg() { return meteoFlg; }
	void SetFlg(bool flg) { meteoFlg = flg; }

	float GetRadius() { return meteoRadius; }

	float GetRight() { return meteoRight; }
	float GetLeft() { return meteoLeft; }
	float GetTop() { return meteoTop; }
	float GetBottom() { return meteoBottom; }

	void SetRight(float right) { meteoRight = right; }
	void SetLeft(float left) { meteoLeft = left; }
	void SetTop(float top) { meteoTop = top; }
	void SetBottom(float bottom) { meteoBottom = bottom; }
	
	float RandX() { return rand() % 1280 - 640; }
	float RandY() { return rand() % 500 + 400; }

	float GetScale() { return meteoScale; }
	void SetScale(float scale) { meteoScale = scale; }

private:

	Math::Vector2 m_pos;
	Math::Vector2 m_move;

	float meteoScale;

	float meteoRadius = 32;

	int meteoAttack;

	float meteoRight = m_pos.x + meteoRadius;
	float meteoLeft = m_pos.x - meteoRadius;
	float meteoTop = m_pos.y + meteoRadius;
	float meteoBottom = m_pos.y - meteoRadius;

	bool meteoFlg;

	Math::Matrix m_mat;

	KdTexture *m_tex;

	GameScene* game = nullptr;
};