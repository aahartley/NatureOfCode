#pragma once
#include <SFML/Graphics.hpp>

class ParticleSim{
public:
	ParticleSim();
	void render();
	sf::RenderWindow* getWindow() { return window; }
private:
	sf::RenderWindow* window;

};