class Weapon{
public:
	bool onGround;
	RectangleShape w;
	
	Weapon(Vector2f pos){
		onGround = false;
		w.setSize(Vector2f(20,20));
		w.setPosition(pos);
		w.setFillColor(sf::Color::Blue);
	}
	void throwWeapon(float angle){

	}
	int getX(){
		return w.getPosition().x;
	}
	int getY(){
		return w.getPosition().y;
	}
	int getRightBound(){
		return getX()+w.getSize().x;
	}
	int getLowerBound(){
		return getY()+w.getSize().y;
	}
	void draw(RenderWindow& window){
		window.draw(w);
	}
};