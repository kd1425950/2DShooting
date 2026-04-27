#pragma once

class GameScene;

class SKILL
{
public:
	SKILL() {}
	~SKILL() {}
	void Update();
	void Draw();
	void Init();
	void Release();
private:
	KdTexture skillTex;
	KdTexture spaceTex;

	Math::Matrix skillMat;
	Math::Matrix spaceMat;

	GameScene* game = nullptr;
};