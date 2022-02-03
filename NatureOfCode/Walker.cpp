#include "Walker.h";
#include <random>;

void Walker::walk(sf::CircleShape& circle) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 4);
	switch (dist(mt)) {
	case 1:
		++coord.x;
		break;
	case 2:
		--coord.x;
		break;
	case 3:
		++coord.y;
		break;
	case 4:
		--coord.y;
		break;
	default:
		break;
	}
	circle.setPosition(coord);
}