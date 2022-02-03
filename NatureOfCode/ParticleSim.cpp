#include "ParticleSim.h"
#include "Particle.h"
#include <iostream>;
ParticleSim::ParticleSim() {
	window = new sf::RenderWindow(sf::VideoMode(1000, 800), "Particle");

}
void ParticleSim::render() {
    window->setFramerateLimit(60);
    
    Particle p{ sf::Vector2f{400.0f ,400.0f }, sf::Vector2f{400.0f ,500.0f } };
    sf::CircleShape circle(5.0f);
    sf::CircleShape circle2(5.0f);
 
    circle.setPosition(sf::Vector2f{ p.coord.x - 5.0f,p.coord.y - 5.0f });
    circle.setFillColor(sf::Color::White);
    circle2.setPosition(sf::Vector2f{ p.coord2.x - 5.0f,p.coord2.y - 5.0f });
    circle2.setFillColor(sf::Color::White);
    sf::RectangleShape rect;
    rect.setPosition(sf::Vector2f{ p.anchorCoord.x - 5.0f,p.anchorCoord.y - 5.0f });
    rect.setSize(sf::Vector2f{ 10.0,10.0 });
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1.0);
    rect.setFillColor(sf::Color::Transparent);
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f{p.coord.x,p.coord.y}),
        sf::Vertex(p.anchorCoord)
    };
    sf::Vertex line2[] =
    {
        sf::Vertex(sf::Vector2f{p.coord2.x,p.coord2.y}),
        sf::Vertex(p.coord)
    };
    //room
    sf::Vertex line3[] =
    {
        sf::Vertex(sf::Vector2f{200,0}),
        sf::Vertex(sf::Vector2f{200,350})
    };
    sf::Vertex line4[] =
    {
        sf::Vertex(sf::Vector2f{200,350}),
        sf::Vertex(sf::Vector2f{600,800})
    };
    sf::Vertex line5[] =
    {
        sf::Vertex(sf::Vector2f{200,350}),
        sf::Vertex(sf::Vector2f{0,400})
    };
    //window
    //left
    sf::Vertex line6[] =
    {
        sf::Vertex(sf::Vector2f{p.anchorCoord.x+10,p.anchorCoord.y-10}),
        sf::Vertex(sf::Vector2f{ p.anchorCoord.x - 5.0f ,p.anchorCoord.y - 5.0f +150 })
    };
    //right
    sf::Vertex line7[] =
    {
        sf::Vertex(sf::Vector2f{p.anchorCoord.x + 117,p.anchorCoord.y +100}),
        sf::Vertex(sf::Vector2f{ p.anchorCoord.x - 5.0f + 110,p.anchorCoord.y - 5.0f + 250 })
    };
    //bottom
    sf::Vertex line8[] =
    {
        sf::Vertex(sf::Vector2f{p.anchorCoord.x -5,p.anchorCoord.y - 5+150}),
        sf::Vertex(sf::Vector2f{ p.anchorCoord.x -5+110,p.anchorCoord.y - 5.0f + 250 })
    };
    //top
    sf::Vertex line9[] =
    {
        sf::Vertex(sf::Vector2f{p.anchorCoord.x +10,p.anchorCoord.y-10 }),
        sf::Vertex(sf::Vector2f{ p.anchorCoord.x +117,p.anchorCoord.y +100 })
    };
    sf::Clock clock;

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        sf::Time time = clock.getElapsedTime();

        window->clear();
        window->draw(line3, 2, sf::Lines);
        window->draw(line4, 2, sf::Lines);
        window->draw(line5, 2, sf::Lines);
        window->draw(line6, 2, sf::Lines);
        window->draw(line7, 2, sf::Lines);
        window->draw(line8, 2, sf::Lines);
        window->draw(line9, 2, sf::Lines);
        for (float i = 10; i < 102; i+=2) {
            std::cout << i << '\n';
            sf::RectangleShape rect;
            rect.setSize(sf::Vector2f{ 10.0,10.0 });
            rect.setOutlineColor(sf::Color::White);
            rect.setOutlineThickness(1.0);
            rect.setFillColor(sf::Color::Transparent);
            rect.setPosition(sf::Vector2f{ p.anchorCoord.x - 5.0f+i,p.anchorCoord.y - 5.0f+i });

            sf::CircleShape circle(5.0f);
            circle.setPosition(sf::Vector2f{ p.coord.x - 5.0f + i,p.coord.y - 5.0f + i });

            sf::CircleShape circle2(5.0f);
            circle2.setPosition(sf::Vector2f{ p.coord2.x - 5.0f+i,p.coord2.y - 5.0f+i });

            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f{p.coord.x+i,p.coord.y+i}),
                sf::Vertex(sf::Vector2f{p.anchorCoord.x+i,p.anchorCoord.y+i})
            };
            sf::Vertex line2[] =
            {
                sf::Vertex(sf::Vector2f{p.coord2.x+i,p.coord2.y+i}),
                sf::Vertex(sf::Vector2f{p.coord.x+i,p.coord.y+i})
            };
           // window->clear();
            window->draw(circle);
            window->draw(circle2);
            window->draw(rect);
            window->draw(line, 2, sf::Lines);
            window->draw(line2, 2, sf::Lines);

        }
      //  window->draw(rect);
      //  window->draw(line, 2, sf::Lines);
       // window->draw(line2, 2, sf::Lines);
      //  window->draw(circle);
      //  window->draw(circle2);
        p.gravityCalc(circle, circle2);
 

       // line[0] = sf::Vertex(sf::Vector2f{ p.coord.x,p.coord.y });
       // line2[0] = sf::Vertex(sf::Vector2f{ p.coord2.x,p.coord2.y });
       // line2[1] = sf::Vertex(p.coord);
        window->display();
    }

}