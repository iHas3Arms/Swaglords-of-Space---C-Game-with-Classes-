#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Player
{
private:
	// Player graphics variables
	sf::Sprite _sprite;
	sf::Texture _texture;

	// Player movement variables
	float _movementSpeed;

	// Private functions
	void _initTexture();
	void _initSprite();

public:
	// Con/Des
	Player();
	virtual ~Player();

	// Public functions
	void _move(const float dirX, const float dirY);

	void _update();
	void _render(sf::RenderTarget& target);
};