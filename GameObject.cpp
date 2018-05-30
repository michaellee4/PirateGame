#include "GameObject.h"
class GameObject
{
public:
	GameObject(){
		
	}
	int getX() const{
		return x;
	}
	int getY() const{
		return y;
	}
	int getRightBound() const{
		return x+shape.getSize().x;
	}
	int getXVelocity() const{
		return velocityX;
	}
	int getYVelocity() const{
		return velocityY;
	}
	void setX(const int newX){
		x= newX;
	}
	void setY(const int newY){
		y= newY;
	}
	void setXVelocity(const float newVX){
		velocityX = newVX;
	}
	void setYVelocity(const float newVY){
		velocityY = newVY;
	}
	bool inAir(){
		return velocityY == 0;
	}
};