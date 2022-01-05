#pragma once
#include "Component.h"

class AttackComponent :
	public Component
{
public:
	//Made a default contructor for the Attack Componet
	AttackComponent();
	//called update
	void update(float deltaTime) override;

private:
	int m_framesCounter;
	int m_maxFrames;
};

