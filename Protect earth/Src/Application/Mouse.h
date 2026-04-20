#pragma once

class MOUSE
{
public:

	MOUSE() {}
	~MOUSE() {}

	void Init();
	void Update();

	void getmousePos2(POINT* mousePos);

	Math::Vector2 GetPos();

private:

	POINT mouse;
	Math::Vector2 m_mousePos;
	static const int screenWidth = 1280;
	static const int screenHeight = 720;
};