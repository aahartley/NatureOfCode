#pragma once
#include <SFML/Graphics.hpp>

class Particle {
public:
	sf::Vector2f anchorCoord;
	sf::Vector2f coord;
	sf::Vector2f coord2;
	float gravity{ 10.0f };
	float timeStep{ 0.22f };
	float k{ 7.0f };
	float damping{ 5.0f };
	Particle(sf::Vector2f coord, sf::Vector2f coord2) :coord(coord), coord2(coord2), anchorCoord{ 500.0f,200.0f }, velocityY(0), velocityX(0), velocity2Y(0), velocity2X(0), mass(30), mass2(30) {}
	void gravityCalc(sf::CircleShape& circle, sf::CircleShape& circle2);
	float getVelocityY() { return velocityY ;}


private:
	float velocityY,mass,velocityX,mass2,velocity2X,velocity2Y;
};