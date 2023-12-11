#pragma once
#include "components.h"


/*An entity denotes a game element in the world. In our game, possible entities are
friendly and enemy airplanes, bullets, missiles, or pickups that increase the player's
strength. Entities interact with each other: enemy airplanes can fire missiles, the
player's airplane may evade them, and the missiles may explode if they hit the
player's plane, dealing damage to it. The player's aircraft can touch a pickup to
collect it, as a result of which it gets a new ability. The possibilities are nearly
unlimited, and they may occur between almost any pair of entity types.*/
class Entity {//define entities here...............
protected:
	sf::Vector2f mVelocity;
public:
	void setVelocity(float vx, float vy) {
		mVelocity.x = vx;
		mVelocity.y = vy;
	}
		sf::Vector2f getVelocity() {
			return mVelocity;
		}
		Entity() {
			mVelocity.x = 5.f;
			mVelocity.y = 5.f;
	 }
	

};



class Enemy:public Entity {
public:
	enum Type {
		lowSoldier,
	    midSoldier,
	};
	explicit Enemy(Type type) {
		mType = type;
	}

private:
	Type mType;

};

//CGraphic::set_texture("D:\operationM.A.D\operationM.A.D\Assets\bullet.png")

 
/*class Entity :public Cname {
private:
	std::string name;
public:
	Entity() {
	
	}
		

};*/
