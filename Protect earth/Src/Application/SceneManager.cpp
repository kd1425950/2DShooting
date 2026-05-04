#include "SceneManager.h"
#include "State.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"
#include "GameOverScene.h"
#include "Score.h"

void SceneM::Init()
{
	currentState->Init();
}

void SceneM::Update()
{
	currentState->Update();
}

void SceneM::Draw()
{
	currentState->Draw();
}

void SceneM::Release()
{
	currentState->Release();
}

void SceneM::ChangeState(State* newState)
{
	if (currentState != nullptr) 
	{
		if (currentState->GetTag() == Game)
		{
			GameScene* game = dynamic_cast<GameScene*>(currentState);
			Score = game->GetScore()->GetScoreValue();
		}
	}

	delete currentState;
	currentState = newState;
	currentState->Init();
}
