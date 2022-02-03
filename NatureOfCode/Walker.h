#pragma once
#include <SFML/Graphics.hpp>

class Walker {
	int x;
	int y;
	sf::CircleShape& circle;
public:
	sf::Vector2f coord{ x, y };

	Walker(int x, int y,sf::CircleShape circle) : x(x), y(y), coord{ x,y },circle(circle) {};
	void walk(sf::CircleShape& circle);
};