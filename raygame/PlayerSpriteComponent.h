#pragma once
#include "SpriteComponent.h"
#include <raylib.h>
class Player;
class Texture2D;

class PlayerSpriteComponent :
    public SpriteComponent
{
public:
    PlayerSpriteComponent(const char* name = "PlayerSpriteComponent");
    ~PlayerSpriteComponent() override;

    Player* getPlayerOwner() { return (Player*)getOwner(); }

    void update(float deltaTime) override;
    void draw() override;
    void getCurrentFrames();
    void updateFrames(float deltaTime);


private:
    Texture2D* m_rightTexture;
    Texture2D* m_leftTexture;
    bool m_textureIsLeft;

    int m_timeTracker;
    int m_frameDuration;
    int m_currentXFrame;
    int m_currentYFrame;
    Rectangle m_frameRec = { 0, 0, (float)getWidth() / 6, (float)getHeight() / 5 };
};

