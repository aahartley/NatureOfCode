#include "Particle.h"
#include "ParticleSim.h"
#include <iostream>
void Particle::gravityCalc(sf::CircleShape& circle, sf::CircleShape& circle2) {
	
	
	//mass 1 spring force
	float springForceY = -k * (coord.y - anchorCoord.y);
	float springForceX = -k * (coord.x - anchorCoord.x);

	//mass 2 spring force
	float springForce2Y = -k * (coord2.y - coord.y);
	float springForce2X = -k * (coord2.x - coord.x);

	//mass 1 damping
	float dampingForceY = velocityY * damping;
	float dampingForceX = velocityX * damping;

	//mass 2 damping
	float dampingForce2Y = velocity2Y * damping;
	float dampingForce2X = velocity2X * damping;

	//mass 1 force
	float forceX = (springForceX - dampingForceX) - (springForce2X+ dampingForce2X);
	float forceY = ((springForceY + (mass * gravity)) - dampingForceY) - (dampingForce2Y+springForce2Y);

	//mass 2 force
	float force2X = springForce2X - dampingForce2X;
	float force2Y = (springForce2Y + (mass * gravity)) - dampingForce2Y;

	//mass 1 acceerlation
	float accelerationY = forceY / mass;
	float accelerationX = forceX / mass;

	//mass 2 acceleration

	float acceleration2Y = force2Y / mass2;
	float acceleration2X = force2X / mass2;

	// mass 1 velocity
	velocityY += accelerationY * timeStep;
	velocityX += accelerationX * timeStep;

	//mass 2 velocity
	velocity2Y += acceleration2Y * timeStep;
	velocity2X += acceleration2X * timeStep;

	// mass 1 coord
	coord.y += velocityY * timeStep;
	coord.x += velocityX * timeStep;
	
	circle.setPosition(sf::Vector2f{coord.x-5,coord.y-5});

	//mass 2 coord
	coord2.y += velocity2Y * timeStep;
	coord2.x += velocity2X * timeStep;
	circle2.setPosition(sf::Vector2f{ coord2.x - 5,coord2.y - 5 });



}
