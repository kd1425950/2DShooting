#pragma once
#include "State.h"

class Player;
class MOUSE;
class SHOT;
class METEO;
class Particle;
class SKILL;
class Earth;
class Score;

class GameScene : public State
{
public:
	GameScene() { m_tag = Game; }
	~GameScene() {}
	void Update() override;
	void Draw() override;
	void Init() override;
	void Release() override;

	void Timer();

	SHOT* GetShot() { return shot; }
	std::vector <METEO*> GetMeteo() { return meteo; }
	std::vector <Particle*>* GetParticle() { return &particle; }
	Earth* GetEarth() { return earth; }
	KdTexture* GetParticleTex() { return &particleTex; }

	Score* GetScore() { return score; }

private:

	static const int meteoNum = 10;

	// テクスチャ ・・・ 画像データ
	KdTexture playerTex;
	KdTexture shotTex;
	KdTexture shotUiTex;
	KdTexture shotUiTex2;
	KdTexture meteoTex;
	KdTexture backTex;
	KdTexture particleTex;

	KdTexture secTex;
	KdTexture sec10Tex;
	KdTexture minTex;
	KdTexture semiTex;

	Math::Matrix backMat;

	Math::Matrix secMat;
	Math::Matrix sec10Mat;
	Math::Matrix minMat;
	Math::Matrix semiMat;

	//インスタンス
	Player* player = nullptr;
	MOUSE* mouse = nullptr;
	SHOT* shot = nullptr;
	std::vector <METEO*> meteo;
	std::vector <Particle*> particle;
	SKILL* skill = nullptr;
	Earth* earth = nullptr;
	Score* score = nullptr;

	float m_alpha;
	float m_alphaAdd;

	int frame;
	int Time;

	int sec;
	int sec10;
	int min;
	int mod;

	bool changeResultFlg;
	bool changeGOFlg;
};