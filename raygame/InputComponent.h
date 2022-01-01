#pragma once
#include "Component.h"
#include <Vector2.h>
#include <raylib.h>

class InputComponent :
	public Component
{
public:
	InputComponent(Actor* owner);

	MathLibrary::Vector2 getMoveAxis();
	bool getAttackInput();

	void update(float deltaTime) override;

private:
	bool m_isAttacking;

	RAYLIB_H::KeyboardKey m_up = RAYLIB_H::KeyboardKey::KEY_W;
	RAYLIB_H::KeyboardKey m_left = RAYLIB_H::KeyboardKey::KEY_A;
	RAYLIB_H::KeyboardKey m_down = RAYLIB_H::KeyboardKey::KEY_S;
	RAYLIB_H::KeyboardKey m_right = RAYLIB_H::KeyboardKey::KEY_D;
	RAYLIB_H::KeyboardKey m_meleeSwing = RAYLIB_H::KeyboardKey::KEY_SPACE;
};

