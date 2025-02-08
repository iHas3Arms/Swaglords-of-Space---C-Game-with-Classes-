#include "Player.h"

// Private functions

void Player::_initTexture()
{
	// Load a texture from a file
	if (!_texture.loadFromFile("Textures/ship.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Texture could not be loaded.";
	}


}

void Player::_initSprite()
{
	// Set the texture to the sprite
	_sprite.setTexture(_texture); // If e.g. a square, passes a pointer, but sprite passes object

	// Resize the sprite
	_sprite.scale(0.1f, 0.1f);
}

// Public functions

// Constructor
Player::Player()
{
	_movementSpeed = 0.2f;

	_initTexture();
	_initSprite();
}

// Destructor
Player::~Player()
{
}

void Player::_move(const float dirX, const float dirY)
{
	_sprite.move(_movementSpeed * dirX, _movementSpeed * dirY);
}

void Player::_update()
{
}

void Player::_render(sf::RenderTarget& target)
{
	target.draw(_sprite);
}
