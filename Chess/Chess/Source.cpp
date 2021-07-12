#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;

//Since the board is 600x600 for an 8x8, each square is a 75x75 piece

vector<vector<int>> board = { {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0} };


//6 == Rook
//5 == Horse
//4 == Bishop
//3 == Queen
//2 == King
//1 == Pawns

vector<vector<int>> boardPi ={{6,5,4,3,2,4,5,6},
                            {1,1,1,1,1,1,1,1},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {1,1,1,1,1,1,1,1},
                            {6,5,4,3,2,4,5,6} };

vector<sf::Sprite> holder;




class bPawn1 : public sf::Sprite {

};
class bPawn2 : public sf::Sprite {

};
class bPawn3 : public sf::Sprite {

};
class bPawn4 : public sf::Sprite {

};
class bPawn5 : public sf::Sprite {

};
class bPawn6 : public sf::Sprite {

};
class bPawn7 : public sf::Sprite {

};
class bPawn8 : public sf::Sprite {

};

bPawn1 bSpritePawn1;
sf::Texture bTextPawn1;

bPawn1 bSpritePawn2;
sf::Texture bTextPawn2;

bPawn3 bSpritePawn3;
sf::Texture bTextPawn3;

bPawn4 bSpritePawn4;
sf::Texture bTextPawn4;

bPawn5 bSpritePawn5;
sf::Texture bTextPawn5;

bPawn6 bSpritePawn6;
sf::Texture bTextPawn6;

bPawn7 bSpritePawn7;
sf::Texture bTextPawn7;

bPawn8 bSpritePawn8;
sf::Texture bTextPawn8;

float findPositionX(float pX) {
    float num = 0;
    float num2 = 0;

    for (int i = 0; i < 7; i++) {
        num2 = num + 75;
        if (num <= pX && pX <= num2) {
            return num;
        }
        num += 75;
    }
    return 525;
}

float findPositionY(float pY) {
    float num = 0;
    float num2 = 0;

    for (int i = 0; i < 7; i++) {
        num2 = num + 75;
        if (num <= pY && pY <= num2) {
            return num;
        }
        num += 75;
    }
    return 525;
}

