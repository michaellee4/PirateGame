/*
Inspired by Micro Battles Pirate game
To-do priority

1.implement one-way platforms
2.implement weapons and how to throw them
3.implement characted/weapon collision 
4.possibly implement a game object manager
5.add sprites
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameManager.h"
#include "Player.h"

using namespace sf;
using namespace std;

int main()  
{   
	float windowWidth = 500.f;
	float windowHeight = 400.f;
    GameManager gm(windowWidth,windowHeight);
    RenderWindow& window = gm.getWindow();

    Player& p1 = gm.getPlayerNumber(1);
    Player& p2 = gm.getPlayerNumber(2);

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
        	//allows us to close by x'ing or pressing q
            if (event.type == Event::Closed)
                window.close();
            if(Keyboard::isKeyPressed(Keyboard::Q))
                window.close();

            //handles inputs for jump, and eventually throwing
            if (event.type == Event::KeyPressed){
                if (event.key.code == Keyboard::Space){
                    p1.startJump();
                }
                if(event.key.code==Keyboard::Period){
                    p2.startJump();
                }
            }
        }
        gm.clearWindow();
        //draw players
        gm.drawState(window);
        //end current frame
        gm.displayWindow();
        //move the character shapes
        gm.moveObjects();
    }
    window.close();
    return 0;
}
