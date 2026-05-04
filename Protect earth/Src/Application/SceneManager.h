#pragma once

class State;
class TitleScene;
class GameScene;
class ResultScene;
class GameOverScene;

class SceneM
{
public:

	static SceneM& GetInstance()
	{
		static SceneM instance;
		return instance;
	}

	void Init();
	void Update();
	void Draw();
	void Release();
	void ChangeState(State* newState);

	int GetScore() { return Score; }

	State* GetState() { return currentState; }

private:

	SceneM() {}

	int Score;

	State* currentState = nullptr;
};

#define SCENEM SceneM::GetInstance()