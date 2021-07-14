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

vector<vector<int>> boardPi ={{-6,-5,-4,-2,-3,-4,-5,-6},
                            {-1,-1,-1,-1,-1,-1,-1,-1},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {1,1,1,1,1,1,1,1},
                            {6,5,4,3,2,4,5,6} };

class movementStrat {

};

class chessPieces : public sf::Sprite {
private:
    int color; //0 = white, 1 = black
    bool firstMove = false;
    bool isAlive = true;
    movementStrat* strat = nullptr;
    int boardX;
    int boardY;

public:
    chessPieces(int x, int y, int c) {
        color = c;
        boardX = x;
        boardY = y;
    }
    void firstMoveMade() {
        firstMove = true;
    }
    void killPiece() {
        isAlive = false;
    }
    bool checkAlive() {
        return isAlive;
    }
    void setMoveStrat(movementStrat* strat_) {
        strat = strat_;
    }
    void setNewPosition(int x, int y) {
        boardX = x;
        boardY = y;
    }
    int getPositionX() {
        return boardX;
    }
    int getPositionY() {
        return boardY;
    }
    int getColor() {
        return color;
    }
};

vector<chessPieces> holder;

chessPieces bSpritePawn1(0, 1, 1);
sf::Texture bTextPawn1;

chessPieces bSpritePawn2(1, 1, 1);
sf::Texture bTextPawn2;

chessPieces bSpritePawn3(2, 1, 1);
sf::Texture bTextPawn3;

chessPieces bSpritePawn4(3, 1, 1);
sf::Texture bTextPawn4;

chessPieces bSpritePawn5(4, 1, 1);
sf::Texture bTextPawn5;

chessPieces bSpritePawn6(5, 1, 1);
sf::Texture bTextPawn6;

chessPieces bSpritePawn7(6, 1, 1);
sf::Texture bTextPawn7;

chessPieces bSpritePawn8(7, 1, 1);
sf::Texture bTextPawn8;

chessPieces bSpriteRook1(0, 0, 1);
sf::Texture bTextRook1;

chessPieces bSpriteRook2(7, 0, 1);
sf::Texture bTextRook2;

chessPieces bSpriteKnight1(1, 0, 1);
sf::Texture bTextKnight1;

chessPieces bSpriteKnight2(6, 0, 1);
sf::Texture bTextKnight2;

chessPieces bSpriteBishop1(2, 0, 1);
sf::Texture bTextBishop1;

chessPieces bSpriteBishop2(5, 0, 1);
sf::Texture bTextBishop2;

chessPieces bSpriteQueen(4, 0, 1);
sf::Texture bTextQueen;

chessPieces bSpriteKing(3, 0, 1);
sf::Texture bTextKing;

chessPieces wSpritePawn1(0 , 6, 0);
sf::Texture wTextPawn1;

chessPieces wSpritePawn2(1, 6, 0);
sf::Texture wTextPawn2;

chessPieces wSpritePawn3(2, 6, 0);
sf::Texture wTextPawn3;

chessPieces wSpritePawn4(3, 6, 0);
sf::Texture wTextPawn4;

chessPieces wSpritePawn5(4, 6, 0);
sf::Texture wTextPawn5;

chessPieces wSpritePawn6(5, 6, 0);
sf::Texture wTextPawn6;

chessPieces wSpritePawn7(6, 6, 0);
sf::Texture wTextPawn7;

chessPieces wSpritePawn8(7, 6, 0);
sf::Texture wTextPawn8;

chessPieces wSpriteRook1(0, 7, 0);
sf::Texture wTextRook1;

chessPieces wSpriteRook2(7, 7, 0);
sf::Texture wTextRook2;

chessPieces wSpriteKnight1(1, 7, 0);
sf::Texture wTextKnight1;

chessPieces wSpriteKnight2(6, 7, 0);
sf::Texture wTextKnight2;

chessPieces wSpriteBishop1(2, 7, 0);
sf::Texture wTextBishop1;

chessPieces wSpriteBishop2(5, 7, 0);
sf::Texture wTextBishop2;

chessPieces wSpriteQueen(3, 7, 0);
sf::Texture wTextQueen;

chessPieces wSpriteKing(4, 7, 0);
sf::Texture wTextKing;


