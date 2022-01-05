#pragma once
#include "SpriteComponent.h"
#include <raylib.h>
class Player;
class Texture2D;

class PlayerSpriteComponent :
    public SpriteComponent
{
public:
    //default constructor for the PLayerSpriteCOmponet
    PlayerSpriteComponent(const char* name = "PlayerSpriteComponent");
    //default deconstructor 
    ~PlayerSpriteComponent() override;

    //gets the player owner by returning a Player pointer then calling the function get Owner
    Player* getPlayerOwner() { return (Player*)getOwner(); }

    //called update
    void update(float deltaTime) override;
    //called draw
    void draw() override;
    //gets the current frames
    void getCurrentFrames();
    //updates the curretn frames of the sprite or the current scene
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
    //set paramerts for the game to have with (sprites)
    Rectangle m_frameRec = { 0, 0, (float)getWidth() / 6, (float)getHeight() / 5 };
};

