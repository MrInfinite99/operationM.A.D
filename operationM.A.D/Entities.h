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

	void Shoot(sf::Time time, sf::Vector2f l_playerPosition,bool l_state,int l_multiplier) {
		 
			//do {
		if (!((mbullet_Sprite.getPosition().x < l_playerPosition.x + 400) && (mbullet_Sprite.getPosition().x > l_playerPosition.x - 400) &&
			(mbullet_Sprite.getPosition().y < l_playerPosition.y + 300) && (mbullet_Sprite.getPosition().y > l_playerPosition.y - 300))) {
			mbullet_Sprite.setPosition(l_playerPosition);
			l_state = false;
		}
				mbullet_Sprite.move(mbullet_Velocity.x * time.asSeconds()*l_multiplier, mbullet_Velocity.y * time.asSeconds()*l_multiplier);
				bBoxBullet.left = mbullet_Sprite.getPosition().x;//set BBox positions again because SFML was pussy enough to not give a move function for Rect or maybe it just automaticall moves
				bBoxBullet.top = mbullet_Sprite.getPosition().y;
			 
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
		selected_item = 0;
	}

	void menu_draw(sf::RenderWindow &l_window);
	void menu_moveUp();
	void menu_moveDown();
	void set_menu(float width, float height, std::string string1, std::string string2,int w);
