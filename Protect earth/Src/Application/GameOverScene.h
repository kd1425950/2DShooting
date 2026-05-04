#pragma once
#include "State.h"

class MOUSE;

class GameOverScene :public State
{
public:

	GameOverScene(){}
	~GameOverScene(){}

	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;

private:

	int score;

	MOUSE* mouse;
	
	KdTexture gameOverBackTex;
	KdTexture scoreTex;
	KdTexture scoreStringTex;
	KdTexture GameOverTex;
	KdTexture TitleStringTex;
	KdTexture RetryTex;

	Math::Matrix gameOverMat;

	Math::Matrix scoreMat1;
	Math::Matrix scoreMat2;
	Math::Matrix scoreMat3;
	Math::Matrix scoreMat4;
	Math::Matrix scoreMat5;

	Math::Matrix scoreStringMat;

	Math::Matrix gameoverbackMat;

	Math::Matrix TitleStringMat;
	Math::Matrix RetryMat;

	int scoreXCut1;
	int scoreXCut2;
	int scoreXCut3;
	int scoreXCut4;
	int scoreXCut5;

	int scoreYCut1;
	int scoreYCut2;
	int scoreYCut3;
	int scoreYCut4;
	int scoreYCut5;

	float m_alpha;
	float m_alphaAdd;

	bool changeTitleFlg;
	bool changeRetryFlg;

	Math::Vector2 title;
	Math::Vector2 retry;

	Math::Vector2 titleRadius;
	Math::Vector2 retryRadius;

	float titleScale;
	float retryScale;

	float titleScaleAdd;
	float retryScaleAdd;

	float titleR;
	float titleL;
	float titleT;
	float titleB;

	float retryR;
	float retryL;
	float retryT;
	float retryB;
};