int findPositionX(float pX) {
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

int findPositionY(float pY) {
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

    int y1 = 0;
    int y2 = 75;

    int y3 = 450;
    int y4 = 525;
    
    bTextPawn1.loadFromFile("pi/bPawn.png");
    bSpritePawn1.setTexture(bTextPawn1);
    bSpritePawn1.setPosition(0, y2);
    holder.push_back(bSpritePawn1);

    
    bTextPawn2.loadFromFile("pi/bPawn.png");
    bSpritePawn2.setTexture(bTextPawn2);
    bSpritePawn2.setPosition(75, y2);
    holder.push_back(bSpritePawn2);

    bTextPawn3.loadFromFile("pi/bPawn.png");
    bSpritePawn3.setTexture(bTextPawn3);
    bSpritePawn3.setPosition(150, y2);
    holder.push_back(bSpritePawn3);


    bTextPawn4.loadFromFile("pi/bPawn.png");
    bSpritePawn4.setTexture(bTextPawn4);
    bSpritePawn4.setPosition(225, y2);
    holder.push_back(bSpritePawn4);

    bTextPawn5.loadFromFile("pi/bPawn.png");
    bSpritePawn5.setTexture(bTextPawn5);
    bSpritePawn5.setPosition(300, y2);
    holder.push_back(bSpritePawn5);


    bTextPawn6.loadFromFile("pi/bPawn.png");
    bSpritePawn6.setTexture(bTextPawn6);
    bSpritePawn6.setPosition(375, y2);
    holder.push_back(bSpritePawn6);

    bTextPawn7.loadFromFile("pi/bPawn.png");
    bSpritePawn7.setTexture(bTextPawn7);
    bSpritePawn7.setPosition(450, y2);
    holder.push_back(bSpritePawn7);


    bTextPawn8.loadFromFile("pi/bPawn.png");
    bSpritePawn8.setTexture(bTextPawn8);
    bSpritePawn8.setPosition(525, y2);
    holder.push_back(bSpritePawn8);

    bTextRook1.loadFromFile("pi/bRook.png");
    bSpriteRook1.setTexture(bTextRook1);
    bSpriteRook1.setPosition(0, y1);
    holder.push_back(bSpriteRook1);

    bTextRook2.loadFromFile("pi/bRook.png");
    bSpriteRook2.setTexture(bTextRook2);
    bSpriteRook2.setPosition(525, y1);
    holder.push_back(bSpriteRook2);

    bTextKnight1.loadFromFile("pi/bKnight.png");
    bSpriteKnight1.setTexture(bTextKnight1);
    bSpriteKnight1.setPosition(75, y1);
    holder.push_back(bSpriteKnight1);

    bTextKnight2.loadFromFile("pi/bKnight.png");
    bSpriteKnight2.setTexture(bTextKnight2);
    bSpriteKnight2.setPosition(450, y1);
    holder.push_back(bSpriteKnight2);

    bTextBishop1.loadFromFile("pi/bBishop.png");
    bSpriteBishop1.setTexture(bTextBishop1);
    bSpriteBishop1.setPosition(150, y1);
    holder.push_back(bSpriteBishop1);

    bTextBishop2.loadFromFile("pi/bBishop.png");
    bSpriteBishop2.setTexture(bTextBishop2);
    bSpriteBishop2.setPosition(375, y1);
    holder.push_back(bSpriteBishop2);

    bTextKing.loadFromFile("pi/bKing.png");
    bSpriteKing.setTexture(bTextKing);
    bSpriteKing.setPosition(225, y1);
    holder.push_back(bSpriteKing);

    bTextQueen.loadFromFile("pi/bQueen.png");
    bSpriteQueen.setTexture(bTextQueen);
    bSpriteQueen.setPosition(300, y1);
    holder.push_back(bSpriteQueen);


    //--------------------------------------------

    wTextPawn1.loadFromFile("pi/wPawn.png");
    wSpritePawn1.setTexture(wTextPawn1);
    wSpritePawn1.setPosition(0, y3);
    holder.push_back(wSpritePawn1);


    wTextPawn2.loadFromFile("pi/wPawn.png");
    wSpritePawn2.setTexture(wTextPawn2);
    wSpritePawn2.setPosition(75, y3);
    holder.push_back(wSpritePawn2);

    wTextPawn3.loadFromFile("pi/wPawn.png");
    wSpritePawn3.setTexture(wTextPawn3);
    wSpritePawn3.setPosition(150, y3);
    holder.push_back(wSpritePawn3);


    wTextPawn4.loadFromFile("pi/wPawn.png");
    wSpritePawn4.setTexture(wTextPawn4);
    wSpritePawn4.setPosition(225, y3);
    holder.push_back(wSpritePawn4);

    wTextPawn5.loadFromFile("pi/wPawn.png");
    wSpritePawn5.setTexture(wTextPawn5);
    wSpritePawn5.setPosition(300, y3);
    holder.push_back(wSpritePawn5);


    wTextPawn6.loadFromFile("pi/wPawn.png");
    wSpritePawn6.setTexture(wTextPawn6);
    wSpritePawn6.setPosition(375, y3);
    holder.push_back(wSpritePawn6);

    wTextPawn7.loadFromFile("pi/wPawn.png");
    wSpritePawn7.setTexture(wTextPawn7);
    wSpritePawn7.setPosition(450, y3);
    holder.push_back(wSpritePawn7);

    wTextPawn8.loadFromFile("pi/wPawn.png");
    wSpritePawn8.setTexture(wTextPawn8);
    wSpritePawn8.setPosition(525, y3);
    holder.push_back(wSpritePawn8);

    wTextRook1.loadFromFile("pi/wRook.png");
    wSpriteRook1.setTexture(wTextRook1);
    wSpriteRook1.setPosition(0, y4);
    holder.push_back(wSpriteRook1);

    wTextRook2.loadFromFile("pi/wRook.png");
    wSpriteRook2.setTexture(wTextRook2);
    wSpriteRook2.setPosition(525, y4);
    holder.push_back(wSpriteRook2);

    wTextKnight1.loadFromFile("pi/wKnight.png");
    wSpriteKnight1.setTexture(wTextKnight1);
    wSpriteKnight1.setPosition(75, y4);
    holder.push_back(wSpriteKnight1);

    wTextKnight2.loadFromFile("pi/wKnight.png");
    wSpriteKnight2.setTexture(wTextKnight2);
    wSpriteKnight2.setPosition(450, y4);
    holder.push_back(wSpriteKnight2);

    wTextBishop1.loadFromFile("pi/wBishop.png");
    wSpriteBishop1.setTexture(wTextBishop1);
    wSpriteBishop1.setPosition(150, y4);
    holder.push_back(wSpriteBishop1);

    wTextBishop2.loadFromFile("pi/wBishop.png");
    wSpriteBishop2.setTexture(wTextBishop2);
    wSpriteBishop2.setPosition(375, y4);
    holder.push_back(wSpriteBishop2);

    wTextQueen.loadFromFile("pi/wQueen.png");
    wSpriteQueen.setTexture(wTextQueen);
    wSpriteQueen.setPosition(225, y4);
    holder.push_back(wSpriteQueen);

    wTextKing.loadFromFile("pi/wKing.png");
    wSpriteKing.setTexture(wTextKing);
    wSpriteKing.setPosition(300, y4);
    holder.push_back(wSpriteKing);
    }

    bool checkIfSameColor(chessPieces temp1, chessPieces temp2) {
        if (temp1.getColor() == temp2.getColor()) {
            return true;
        }
        return false;
    }

    int checkCollision(int x, int y, int z) {
        for (int i = 0; i < holder.size(); i++) {
            if (i == z || !holder[i].checkAlive()) {
                continue;
            }
            if (holder[i].getPositionX() == x && holder[i].getPositionY() == y) { 
                return i;
            }
        }
        return -1;
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
    int posX = 0;
    int posY = 0;

    sf::Vector2f mouse;
    
    sf::Texture textureBoard;
    sf::Texture texturePiece;
    sf::Sprite spriteBoard;
    sf::Sprite spritePiece;

    vector<sf::Sprite> bPieces;
    vector<sf::Sprite> wPieces;

    int prevX = 0;
    int prevY = 0;

    buildBoard(textureBoard, texturePiece, bPieces, wPieces, spriteBoard, spritePiece);

    int z = -1;

    while (play == true)
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            //cout << "holder size: " << holder.size() << endl;
            if (event.type == sf::Event::Closed)
                window.close();

            
            for (int i = 0; i < holder.size(); i++) {
                if (!holder[i].checkAlive()) {
                    continue;
                }
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    mouseClicked = true;

                    if (holder[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        //cout << "Found at :" << event.mouseButton.x << endl;
                        prevX = event.mouseButton.x;
                        prevY = event.mouseButton.y;
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

                    int b = checkCollision(posX / 75, posY / 75, z);
                    if (b != -1) {
                        if (checkIfSameColor(holder[z], holder[b])) {
                            holder[z].setPosition(findPositionX(prevX), findPositionY(prevY));
                        }
                        else{
                            holder[b].killPiece();
                            holder[z].setNewPosition(posX / 75, posY / 75);
                            holder[z].setPosition(findPositionX(posX), findPositionY(posY));
                        }
                    }
                    else {
                        holder[z].setNewPosition(posX / 75, posY / 75);
                        holder[z].setPosition(findPositionX(posX), findPositionY(posY));
                    }

            }

            if (event.type == sf::Event::MouseMoved) {
                    mouseX = event.mouseMove.x;
                    mouseY = event.mouseMove.y;
            }
        }

        if (dragging == true && z != -1) {
            cout << "z: " << z << endl;
            holder[z].setPosition(mouseX- holder[z].getLocalBounds().width/2, mouseY- holder[z].getLocalBounds().height/2);
        }

        window.clear();
        window.draw(spriteBoard);
        for (int j = 0; j < holder.size(); j++) {
            if (!holder[j].checkAlive()) {
                continue;
            }
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