#pragma once
#include "State.h"

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

	float m_alpha;
	float m_alphaAdd;
};