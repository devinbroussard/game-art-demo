#pragma once
#include "AnimatedSpriteComponent.h"
class PlayerAnimationsComponent :
	public AnimatedSpriteComponent
{
public:
	void updateFrames(float deltaTime) override;
};

