#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Platform
{
	protected:
		RectangleShape platform;
	public:
		Platform(Vector2f size, Vector2f pos){
		platform.setSize(size);
		platform.setPosition(pos);
		platform.setFillColor(Color::White);
	}
	void draw(RenderWindow& window){
		window.draw(platform);
	}
	int getX()const{
		return platform.getPosition().x;
	}
	int getY()const{
		return platform.getPosition().y;
	}
	int getRightBound(){
		return getX()+platform.getSize().x;
	}
	int getHeight(){
		return platform.getSize().y;
	}
};