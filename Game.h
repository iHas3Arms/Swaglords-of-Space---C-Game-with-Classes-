#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Game
{
private:
	bool _endGame;

	// Window variables
	sf::RenderWindow* _window;
	sf::VideoMode _videoMode;
	int _screenWidth, _screenHeight;

	// Init functions
	void _initVariables();
	void _initWindow();
public:
	// Con/Des
	Game();
	virtual ~Game();
	// Virtual allows the deconstructors of derived classes
	// to be run because the vptr points to them first in the vtable

	// Functions
	void _run();
	void _update();
	void _render();
};