#pragma once
#include <SFML/Graphics.hpp>

class WalkerSim {
	sf::RenderWindow* window;

public:
	WalkerSim();
	sf::Color randomColor();
	void render();
};