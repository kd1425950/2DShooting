#pragma once
#include "State.h"

class Player;
class MOUSE;
class SHOT;
class METEO;
class Particle;
class SKILL;
class Earth;

class GameScene : public State
{
public:
	GameScene() { m_tag = Game; }
	~GameScene() {}
	void Update() override;
	void Draw() override;
	void Init() override;
	void Release() override;

	SHOT* GetShot() { return shot; }
	std::vector <METEO*> GetMeteo() { return meteo; }
	std::vector <Particle*>GetParticle() { return particle; }
	Earth* GetEarth() { return earth; }

private:

	static const int meteoNum = 1;
	static const int particleNum = 5;

	// テクスチャ ・・・ 画像データ
	KdTexture playerTex;
	KdTexture shotTex;
	KdTexture meteoTex;
	KdTexture backTex;
	KdTexture particleTex;

	Math::Matrix backMat;

	//インスタンス
	Player* player = nullptr;
	MOUSE* mouse = nullptr;
	SHOT* shot = nullptr;
	std::vector <METEO*> meteo;
	std::vector <Particle*> particle;
	SKILL* skill = nullptr;
	Earth* earth = nullptr;
};