#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	sf::Sprite _shape;

	sf::Vector2f _direction;
	float _movementSpeed;

public:
	Bullet(sf::Texture& texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
	virtual ~Bullet();

	// Accessor
	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};