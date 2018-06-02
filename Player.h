#pragma once
#include <SFML/Graphics.hpp>
#include "Platform.h"
#include "Weapon.h"
using namespace sf;

class Player
{
protected:
	int dx;
	int dy;
	int playerHeight;
	int playerWidth;
	bool grounded;
	RectangleShape player;
	Weapon* weapon;

	constexpr static int defaultXVelocity = 3;
	constexpr static int playerInitialJump = -15;
	constexpr static int gravityRate = 1;

	vector<Platform> platforms;
	vector<Weapon> weapons;
public:
	Player(Vector2f size, Vector2f pos, bool p1p2, Color c, const vector<Platform> t){//, const vector<Weapon> weapons
		player.setSize(size);
		player.setPosition(pos);
		player.setFillColor(c);
		playerHeight= player.getSize().y;
		playerWidth = player.getSize().x;
		platforms = t;

		dx = p1p2?-defaultXVelocity:defaultXVelocity;
		dy = 0;
		grounded = true;
		weapon = nullptr;
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
	void print(){
		// cout<<weapons.size();
	}
	//code to simulate gravity, adds rate of gravity to dy until you hit a platform or the floor
	void gravity(){
		//begin jump code
    	int platformHeight = platforms[0].getY();
    	setYVelocity(getYVelocity() + getGravity());

    	//falling, need to check for collisions
    	if(getYVelocity()>0){
    		for(Platform p : platforms){
    			if(getRightBound()>=p.getX()&&getX()<=p.getRightBound()&& p.getY()>=getLowerBound())
    				platformHeight = min(p.getY(),platformHeight);
    		}
    		if(player.getPosition().y<platformHeight){
	       		setOnGround(false);
    		}
    		if(getLowerBound() + getYVelocity()> platformHeight){
			    setOnGround(true);
				setYVelocity(0.0);
				player.setPosition(player.getPosition().x,platformHeight-playerHeight); //
    		}	
    	}
    	
    	//end jump code
	}
	
	void move(int windowWidth){
		//check for collisions with the side boundaries
		if(windowWidth<=getRightBound()||getX()<=0)
			setXVelocity(-getXVelocity());

		gravity();

		// findWeapon();

		// cout<<(weapon == nullptr)<<endl;
		// cout<<weapons.size()<<endl;

		// if(weapon!=nullptr){
		// 	cout<<weapon->w.getPosition().x<<" "<<weapon->w.getPosition().y<<endl;

		// 	weapon->w.move(Vector2f(getXVelocity(),getYVelocity()));
		// 	// cout<<weapon->w.getPosition().x<<" "<<weapon->w.getPosition().y<<endl;
		// 	// cout<<(*weapon).w.getPosition().y<<endl;
		// }
		// else{
		// 	findWeapon();
		// }

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
	int getXVelocity() const{
		return dx;
	}
	int getYVelocity() const{
		return dy;
	}
	void setXVelocity(const int newX){
		dx = newX;
	}
	void setYVelocity(const int newY){
		dy = newY;
	}
	bool onGround(){
		return grounded;
	}
	void setOnGround(bool g){
		grounded = g;
	}
	int getGravity()const{
		return gravityRate;
	}
	// void giveWeapon(Weapon w){
	// 	weapon = &w;
	// 	w.onGround = false;
	// }
	// void listWeapons(const vector<Weapon>& wep){
	// 	weapons = wep;
	// }
	// void findWeapon(){
	// 	for(Weapon w : weapons){
	// 		if(getX()<=w.getRightBound()||getLowerBound()<=w.getY()||getY()>=w.getLowerBound()||getRightBound()<=w.getX()&&weapon!=nullptr&&w.onGround){
	// 			giveWeapon(w);
	// 		}
	// 	}	
	// }
	// ~Player();
};