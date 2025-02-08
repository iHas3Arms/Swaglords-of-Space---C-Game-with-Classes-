#include "Bullet.h"

// Private functions

// Public functions

Bullet::Bullet(sf::Texture& texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	_shape.setTexture(texture);

	_shape.setPosition(pos_x, pos_y);
	_shape.scale(5.f, 5.f);
	_direction.x = dir_x;
	_direction.y = dir_y;
	_movementSpeed = movement_speed;
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getBounds() const
{
	return _shape.getGlobalBounds();
}

void Bullet::update()
{
	// Movement
	_shape.move(_movementSpeed * _direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(_shape);
}
