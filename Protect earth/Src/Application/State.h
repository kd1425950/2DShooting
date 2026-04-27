#pragma once

enum  tag
{
	Title,
	Game,
	Result
};

class State
{
public:
	State() {}
	~State() {}

	virtual void Update() = 0;//純粋仮想関数
	virtual void Draw() = 0;//純粋仮想関数
	virtual void Init() = 0;//純粋仮想関数
	virtual void Release() {};//純粋仮想関数

	tag GetTag() { return m_tag; }
protected:
	tag m_tag;
};