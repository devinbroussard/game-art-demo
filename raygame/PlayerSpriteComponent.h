#pragma once
#include "SpriteComponent.h"
#include <raylib.h>

class PlayerSpriteComponent :
    public SpriteComponent
{
public:
    PlayerSpriteComponent(const char* name = "PlayerSpriteComponent");
    ~PlayerSpriteComponent() override;

    void update(float deltaTime) override;
    void draw() override;


private:
    int m_framesCounter;
    int m_framesSpeed;
    int m_currentFrame;
    Rectangle m_frameRec = { 0, 0, (float)getWidth() / 6, (float)getHeight() / 5 };
};

