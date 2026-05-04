#pragma once
#include "State.h"

class MOUSE;

class TitleScene : public State
{
public:
	TitleScene() { m_tag = Title; }
	~TitleScene() {}
	void Update() override;
	void Draw() override;
	void Init() override;
	void Release() override;
private:
	KdTexture titleTex;
	KdTexture titleBackTex;
	KdTexture PlayTex;
	KdTexture ExitTex;

	Math::Matrix titleMat;
	Math::Matrix titleBackMat;
	Math::Matrix PlayMat;
	Math::Matrix ExitMat;

	float m_alpha;
	float m_alphaAdd;

	Math::Vector2 play;
	Math::Vector2 exit;

	float playScale;
	float playScaleAdd;

	float exitScale;
	float exitScaleAdd;

	float playRadiusX;
	float playRadiusY;

	float exitRadiusX;
	float exitRadiusY;

	float playR;
	float playL;
	float playT;
	float playB;

	float exitR;
	float exitL;
	float exitT;
	float exitB;

	bool changeFlg;

	MOUSE* mouse;
};