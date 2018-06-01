#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

using namespace sf;
using namespace std;

class GameManager
{
private:
	RenderWindow window;
	vector<Platform> platforms;
	vector<Player> players;

	const int windowWidth = 500;
	const int windowHeight = 400;
	const int playerWidth = 25;
	const int playerHeight = 45;

public:
GameManager(){
		window = makeWindow();
		platforms = makePlatforms();
		players = makePlayers();
	}
void moveObjects(){
	for(Player plr : players)
		plr.move(windowWidth);
	}
void drawState(){
	for(Platform pltfm : platforms)
		pltfm.draw(window);
	for(Player plr : players)
		plr.draw(window);
	}

RenderWindow& getWindow(){
	return window;
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
vector<Player> makePlayers(){
	std::vector<Player> v;
	Vector2f playerDim(playerWidth,playerHeight);
    Player p1 = Player(playerDim ,Vector2f(1,windowHeight-playerHeight),true, Color::Green,platforms);
    Player p2 = Player(playerDim ,Vector2f(windowWidth-playerWidth-1,windowHeight-playerHeight), false, Color::Red,platforms);
    v.push_back(p1);
    v.push_back(p2);
    return v;
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
}