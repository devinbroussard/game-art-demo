#pragma once
#include "AnimatedSpriteComponent.h"
class EnemyAnimationsComponent :
	public AnimatedSpriteComponent
{
public:
	EnemyAnimationsComponent(const char* rightPath, const char* leftPath, int xFrames, int yFrames, float fps);

	void updateFrames(float deltaTime) override;
	void draw() override;
};

