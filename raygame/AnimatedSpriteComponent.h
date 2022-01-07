#pragma once
#include "SpriteComponent.h"
class Character;

class AnimatedSpriteComponent :
	public SpriteComponent
{
public:
	AnimatedSpriteComponent(int xFrames, int yFrames);
	~AnimatedSpriteComponent() override;

	Character* getCharacter() { return (Character*)getOwner(); }

	void update(float deltaTime) override;
	void draw() override;
	void getCurrentFrames();
	void updateFrames(float deltaTime);

private:	
	Texture2D* m_rightTexture;
	Texture2D* m_leftTexture;
	bool m_textureIsLeft;

	float m_timeTracker;
	float m_frameDuration;
	float m_fps;
	int m_currentXFrame;
	int m_currentYFrame;
	int m_xFrameCount;
	int m_yFrameCount;
	Rectangle m_frameRec = { 0, 0, (float)getWidth() / m_xFrameCount, (float)getHeight() / m_yFrameCount };
};

