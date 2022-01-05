#pragma once
#include "SpriteComponent.h"
#include <raylib.h>

class Enemy;
class Texture2D;

class EnemySpriteComponent :
	public SpriteComponent
{
public:
    //default constructor for the enemySpriteComponent
    EnemySpriteComponent(const char* name = "PlayerSpriteComponent");
    //default deconstructor for the enemySprite
    ~EnemySpriteComponent() override;

    //returns a Enemy pointer that is its owner
    //Gets the players Owner
    Enemy* getPlayerOwner() { return (Enemy*)getOwner(); }

    //called update
    void update(float deltaTime) override;
    void draw() override;
    //gets the current frames of the sprite or the current scene
    void getCurrentFrames();
    //updates the frames of the sprite or the current scnene
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
    //set a paraminter for the texture
    Rectangle m_frameRec = { 0, 0, (float)getWidth() / 6, (float)getHeight() / 5 };
};

