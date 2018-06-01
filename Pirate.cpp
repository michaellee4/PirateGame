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
#include "Player.h"

using namespace sf;
using namespace std;

const int windowWidth = 500;
const int windowHeight = 400;
const int playerWidth = 25;
const int playerHeight = 45;

RenderWindow& makeWindow();
Platform makeFloor();
vector<Platform> makePlatforms();

int main()  
{   
    //Creates the drawing window
    RenderWindow& window = makeWindow();
 
    //test platform, 1st platform to be added must be the floor
    vector<Platform> platforms = makePlatforms();

    //initialize player rectangles
    Vector2f playerDim(playerWidth,playerHeight);
    Player p1 = Player(playerDim ,Vector2f(1,windowHeight-playerHeight),true, Color::Green,platforms);
    Player p2 = Player(playerDim ,Vector2f(windowWidth-playerWidth-1,windowHeight-playerHeight), false, Color::Red,platforms);


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
        window.clear();
        //draw players
        for(Platform p : platforms)
            p.draw(window);
        p1.draw(window);
        p2.draw(window);
        //end current frame
        window.display();
        //move the character shapes
        p1.move(windowWidth);
        p2.move(windowWidth);
    }
    window.close();
    return 0;
}


vector<Platform> makePlatforms(){

	vector<Platform> platforms;
    platforms.push_back(makeFloor());
	Vector2f pDim(100,5);

    Platform x = Platform (pDim, Vector2f(75,windowHeight-playerHeight-30));
    Platform y = Platform (pDim, Vector2f(windowWidth/2-pDim.x/2,windowHeight-playerHeight-125));
    Platform z = Platform (pDim, Vector2f(windowWidth-pDim.x-75,windowHeight-playerHeight-30));
    
    
    platforms.push_back (x);
    platforms.push_back (y);
    platforms.push_back (z);


    return platforms;
}

Platform makeFloor(){
	Platform floor = Platform(Vector2f(windowWidth, 1), Vector2f(0, windowHeight));
    return floor;
}

RenderWindow& makeWindow(){
	static RenderWindow window;

    window.create(VideoMode(windowWidth, windowHeight), "Game");

    //gets the dimensions of the current screen to center the window
    int height = VideoMode::getDesktopMode().height;
    int width = VideoMode::getDesktopMode().width;

    //centers the window
    window.setPosition(Vector2i(width/2-windowWidth/2,height/2-windowHeight/2));

    //enable V-sync
    window.setVerticalSyncEnabled(true);

    //limits to 1 action per key press
    window.setKeyRepeatEnabled(false);

    return window;
}