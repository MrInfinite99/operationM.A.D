#pragma once
#include "systems.h"
#include "components.h"

 
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



class Enemy:public CGraphic,public Animation {
public:
	
	 void setEnemy(int Etype, sf::Vector2u EimageCount, float EswitchTime,sf::Vector2f Eposition) {
		
		
		 if (Etype == low) {
			 if (!Etexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\lowSoldier.png")) {

				 std::cout << "hi";
			 }
		 }
		 
		 Esprite.setTexture(Etexture);
		 Esprite.setPosition(Eposition);//for the low Soldier set the position off screen because they come running and then go away

		 
		enemy.setAnimation(&Etexture, EimageCount, EswitchTime);
		
	}

	 void Edraw(sf::RenderWindow& Ewindow,float time) {//draws the enemy on screen
		//std::cout << Animation::uvRect.width << std::endl;
		
		enemy.Update(0, time);
		Esprite.setTextureRect(enemy.uvRect);
		 Ewindow.draw(Esprite);
	 }

protected:
	sf::Texture Etexture;
	Animation enemy;
	sf::Sprite Esprite;
	enum types {
	 low =1,
	 mid =2,

	};

};
 
class bullets {
public:
	bullets() {
		std::cout << " " << std::endl;
	};
	bullets(std::string string,sf::Vector2f &l_playerPosition,sf::Vector2f l_velocity) {
		mbullet_Texture.loadFromFile(string);
		mbullet_Sprite.setTexture(mbullet_Texture);
		mbullet_Position = l_playerPosition;
		mbullet_Sprite.setPosition(mbullet_Position);
		
		mbullet_Velocity = l_velocity;
	}
	void setBullet(std::string string, sf::Vector2f l_playerPosition, sf::Vector2f l_velocity) {
		mbullet_Texture.loadFromFile(string);
		mbullet_Sprite.setTexture(mbullet_Texture);
		mbullet_Position = l_playerPosition;
		mbullet_Sprite.setPosition(mbullet_Position);

		mbullet_Velocity = l_velocity;
	}

	void Shoot(sf::Time time, sf::Vector2f l_playerPosition,bool l_state) {
		 
			//do {
		if (!((mbullet_Sprite.getPosition().x < l_playerPosition.x + 400) && (mbullet_Sprite.getPosition().x > l_playerPosition.x - 400) &&
			(mbullet_Sprite.getPosition().y < l_playerPosition.y + 300) && (mbullet_Sprite.getPosition().y > l_playerPosition.y - 300))) {
			mbullet_Sprite.setPosition(l_playerPosition);
			l_state = false;
		}
				mbullet_Sprite.move(mbullet_Velocity.x * time.asSeconds()*2000, mbullet_Velocity.y * time.asSeconds());
				//mbullet_Position.y += mbullet_Velocity.y * time.asSeconds();
				
			 //while ((mbullet_Sprite.getPosition().x < l_playerPosition.x + 400) && (mbullet_Sprite.getPosition().x > l_playerPosition.x - 400) && (mbullet_Sprite.getPosition().y < l_playerPosition.y + 300) && (mbullet_Sprite.getPosition().y > l_playerPosition.y - 300));
			/*
				std::cout << mbullet_Sprite.getPosition().x << std::endl;
			}*/
			//std::cout << mbullet_Sprite.getPosition().x << std::endl;
	}

	void drawBullet(sf::RenderWindow& l_window) {
		l_window.draw(mbullet_Sprite);
	}

	void replaceBullet(sf::Vector2f l_position) {
		mbullet_Sprite.setPosition(l_position);
	}


protected:
	sf::Texture mbullet_Texture;
	sf::Sprite  mbullet_Sprite;
	sf::Vector2f mbullet_Position;
	sf::Vector2f mbullet_Velocity;



 };
 