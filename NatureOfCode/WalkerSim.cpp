#include "WalkerSim.h"
#include "Walker.h"
#include <random>
#include <iostream>
#include <time.h>
WalkerSim::WalkerSim() {
	window = new sf::RenderWindow(sf::VideoMode(1000, 800), "Random Walker");

}
sf::Color WalkerSim::randomColor() {

    double val = (double)rand() / RAND_MAX;

    if (val < 0.1)       //  10%
        return sf::Color::Green;
    else if (val < 0.25)  //  10% + 15%
        return sf::Color::Blue;
    else if (val < 0.45)  //  10% + 15% + 20%
        return sf::Color::Yellow;
    else
        return sf::Color::Magenta; //55%
}
void WalkerSim::render() {
    //  window.setFramerateLimit(144);
    sf::CircleShape circle(1.0f);
    Walker random{ 250,250,circle };
    circle.setPosition(random.coord);
    circle.setFillColor(sf::Color::Green);
    sf::Clock clock;
    int g{ 0 };
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        g++;
        sf::Time time = clock.getElapsedTime();
        std::cout << time.asSeconds() << '\n';
        //    if (static_cast<int>(time.asSeconds()) % 5==0)
               // circle.setFillColor(randomColor());
        if (g > 800) {
            circle.setFillColor(randomColor());
            g = 0;
        }
        // window.clear();
        window->draw(circle);
        random.walk(circle);
        window->display();
    }

}