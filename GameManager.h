#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

class GameManager
{
protected:
	RenderWindow window;
	vector<Platform> platforms;
	vector<Player> players;
	vector<Weapon> weapons;
	float windowWidth;
	float windowHeight;
	static constexpr int playerWidth = 25;
	static constexpr int playerHeight = 45;	
public:
	GameManager(float w, float h){
		
		windowWidth = w;
		windowHeight = h;
		makePlatforms();
		makePlayers();
		// makeWeapons();

		makeWindow(windowWidth,windowHeight);
		
	}	
void moveObjects(){
	for(Player& plr : players)
		plr.move(windowWidth);
	}
void drawState(RenderWindow& window){
	for(Platform& pltfm : platforms){
		// cout<<pltfm.getX()<<endl;
		pltfm.draw(window);
	}
	for(Player& plr : players)
		plr.draw(window);
	for(Weapon& w: weapons)
		w.draw(window);
		// static RectangleShape r(Vector2f(20,30));
		// window.draw(r);
	}
void makePlatforms(){
    platforms.push_back(makeFloor());
	Vector2f pDim(100,5);

    Platform x = Platform (pDim, Vector2f(75,windowHeight-playerHeight-30));
    Platform y = Platform (pDim, Vector2f(windowWidth/2-pDim.x/2,windowHeight-playerHeight-125));
    Platform z = Platform (pDim, Vector2f(windowWidth-pDim.x-75,windowHeight-playerHeight-30));
    
    platforms.push_back (x);
    platforms.push_back (y);
    platforms.push_back (z);

}
void makePlayers(){
	Vector2f playerDim(playerWidth,playerHeight);
    Player p1 = Player(playerDim ,Vector2f(1,windowHeight-playerHeight),true, Color::Green,platforms);
    Player p2 = Player(playerDim ,Vector2f(windowWidth-playerWidth-1,windowHeight-playerHeight), false, Color::Red,platforms);
    players.push_back(p1);
    players.push_back(p2);
}

// void makeWeapons(){
// 	Player& p1 = players[0];
// 	Weapon we(Vector2f((float)p1.getX(),(float)p1.getY()-20));
// 	// cout<<p1.getX()<<" "<<p1.getY()<<endl;
// 	// cout<<we.w.getPosition().x<<" "<<we.w.getPosition().y<<endl;
// 	p1.giveWeapon(we);
// 	weapons.push_back(we);
// }


Platform makeFloor(){
	Platform floor = Platform(Vector2f(windowWidth, 1), Vector2f(0, windowHeight));
    return floor;
}

Player& getPlayerNumber(int n){
	return players[n-1];
}


void makeWindow(int windowWidth, int windowHeight){
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

}

RenderWindow& getWindow(){
	return window;
}
void clearWindow(){
	window.clear();
}
void displayWindow(){
	window.display();
}
};
