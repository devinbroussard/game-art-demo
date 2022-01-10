#pragma once
#include "AnimatedSpriteComponent.h"
class PlayerAnimationsComponent :
	public AnimatedSpriteComponent
{
public:
	PlayerAnimationsComponent(const char* rightPath, const char* leftPath, int xFrames, int yFrames);

	void updateFrames(float deltaTime) override;
	void draw() override;
};

