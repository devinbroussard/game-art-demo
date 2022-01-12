#pragma once
#include "SpriteComponent.h"
class Character;

class AnimatedSpriteComponent :
	public SpriteComponent
{
public:
	AnimatedSpriteComponent(const char* rightPath, const char* leftPath, int xFrames, int yFrames, float fps);
	~AnimatedSpriteComponent() override;

	Rectangle* getFrameRec() { return &m_frameRec; }
	Character* getCharacter() { return (Character*)getOwner(); }
	float getTimeTracker() { return m_timeTracker; }
	float getFps() { return m_fps; }
	int getCurrentXFrame() { return m_currentXFrame; }
	int getCurrentYFrame() { return m_currentYFrame; }
	int getXFrameCount() { return m_xFrameCount; }
	int getYFrameCount() { return m_yFrameCount; }
	Texture2D* getRightTexture() { return m_rightTexture; }
	Texture2D* getLeftTexture() { return m_leftTexture; }
	bool getIsTextureLeft() { return m_textureIsLeft; }
	void setTimeTracker(float time) { m_timeTracker = time; }
	void setFps(float fps) { m_fps = fps; }
	void setCurrentXFrame(int xFrame) { m_currentXFrame = xFrame; }
	void setCurrentYFrame(int yFrame) { m_currentYFrame = yFrame; }
	void setIsTextureLeft(bool isLeft) { m_textureIsLeft = isLeft; }
	void setStartAttack(bool startAttack) { m_startAttack = startAttack; }
	void setCharacterIsDead(bool value) { m_characterIsDead = true; }
	bool getCharacterIsDead() { return m_characterIsDead; }
	
	void update(float deltaTime) override;
	virtual void draw() override;
	void getCurrentFrames();
	virtual void updateFrames(float deltaTime) {};

private:	
	Texture2D* m_rightTexture;
	Texture2D* m_leftTexture;
	bool m_textureIsLeft;
	bool m_characterIsDead;

	bool m_startAttack;
	float m_timeTracker;
	float m_fps;
	int m_currentXFrame;
	int m_currentYFrame;
	int m_xFrameCount;
	int m_yFrameCount;
	Rectangle m_frameRec = { 0, 0, (float)getWidth() / m_xFrameCount, (float)getHeight() / m_yFrameCount };
};

