#include "Game.h"

// Private functions

void Game::_initVariables()
{
	_endGame = false;
}

void Game::_initWindow()
{
	_screenWidth = 800;
	_screenHeight = 600;
	_videoMode = sf::VideoMode(_screenWidth, _screenHeight);
	_window = new sf::RenderWindow(_videoMode, "Game", sf::Style::Default);
	_window->setFramerateLimit(60);
}

// Public functions

// Constructor
Game::Game()
{
	_window = nullptr;
	_initVariables();
	_initWindow();
}

// Destructor
Game::~Game()
{
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

void Game::_update()
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

void Game::_render()
{
	_window->clear();

	// Draw everything

	_window->display();
}
