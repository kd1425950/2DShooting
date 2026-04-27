#pragma once

class State;
class TitleScene;
class GameScene;
class ResultScene;

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

	State* GetState() { return currentState; }

private:

	SceneM() {}

	State* currentState = nullptr;
};

#define SCENEM SceneM::GetInstance()