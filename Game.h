#pragma once

#include "Player.h"
#include "Bullet.h"

class Game
{
private:
	bool _endGame;
	bool _mouseHeld;

	// Resources
	std::map<std::string, sf::Texture> _textures;
	std::vector<Bullet> _bulletsVector;

	// Player
	Player* _player;
	float _playerDirX, _playerDirY;

	// Window variables
	sf::RenderWindow* _window;
	sf::VideoMode _videoMode;
	int _screenWidth, _screenHeight;

	// Init functions
	void _initVariables();
	void _initWindow();
	void _initTextures();
	void _initPlayer();
public:
	// Con/Des
	Game();
	virtual ~Game();
	// Virtual allows the deconstructors of derived classes
	// to be run because the vptr points to them first in the vtable

	// Functions
	void _run();

	void _updatePollEvents();
	void _updateInputs();

	void _updateBullets();
	void _update();
	void _render();
};