#pragma once
#include "Character.h"
#include "BoxBoundaryComponent.h"
#include "AABBCollider.h"
class InputComponent;

class Player :
	public Character
{
public:
	Player(float x, float y, const char* name, float speed, int maxHealth);
	~Player() {};

	InputComponent* getInputComponent() { return m_inputComponent; }

	void start() override;
	void update(float deltaTime) override;
	void  onCollision(Actor* other);
private:
	InputComponent* m_inputComponent;
	BoxBoundaryComponent* m_boxBoundaryComponent;
	AABBCollider* m_aabbCollider;
};

