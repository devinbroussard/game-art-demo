#pragma once
#include "SpriteComponent.h"
#include <raylib.h>
class Player;

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
    void updateFrames();


private:
    int m_framesCounter;
    int m_framesSpeed;
    int m_currentXFrame;
    int m_currentYFrame;
    Rectangle m_frameRec = { 0, 0, (float)getWidth() / 6, (float)getHeight() / 5 };
};

