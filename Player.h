#pragma once
#include <SFML/Graphics.hpp>
#include "Platform.h"
using namespace sf;

class Player
{
protected:
	float dx;
	float dy;
	float groundHeight;
	int playerHeight;
	int playerWidth;
	bool grounded;
	RectangleShape player;
	bool hasWeapon;

	const float defaultXVelocity = 3.f;
	const float playerInitialJump = -15.f;
	const float gravityRate = 1.f;
	vector<Platform> platforms;
public:
	Player(Vector2f size, Vector2f pos, bool p1p2, Color c, const vector<Platform> t ){
		player.setSize(size);
		player.setPosition(pos);
		player.setFillColor(c);
		playerHeight= player.getSize().y;
		playerWidth = player.getSize().x;
		dx = p1p2?-defaultXVelocity:defaultXVelocity;
		dy = 0;
		grounded = true;
		groundHeight = pos.y+size.y;
		hasWeapon = true;
		platforms = t;
	}
	void draw(RenderWindow& window){
		window.draw(player);
	}

	//add's initial upwards momentum to jump
	void startJump(){
		if(onGround()){
			dy = playerInitialJump;
			setOnGround(false);
		}
	}

	//code to simulate gravity, adds rate of gravity to dy until you hit a platform or the floor
	void gravity(){
		//begin jump code
    	int platformHeight = groundHeight;
    	setYVelocity(getYVelocity() + getGravity());

    	//falling, need to check for collisions
    	if(getYVelocity()>0){
    		setOnGround(false);
    		for(Platform p : platforms){
    			if(getRightBound()>=p.getX()&&getX()<=p.getRightBound()&& p.getY()>=getLowerBound())
    				platformHeight = min(p.getY(),platformHeight);
    		}
    		if(getLowerBound() + getYVelocity()> platformHeight){
				setYVelocity(0.0);
			    setOnGround(true);
    		}	
    	}
    	
    	//end jump code
	}
	void move(int windowWidth){
		//check for collisions with the side boundaries
		if(windowWidth<=getRightBound()||getX()<=0)
			setXVelocity(-getXVelocity());

		gravity();

		player.move(Vector2f(getXVelocity(),getYVelocity()));
	}
	int getX() const{
		return player.getPosition().x;
	}
	int getY() const{
		return player.getPosition().y;
	}
	int getLowerBound()const{
		return player.getPosition().y+player.getSize().y;
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
	// ~Player();
};