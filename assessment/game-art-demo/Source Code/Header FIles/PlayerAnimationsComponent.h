#pragma once
#include "AnimatedSpriteComponent.h"
class PlayerAnimationsComponent :
	public AnimatedSpriteComponent
{
public:
	PlayerAnimationsComponent(const char* rightPath, const char* leftPath, int xFrames, int yFrames, float fps);

	void updateFrames(float deltaTime) override;
	void draw() override;
};

