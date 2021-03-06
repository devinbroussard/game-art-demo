#pragma once
#include "Actor.h"
#include <raylib.h> 

class UIActor :
	public Actor
{
public:
	UIActor(int x ,int y, int fontSize, const char* text);
	UIActor(int x, int y, int fontSize, const char* text, Color color);
	void draw() override;

private:
	int m_fontSize;
	int m_x;
	int m_y;
	const char* m_text;
	Color m_color;
};

