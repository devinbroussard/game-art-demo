#pragma once
#include "Component.h"
#include "Transform2D.h"
class FollowComponent :
	public Component
{
public:
	FollowComponent(const char* name, Actor* targetActor);


	void update(float deltaTime) override;

private:
	Actor* m_targetActor;

};