void buildBoard(sf::Texture& textureBoard, sf::Texture& texturePiece, vector<sf::Sprite>& bPieces, vector<sf::Sprite>& wPieces, sf::Sprite& spriteBoard, sf::Sprite& spritePiece) {
    
    textureBoard.loadFromFile("ChessBoard.png");
    spriteBoard.setTexture(textureBoard);
    
    bTextPawn1.loadFromFile("pi/bPawn.png");
    bSpritePawn1.setTexture(bTextPawn1);
    bSpritePawn1.setPosition(0, 450);
    holder.push_back(bSpritePawn1);

    
    bTextPawn2.loadFromFile("pi/bPawn.png");
    bSpritePawn2.setTexture(bTextPawn2);
    bSpritePawn2.setPosition(75, 450);
    holder.push_back(bSpritePawn2);

    bTextPawn3.loadFromFile("pi/bPawn.png");
    bSpritePawn3.setTexture(bTextPawn3);
    bSpritePawn3.setPosition(150, 450);
    holder.push_back(bSpritePawn3);


    bTextPawn4.loadFromFile("pi/bPawn.png");
    bSpritePawn4.setTexture(bTextPawn4);
    bSpritePawn4.setPosition(225, 450);
    holder.push_back(bSpritePawn4);

    bTextPawn5.loadFromFile("pi/bPawn.png");
    bSpritePawn5.setTexture(bTextPawn5);
    bSpritePawn5.setPosition(300, 450);
    holder.push_back(bSpritePawn5);


    bTextPawn6.loadFromFile("pi/bPawn.png");
    bSpritePawn6.setTexture(bTextPawn6);
    bSpritePawn6.setPosition(375, 450);
    holder.push_back(bSpritePawn6);

    bTextPawn7.loadFromFile("pi/bPawn.png");
    bSpritePawn7.setTexture(bTextPawn7);
    bSpritePawn7.setPosition(450, 450);
    holder.push_back(bSpritePawn7);


    bTextPawn8.loadFromFile("pi/bPawn.png");
    bSpritePawn8.setTexture(bTextPawn8);
    bSpritePawn8.setPosition(525, 450);
    holder.push_back(bSpritePawn8);

    /*
    sf::Sprite bPiece;

    
    bTextPawn.loadFromFile("pi/bPawn.png");
    bPiece.setTexture(bTextPawn);

    for (int i = 0; i < 8; i++) {
        bPiece.setTexture(bTextPawn);
        bPiece.setPosition(x, 450);
        bPieces.push_back(bPiece);
        x += 75;
    }
    
    texturePiece.loadFromFile("pi/bRook.png");
    bPiece.setTexture(texturePiece);
    bPiece.setPosition(0, 525);
    bPieces.push_back(bPiece);
    bPiece.setPosition(525, 525);
    bPieces.push_back(bPiece);

    texturePiece.loadFromFile("pi/bBishop.png");
    bPiece.setTexture(texturePiece);
    bPiece.setPosition(75, 525);
    bPieces.push_back(bPiece);
    bPiece.setPosition(450, 525);
    bPieces.push_back(bPiece);


    texturePiece.loadFromFile("pi/bKnight.png");
    bPiece.setTexture(texturePiece);
    bPiece.setPosition(150, 525);
    bPieces.push_back(bPiece);
    bPiece.setPosition(375, 525);
    bPieces.push_back(bPiece);

    texturePiece.loadFromFile("pi/bKing.png");
    bPiece.setTexture(texturePiece);
    bPiece.setPosition(225, 525);
    bPieces.push_back(bPiece);

    texturePiece.loadFromFile("pi/bQueen.png");
    bPiece.setTexture(texturePiece);
    bPiece.setPosition(300, 525);
    bPieces.push_back(bPiece);

    //------------------------------------------------------------------------------------------------------------------
    /*
    sf::Sprite wPiece;
    texturePiece.loadFromFile("pi/wPawn.png");
    for (int i = 0; i < 8; i++) {
        wPiece.setTexture(texturePiece);
        wPieces.push_back(wPiece);
    }
    texturePiece.loadFromFile("pi/wRook.png");
    wPiece.setTexture(texturePiece);
    wPieces.push_back(wPiece);

    texturePiece.loadFromFile("pi/wBishop.png");
    wPiece.setTexture(texturePiece);
    wPieces.push_back(wPiece);

    texturePiece.loadFromFile("pi/wKnight.png");
    wPiece.setTexture(texturePiece);
    wPieces.push_back(wPiece);

    texturePiece.loadFromFile("pi/wKing.png");
    wPiece.setTexture(texturePiece);
    wPieces.push_back(wPiece);

    texturePiece.loadFromFile("pi/wQueen.png");
    wPiece.setTexture(texturePiece);
    wPieces.push_back(wPiece);
    
    
    
    texturePiece.loadFromFile("pi/bKnight.png");
    spritePiece.setTexture(texturePiece);
    spritePiece.setPosition(450, 450);
    */
    }

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
    float posX = 0;
    float posY = 0;

    sf::Vector2f mouse;
    
    sf::Texture textureBoard;
    sf::Texture texturePiece;
    sf::Sprite spriteBoard;
    sf::Sprite spritePiece;

    vector<sf::Sprite> bPieces;
    vector<sf::Sprite> wPieces;


    buildBoard(textureBoard, texturePiece, bPieces, wPieces, spriteBoard, spritePiece);

    int z = -1;

    while (play == true)
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            
            for (int i = 0; i < holder.size(); i++) {
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    mouseClicked = true;

                    if (holder[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        cout << "Found at :" << event.mouseButton.x << endl;
                        z = i;
                        dragging = true;
                        mouse.x = event.mouseButton.x - holder[i].getGlobalBounds().left - holder[i].getOrigin().x;
                        mouse.y = event.mouseButton.y - holder[i].getGlobalBounds().top - holder[i].getOrigin().y;
                        break;
                    }
                    else {
                        z = -1;
                    }
                }
            }


            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && z != -1) {
                    mouseClicked = false;
                    dragging = false;
                    posX = holder[z].getLocalBounds().left + mouseX;
                    posY = holder[z].getLocalBounds().top + mouseY;
                    cout << "posX: " << posX << endl;
                    cout << "posY: " << posY << endl;

                    holder[z].setPosition(findPositionX(posX), findPositionY(posY));
            }

            if (event.type == sf::Event::MouseMoved) {
                    mouseX = event.mouseMove.x;
                    mouseY = event.mouseMove.y;
            }
        }

        if (dragging == true && z != -1) {
            cout << "z" << z << endl;
            holder[z].setPosition(mouseX- holder[z].getLocalBounds().width/2, mouseY- holder[z].getLocalBounds().height/2);
        }

        window.clear();
        window.draw(spriteBoard);
        for (int j = 0; j < holder.size(); j++) {
            //cout << "j: " << j << endl;
            window.draw(holder[j]);
        }
        window.display();

        if (event.type == sf::Event::Closed) {
            play = false;
        }
    }
    window.close();

    return 0;
}