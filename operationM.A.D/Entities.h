#pragma once
#include "systems.h"
#include "components.h"
#define NUMBER_OF_OPTIONS 2
 
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
		
		 state = true;
		 if (Etype == low) {
			 if (!Etexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\lowSoldier.png")) {

				 std::cout << "hi";
			 }
		 }
		 if (Etype == high) {
			 if (!Etexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\highSoldier.png")) {

				 std::cout << "bye";
			 }
		 }
		 
		 Esprite.setTexture(Etexture);
		 Esprite.setPosition(Eposition); 

		 
		enemy.setAnimation(&Etexture, EimageCount, EswitchTime);
		
	}

	 void Edraw(sf::RenderWindow& Ewindow,float time,int i) {//draws the enemy on screen
		//std::cout << Animation::uvRect.width << std::endl;
		
		enemy.Update(i, time);
		Esprite.setTextureRect(enemy.uvRect);
		 Ewindow.draw(Esprite);
	 }

	 sf::FloatRect Ecollider() {
		bBoxEnemy= Esprite.getLocalBounds();
		bBoxEnemy.left = Esprite.getPosition().x;
		bBoxEnemy.top = Esprite.getPosition().y;
		return bBoxEnemy;
	 }

	 void Edeath(bool l_state) {
		 state = l_state;

	}
	 bool Ealive() {
		 return state;
	 }

protected:
	sf::Texture Etexture;
	Animation enemy;
	sf::Sprite Esprite;
	enum types {
	 low =1,
	 high =2,

	};
	sf::FloatRect bBoxEnemy;
	bool state;
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
		bBoxBullet = mbullet_Sprite.getLocalBounds();

		bBoxBullet.left = mbullet_Sprite.getPosition().x;//set BBox positions
		bBoxBullet.top = mbullet_Sprite.getPosition().y;


		mbullet_Velocity = l_velocity;
	}

	void Shoot(sf::Time time, sf::Vector2f l_playerPosition,bool l_state) {
		 
			//do {
		if (!((mbullet_Sprite.getPosition().x < l_playerPosition.x + 400) && (mbullet_Sprite.getPosition().x > l_playerPosition.x - 400) &&
			(mbullet_Sprite.getPosition().y < l_playerPosition.y + 300) && (mbullet_Sprite.getPosition().y > l_playerPosition.y - 300))) {
			mbullet_Sprite.setPosition(l_playerPosition);
			l_state = false;
		}
				mbullet_Sprite.move(mbullet_Velocity.x * time.asSeconds()*2000, mbullet_Velocity.y * time.asSeconds()*2000);
				bBoxBullet.left = mbullet_Sprite.getPosition().x;//set BBox positions again because SFML was pussy enough to not give a move function for Rect or maybe it just automaticall moves
				bBoxBullet.top = mbullet_Sprite.getPosition().y;
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

	sf::FloatRect BulletCollider() {
		return bBoxBullet;
	}

	void setBulletVelocity(sf::Vector2f l_velocity) {
		mbullet_Velocity = l_velocity;
	}


protected:
	sf::Texture mbullet_Texture;
	sf::Sprite  mbullet_Sprite;
	sf::Vector2f mbullet_Position;
	sf::Vector2f mbullet_Velocity;
	sf::FloatRect bBoxBullet;



 };

/*****************************************************************************MENU************************/
class menu {
public:
	menu(float width,float height);
	~menu() {
	}
	menu() {

	}

	void menu_draw(sf::RenderWindow &l_window);
	void menu_moveUp();
	void menu_moveDown();
	void set_menu(float width, float height);
private:
	sf::Font font;
	sf::Text text[NUMBER_OF_OPTIONS];
	int selected_item;
};
//
menu::menu(float width, float height) {
	if (!font.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\menufont.ttf")) {
		std::cout << "font not working" << std::endl;
	}
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Yellow);
	text[0].setString("PLAY");
	text[0].setPosition(sf::Vector2f(100 , height / (NUMBER_OF_OPTIONS + 1) * 1));
	text[1].setFont(font);
	text[1].setFillColor(sf::Color::Yellow);
	text[1].setString("OPTIONS");
	text[1].setPosition(sf::Vector2f(100 , height / (NUMBER_OF_OPTIONS + 1) * 2));
}

void menu::menu_draw(sf::RenderWindow& l_window) {
	for (int i = 0; i < NUMBER_OF_OPTIONS; i++) {
		l_window.draw(text[i]);
	}
}

void menu::set_menu(float width, float height) {
	if (!font.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\menufont.ttf")) {
		std::cout << "font not working" << std::endl;
	}
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Red);
	text[0].setString("PLAY");
	text[0].setPosition(sf::Vector2f(width /5, height / (NUMBER_OF_OPTIONS + 1) * 1));
	text[1].setFont(font);
	text[1].setFillColor(sf::Color::Yellow);
	text[1].setString("OPTIONS");
	text[1].setPosition(sf::Vector2f(width/5 , height / (NUMBER_OF_OPTIONS + 1) * 2));

	selected_item=0;
}

void menu::menu_moveUp() {
	if (selected_item - 1 >= 0)
	{
		text[selected_item].setFillColor(sf::Color::Yellow);
		selected_item--;
		text[selected_item].setFillColor(sf::Color::Red);
	}

}
void menu::menu_moveDown() {
	if (selected_item + 1 <NUMBER_OF_OPTIONS)
	{
		text[selected_item].setFillColor(sf::Color::Yellow);
		selected_item++;
		text[selected_item].setFillColor(sf::Color::Red);
	}
}