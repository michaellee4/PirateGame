#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
using namespace sf;
using namespace std;

const int windowWidth = 500;
const int windowHeight = 200;
const int playerWidth = 25;
const int playerHeight = 45;
const float playerXVelocity = 3.3f;
const float playerInitialJump = -8.5f;

RenderWindow window;

//gravity variables
const int groundHeight = windowHeight-playerHeight;
void makeWindow();

int main()  
{   
    //Creates the drawing window
    makeWindow();
    //initialize player rectangle

    Player p1 = Player(Vector2f(playerWidth,playerHeight),Vector2f(1,windowHeight-playerHeight),playerXVelocity, Color::Green);
    Player p2 = Player(Vector2f(playerWidth,playerHeight),Vector2f(windowWidth-playerWidth-1,windowHeight-playerHeight), -playerXVelocity, Color::Red);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed){
                if (event.key.code == Keyboard::Space){
                    p1.startJump(playerInitialJump);
                }
                if(event.key.code==Keyboard::W){
                    p2.startJump(playerInitialJump);
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Q))
                window.close();
        }

        window.clear();
        //draw here
        p1.draw(window);
        p2.draw(window);
        //end current frame
        window.display();
        p1.move(windowWidth);
        p2.move(windowWidth);
    }
    window.close();

    return 0;
}

void makeWindow(){
    window.create(VideoMode(windowWidth, windowHeight), "SFML works!");

    //gets the dimensions of the current screen to center the window
    int height = VideoMode::getDesktopMode().height;
    int width = VideoMode::getDesktopMode().width;

    //centers the window
    window.setPosition(Vector2i(width/2-windowWidth/2,height/2-windowHeight/2));

    //enable V-sync
    window.setVerticalSyncEnabled(true);

    //limits to 1 action per key press
    window.setKeyRepeatEnabled(false);
}