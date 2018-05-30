#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Player
{
protected:
	float dx;
	float dy;
	float groundHeight;
	bool grounded;
	RectangleShape player;
	float gravityRate;
public:
	Player(Vector2f size, Vector2f pos, float XVelocity, Color c){
		player.setSize(size);
		player.setPosition(pos);
		player.setFillColor(c);
		dx = XVelocity;
		dy = 0;
		grounded = true;
		groundHeight = pos.y;
		gravityRate = 0.6f;
	}
	void draw(RenderWindow& window){
		window.draw(player);
	}
	void move(int windowWidth){
		if((windowWidth-getRightBound())<=0||getX()<=0)
			setXVelocity(-getXVelocity());
		
		//begin jump code
		setYVelocity(getYVelocity() + getGravity());
    	float positionY = getY() + getYVelocity();
    	float positionX = getX() + getXVelocity();
    
    	if(positionY > groundHeight)
    	{
        	positionY = groundHeight;
        	setYVelocity (0.0);
        	setOnGround(true);
    	}
    	//end jump code

		player.move(Vector2f(getXVelocity(),getYVelocity()));
	}
	int getX() const{
		return player.getPosition().x;
	}
	int getY() const{
		return player.getPosition().y;
	}
	int getRightBound() const{
		return player.getPosition().x+player.getSize().x;
	}
	float getXVelocity() const{
		return dx;
	}
	float getYVelocity() const{
		return dy;
	}
	void setXVelocity(const float newX){
		dx = newX;
	}
	void setYVelocity(const float newY){
		dy = newY;
	}
	bool onGround(){
		return grounded;
	}
	void setOnGround(bool g){
		grounded = g;
	}
	float getGravity()const{
		return gravityRate;
	}
	void startJump(float initialYV){
		if(onGround()){
			dy = initialYV;
			setOnGround(false);
		}
	}
	// ~Player();
};