#pragma once
#include "Component.h"

class AttackComponent :
	public Component
{
public:
	AttackComponent();
	void update(float deltaTime) override;

private:
	int m_framesCounter;
	int m_maxFrames;
};

