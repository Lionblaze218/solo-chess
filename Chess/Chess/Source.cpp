#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    /*
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    */
    
    sf::Texture texture;

    texture.loadFromFile("BlueChessBoard.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}