#pragma once
#include"TitleScene.h"
#include"GameScene.h"
#include"MapScene.h"
#include"ResultScene.h"
#include"Gameover.h"
#include"Tutorial.h"
#include"StageSelect.h"
#include"Exit.h"
#include"difficulty.h"


enum stagetag
{
	a,
	b,
	c
};

enum difficultyTag
{
	easy,
	normal,
	hard
};

class SceneM
{
public:

	static SceneM& GetInstance()
	{
		static SceneM instance;
		return instance;
	}

	void Init()
	{
		currentState->Init();
	}

	void Update()
	{
		currentState->Update();
	}

	void Draw()
	{
		currentState->Draw();
	}

	void DynamicDraw()
	{
		currentState->DynamicDraw();
	}

	void ChangeState(State* newState)
	{
		if (currentState != nullptr) {
			if (currentState->GetTag() == Game)
			{
				GameScene* game = dynamic_cast<GameScene*>(currentState);
				Time = game->GetTime();
			}
		}
		delete currentState;
		currentState = newState;
		currentState->Init();
	}
	State* GetState() { return currentState; }
	int Gettime() { return Time; }
	stagetag GetStageTag() { return m_stagetag; }
	void SetStageTag(stagetag tag) { m_stagetag = tag; }
	difficultyTag GetDTag() { return m_Dtag; }
	void SetDTag(difficultyTag Dtag) { m_Dtag = Dtag; }

private:

	SceneM() {}

	State* currentState = nullptr;

	int Time;
	stagetag m_stagetag;
	difficultyTag m_Dtag;
};

#define SCENEM SceneM::GetInstance()