private:
	sf::Font font;
	sf::Text text[NUMBER_OF_OPTIONS];
	int selected_item;
};
//
menu::menu(float width, float height) {
	selected_item = 0;
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

void menu::set_menu(float width, float height,std::string string1,std::string string2,int w) {
	if (!font.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\menufont.ttf")) {
		std::cout << "font not working" << std::endl;
	}
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Red);
	text[0].setString(string1);
	text[0].setPosition(sf::Vector2f(width /w, height / (NUMBER_OF_OPTIONS + 1) * 1));
	text[1].setFont(font);
	text[1].setFillColor(sf::Color::Yellow);
	text[1].setString(string2);
	text[1].setPosition(sf::Vector2f(width/w , height / (NUMBER_OF_OPTIONS + 1) * 2));

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

class Enemy :public CGraphic, public Animation ,public bullets{// ,public bullets
public:
	Enemy() {
		state = false;
	};
	void setEnemy(int Etype, sf::Vector2u EimageCount, float EswitchTime, sf::Vector2f Eposition) {
		total_time = 0.0;
		state = false;
		if (Etype == 1) {
			if (!Etexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\lowSoldier.png")) {

				std::cout << "hi";
			}
		}
		if (Etype == 2) {
			if (!Etexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\highSoldier.png")) {

				std::cout << "bye";
			}
		}

		 Esprite.setTexture(Etexture);
		 Esprite.setPosition(Eposition); 
		 Ebullet.setBullet("D:\\operationM.A.D\\operationM.A.D\\Assets\\Ebullet.png",Esprite.getPosition(),sf::Vector2f(0,0) );

		enemy.setAnimation(&Etexture, EimageCount, EswitchTime);


	}

	void Edraw(sf::RenderWindow& Ewindow, float time, int i) {//draws the enemy on screen
		//std::cout << Animation::uvRect.width << std::endl;

		enemy.Update(i, time);
		Esprite.setTextureRect(enemy.uvRect);
		Ewindow.draw(Esprite);
	}

	sf::FloatRect Ecollider() {
		bBoxEnemy = Esprite.getLocalBounds();
		bBoxEnemy.left = Esprite.getPosition().x;
		bBoxEnemy.top = Esprite.getPosition().y;
		return bBoxEnemy;
	}
	sf::FloatRect Ebulletcollider() {
		return Ebullet.BulletCollider();
	}

	void Edeath(bool l_state) {
		state = l_state;

	}
	bool Ealive() {
		return state;
	}
	void E_rand_move_Box(bool l_state) {//defines the random movement of sf::Vector2f l_position

		state = l_state;
		if (state == true) {
			bBoxEnemy.left = Esprite.getPosition().x + 10000.0f;
			bBoxEnemy.top = Esprite.getPosition().y + 1000.0f;
		}
	}
	void E_rand_move(sf::Vector2f l_position,float time){
		Esprite.move(0.1, 0);
		total_time += time;
		//std::cout << total_time << std::endl;
		if(Esprite.getPosition().x>l_position.x+400)
			if (total_time > 6.0) {
				Esprite.setPosition(l_position.x - 400,Esprite.getPosition().y);
				state = false;
				total_time = 0.0f;
			}
	}

	void E_track_player(sf::RenderWindow& Ewindow, sf::Vector2f l_playerPosition, float time,sf::Time l_time) {
		float EnemyAngle = (180.0f / 3.1415f) * atan2f(Esprite.getPosition().x - l_playerPosition.x, Esprite.getPosition().y - l_playerPosition.y);
		Ebullet.drawBullet(Ewindow);
		Ewindow.draw(Esprite);
		if (EnemyAngle > 112.5f && EnemyAngle < 157.5f) {//South west
			enemy.Update(5, time);
			Ebullet.setBulletVelocity(sf::Vector2f(-3.16,3.16));
			Ebullet.Shoot(l_time, Esprite.getPosition(), true,100);
		}
		if (EnemyAngle > 157.5f && EnemyAngle < 180.0f) {//South
			enemy.Update(2, time);
			Ebullet.setBulletVelocity(sf::Vector2f(0, 10));
			Ebullet.Shoot(l_time, Esprite.getPosition(), true,100);

		}
		if (EnemyAngle > -157.5f && EnemyAngle < -112.5f) {//South east
			enemy.Update(4, time);
			Ebullet.setBulletVelocity(sf::Vector2f(3.16, 3.16));
			Ebullet.Shoot(l_time, Esprite.getPosition(), true, 10);

		}
		if (EnemyAngle > -180.0f && EnemyAngle < -157.5f) {//South
			enemy.Update(2, time);
			Ebullet.setBulletVelocity(sf::Vector2f(0, 10));
			Ebullet.Shoot(l_time, Esprite.getPosition(), true, 10);
		}
		if (EnemyAngle > 67.5f && EnemyAngle < 112.5f) {//West
			enemy.Update(1, time);
			Ebullet.setBulletVelocity(sf::Vector2f(-10, 0));
			Ebullet.Shoot(l_time, Esprite.getPosition(), true, 10);

		}
		if (EnemyAngle > 22.5 && EnemyAngle < 67.5f) {//North West
			enemy.Update(7, time);
			Ebullet.setBulletVelocity(sf::Vector2f(-3.16, -3.16));
			Ebullet.Shoot(l_time, Esprite.getPosition(), true, 10);

		}
		if (EnemyAngle > -22.5 && EnemyAngle < 22.5f) {//North
			enemy.Update(3, time);
			Ebullet.setBulletVelocity(sf::Vector2f(0, -10));
			Ebullet.Shoot(l_time, Esprite.getPosition(), true,10);

		}
		if (EnemyAngle > -67.5f && EnemyAngle < -22.5f) {//North East
			enemy.Update(6, time);
			Ebullet.setBulletVelocity(sf::Vector2f(3.16, -3.16));
			Ebullet.Shoot(l_time, Esprite.getPosition(), true, 10);

		}
		if (EnemyAngle > -112.5f && EnemyAngle < -67.5f) {//East
			enemy.Update(0, time);
			Ebullet.setBulletVelocity(sf::Vector2f(10,0));
			Ebullet.Shoot(l_time, Esprite.getPosition(), true, 10);

		}
		Esprite.setTextureRect(enemy.uvRect);
		Ewindow.draw(Esprite);
	}
protected:
	sf::Texture Etexture;
	Animation enemy;
	sf::Sprite Esprite; 
	bullets Ebullet;
	sf::FloatRect bBoxEnemy;
	float total_time;
	bool state;
};

class Boss :public Enemy {
public:
	Boss();
	~Boss();
	void setBoss(sf::Vector2u EimageCount, float EswitchTime, sf::Vector2f Eposition) {
		boss_texture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\tankBoss.png");
		boss_sprite.setTexture(boss_texture);
		boss_animation.setAnimation(&boss_texture,EimageCount,EswitchTime);
		
	}
	 void spawn_boss(sf::Vector2f l_position,sf::RenderWindow l_window) {
		if (l_position.x > 3900.0) {
			l_window.draw(boss_sprite);
		}
	 }
	 void boss_mechanics(sf::Vector2f l_position);
private:
	sf::Sprite boss_sprite;
	sf::Texture boss_texture;
	Animation boss_animation;
	sf::FloatRect bBoxBoss;
	float boss_health;
};