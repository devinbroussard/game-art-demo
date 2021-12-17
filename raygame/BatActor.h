#pragma once
#include "Actor.h"
class BatActor :
	public Actor
{
public:
	BatActor(Actor* owner);
	~BatActor();

	void start() override;

private:
	Actor* m_owner;
	
};

