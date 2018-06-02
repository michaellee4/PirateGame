// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include "Player.h"
#include "GameManager.h"

using namespace sf;
using namespace std;

extern float windowWidth, windowHeight;

void GameManager::moveObjects(){
	for(Player& plr : players)
		plr.move(windowWidth);
	}
void GameManager::drawState(RenderWindow& window){
	for(Platform& pltfm : platforms){
		// cout<<pltfm.getX()<<endl;
		pltfm.draw(window);
	}
	for(Player& plr : players)
		plr.draw(window);
		// static RectangleShape r(Vector2f(20,30));
		// window.draw(r);
	}
void GameManager::makePlatforms(){
    platforms.push_back(makeFloor());
	Vector2f pDim(100,5);

	cout<<windowHeight<<" "<<windowWidth<<endl;
    Platform x = Platform (pDim, Vector2f(75,windowHeight-playerHeight-30));
    Platform y = Platform (pDim, Vector2f(windowWidth/2-pDim.x/2,windowHeight-playerHeight-125));
    Platform z = Platform (pDim, Vector2f(windowWidth-pDim.x-75,windowHeight-playerHeight-30));
    
    platforms.push_back (x);
    platforms.push_back (y);
    platforms.push_back (z);

}
void GameManager::makePlayers(){
	Vector2f playerDim(playerWidth,playerHeight);
    Player p1 = Player(playerDim ,Vector2f(1,windowHeight-playerHeight),true, Color::Green,platforms);
    Player p2 = Player(playerDim ,Vector2f(windowWidth-playerWidth-1,windowHeight-playerHeight), false, Color::Red,platforms);
    players.push_back(p1);
    players.push_back(p2);
}

Platform GameManager::makeFloor(){
	Platform floor = Platform(Vector2f(windowWidth, 1), Vector2f(0, windowHeight));
    return floor;
}

Player& GameManager::getPlayerNumber(int n){
	return players[n-1];
}
