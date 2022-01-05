#pragma once
#include "SpriteComponent.h"
#include <raylib.h>

class Enemy;
class Texture2D;

class EnemySpriteComponent :
	public SpriteComponent
{
public:
    EnemySpriteComponent(const char* name = "PlayerSpriteComponent");
    ~EnemySpriteComponent() override;

    Enemy* getPlayerOwner() { return (Enemy*)getOwner(); }

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
    Rectangle m_frameRec = { 0, 0, (float)getWidth() / 6, (float)getHeight() / 5 };
};

