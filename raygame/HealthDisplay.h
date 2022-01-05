#pragma once
#include "Actor.h"
class Character;
class SpriteComponent;

class HealthDisplay :
    public Actor
{
public:
    void start() override;

private:
    Character* m_owner;
    SpriteComponent* m_firstHeart;
    SpriteComponent* m_secondHeart;
    SpriteComponent* m_thirdHeart;

};

