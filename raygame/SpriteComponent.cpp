#include "SpriteComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include <cmath>

SpriteComponent::SpriteComponent(const char* path, const char* name) :
	Component::Component(name)
{
	//sets the texture to the RAYLIB load texture path
	m_texture = new Texture2D(RAYLIB_H::LoadTexture(path));
	//sets the height and the width
	m_height = m_texture->height;
	m_width = m_texture->width;
}

SpriteComponent::SpriteComponent(Texture2D* texture, const char* name) :
	Component::Component(name)
{
	m_texture = texture;
	m_height = m_texture->height;
	m_width = m_texture->width;
}

SpriteComponent::~SpriteComponent()
{
	RAYLIB_H::UnloadTexture(*m_texture);
	m_texture = 0;
}

void SpriteComponent::setTexture(Texture2D* texture)
{
	m_texture = texture;
}

/// <summary>
/// Draws the sprite to the screen
/// </summary>
void SpriteComponent::draw()
{
	//Scale
	int xScale = getOwner()->getTransform()->getScale().x;
	int yScale = getOwner()->getTransform()->getScale().y;

	m_texture->width = m_width * xScale;
	m_texture->height = m_height * yScale;

	//Positions makes a up and forward to set two points that can update.
	MathLibrary::Vector2 up = { getOwner()->getTransform()->getGlobalMatrix()->m01, getOwner()->getTransform()->getGlobalMatrix()->m11 };
	MathLibrary::Vector2 forward = getOwner()->getTransform()->getForward();
	MathLibrary::Vector2 position = getOwner()->getTransform()->getWorldPosition();

	
	position = position - (forward * getWidth() / 2);
	position = position - (up.getNormalized() * getHeight() / 2);
	RAYLIB_H::Vector2 rayPos = { position.x, position.y };

	//Rotations with using the global Matrix..
	float rotation = atan2(getOwner()->getTransform()->getGlobalMatrix()->m10, getOwner()->getTransform()->getGlobalMatrix()->m00);

	//Draws the texture using the actor's transform
	RAYLIB_H::DrawTextureEx(*m_texture, rayPos, (float)(rotation * 180.0f / PI), 1, WHITE);
}
