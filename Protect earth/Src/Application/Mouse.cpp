#include "Application/main.h"
#include "Mouse.h"


void MOUSE::Init()
{
	mouse.x = 0;
	mouse.y = 0;
}

void MOUSE::Update()
{
	getmousePos2(&mouse);

	Math::Color color;
	color = { 1,1,0,1 };

}

void MOUSE::getmousePos2(POINT* mousePos)
{
	GetCursorPos(mousePos);

	ScreenToClient(APP.m_window.GetWndHandle(), mousePos);

	mousePos->x -= screenWidth / 2;
	mousePos->y -= screenHeight / 2;
	mousePos->y *= -1;

	m_mousePos = { (float)mousePos->x,(float)mousePos->y };
}

Math::Vector2 MOUSE::GetPos()
{
	return m_mousePos;
}
