#include "Game.h"

// Private functions

void Game::_initVariables()
{
	_endGame = false;
	_mouseHeld = false;
}

void Game::_initWindow()
{
	_screenWidth = 800;
	_screenHeight = 600;
	_videoMode = sf::VideoMode(_screenWidth, _screenHeight);
	_window = new sf::RenderWindow(_videoMode, "Game", sf::Style::Default);
	_window->setFramerateLimit(144);
	_window->setVerticalSyncEnabled(false);
}

void Game::_initTextures()
{
	_textures["BULLET"] = sf::Texture();
	_textures["BULLET"].loadFromFile("Textures/bullet.png");
}

void Game::_initPlayer()
{
	_player = new Player();
	_playerDirX = 0.f;
	_playerDirY = 0.f;
}

// Public functions

// Constructor
Game::Game()
{
	_window = nullptr;
	_initVariables();
	_initWindow();
	_initPlayer();
}

// Destructor
Game::~Game()
{
	delete _player;
	delete _window;
}

void Game::_run()
{
	while (_window->isOpen())
	{
		_update();
		_render();
	}
}

void Game::_updatePollEvents()
{
	sf::Event e;
	while (_window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			_window->close();
		else if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			_window->close();
	}
}

void Game::_updateInputs()
{
	// Move player

	// Has to be reset otherwise will keep detecting keys pressed down
	// each check and keep adding/subtractng 1.f
	_playerDirX = 0.f;
	_playerDirY = 0.f;

	// Should add/subtract 1.f depending of if key is held from _playerDirX,
	// so if A is held, it equals -1.f, if D is also held, it equals 0.f,
	// if A is lifted, it equals 1.f, and if D is lifted, it equals 0.f.
	// Same for _playerDirY with W and S.

	// Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		_playerDirX -= 1.f;
	else
		_playerDirX += 1.f;
	// Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		_playerDirX += 1.f;
	else
		_playerDirX -= 1.f;
	// Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		_playerDirY -= 1.f;
	else
		_playerDirY += 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		_playerDirY += 1.f;
	else
		_playerDirY -= 1.f;

	_player->_move(_playerDirX, _playerDirY);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!_mouseHeld)
		{
			_mouseHeld = true;
			//                                 pos  pos  dir  dir  mvmntspd
			Bullet bullet(_textures["BULLET"], 0.f, 0.f, 0.f, 0.f, 0.f);
			_bulletsVector.push_back(bullet);
			// This is running but bullets are not being drawn
			std::cout << "hmm" << std::endl;
			int a = 0;
			for (auto& i : _bulletsVector)
				a++;
			std::cout << a << std::endl;
			//bullets are being added to vector, something wrong with textures
		}
	}
	else
		_mouseHeld = false;
}

void Game::_updateBullets()
{
	// Loops through + updates each bullet in _bulletsVector
	for (auto& i : _bulletsVector)
	{
		i.update();
	}
}

void Game::_update()
{
	_updatePollEvents();
	_updateInputs();
	_updateBullets();
}

void Game::_render()
{
	_window->clear();

	// Draw everything

	_player->_render(*_window);

	// Loops through + renders each bullet in _bulletsVector
	for (auto& i : _bulletsVector)
	{
		i.render(_window);
	}

	_window->display();
}
