#pragma once
#include "AnimatedSpriteComponent.h"
class EnemyAnimationsComponent :
	public AnimatedSpriteComponent
{
public:
	EnemyAnimationsComponent(const char* rightPath, const char* leftPath, int xFrames, int yFrames);

	void updateFrames(float deltaTime) override;
};

