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
	MathLibrary::Vector2 getForwardAxis();
	bool getAttackInput();
	void update(float deltaTime) override;

private:
	RAYLIB_H::KeyboardKey m_up = RAYLIB_H::KeyboardKey::KEY_W;
	RAYLIB_H::KeyboardKey m_left = RAYLIB_H::KeyboardKey::KEY_A;
	RAYLIB_H::KeyboardKey m_down = RAYLIB_H::KeyboardKey::KEY_S;
	RAYLIB_H::KeyboardKey m_right = RAYLIB_H::KeyboardKey::KEY_D;

	RAYLIB_H::KeyboardKey m_lookUp = RAYLIB_H::KeyboardKey::KEY_UP;
	RAYLIB_H::KeyboardKey m_lookLeft = RAYLIB_H::KeyboardKey::KEY_LEFT;
	RAYLIB_H::KeyboardKey m_lookDown = RAYLIB_H::KeyboardKey::KEY_DOWN;
	RAYLIB_H::KeyboardKey m_lookRight = RAYLIB_H::KeyboardKey::KEY_RIGHT;

	RAYLIB_H::KeyboardKey m_meleeSwing = RAYLIB_H::KeyboardKey::KEY_SPACE;
};

