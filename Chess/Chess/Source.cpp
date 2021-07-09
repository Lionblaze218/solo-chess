#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

//6 == Rook
//5 == Horse
//4 == Bishop
//3 == Queen
//2 == King
//1 == Pawns

vector<vector<int>> board ={{6,5,4,3,2,4,5,6},
                            {1,1,1,1,1,1,1,1},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {1,1,1,1,1,1,1,1},
                            {6,5,4,3,2,4,5,6} };

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(600, 600), "Chess");

    window.setFramerateLimit(60);

    window.setKeyRepeatEnabled(false);

    //Booleans//
    bool play = true;
    bool mouseClicked = false;
    bool mouseInsideReact = false;
    bool dragging = false;

    //Locations//
    int mouseX = 0;
    int mouseY = 0;

    sf::Vector2f mouse;
    
    sf::Texture textureBoard;
    textureBoard.loadFromFile("ChessBoard.png");

    sf::Texture texturePiece;
    texturePiece.loadFromFile("DarkPawn1.png");

    sf::Sprite spriteBoard;
    spriteBoard.setTexture(textureBoard);

    sf::Sprite spritePiece;
    spritePiece.setTexture(texturePiece);
    spritePiece.setPosition(450, 450);

    while (play == true)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                mouseClicked = true;

                if (spritePiece.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    dragging = true;
                    mouse.x = event.mouseButton.x - spritePiece.getGlobalBounds().left - spritePiece.getOrigin().x;
                    mouse.y = event.mouseButton.y - spritePiece.getGlobalBounds().top - spritePiece.getOrigin().y;

                }
            }

            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                mouseClicked = false;
                dragging = false;
            }

            if (event.type == sf::Event::MouseMoved) {
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
            }
        }

        if (dragging == true) {
            //spritePiece.setOrigin(mouseX, mouseY);
            spritePiece.setPosition(mouseX-32, mouseY-32);
        }

        window.clear();
        window.draw(spriteBoard);
        window.draw(spritePiece);
        window.display();

        if (event.type == sf::Event::Closed) {
            play = false;
        }
    }
    window.close();

    return 0;
}