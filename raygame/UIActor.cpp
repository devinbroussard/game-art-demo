#include "UIActor.h"
#include "Transform2D.h"

UIActor::UIActor(int x ,int y, int fontSize, const char* text)
{
	m_fontSize = fontSize;
	m_text = text;
	m_x = x;
	m_y = y;
}

/// <summary>
/// Draws the text to the screen using the font size and color
/// </summary>
void UIActor::draw()
{
	DrawText(m_text, m_x, m_y , m_fontSize, m_color);
}
