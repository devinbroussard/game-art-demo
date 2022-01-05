#pragma once
#include "Actor.h"
class Character;
class HeartUI;

class HealthDisplay :
    public Actor
{
public:
    HealthDisplay(float x, float y, Character* owner);

    void start() override;
    void update(float deltaTime) override;
    void checkHealth();

private:
    Character* m_owner;
    HeartUI* m_firstHeart;
    HeartUI* m_secondHeart;
    HeartUI* m_thirdHeart;

};

