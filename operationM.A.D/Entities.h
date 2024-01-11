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
	//	std::cout << " " << std::endl;
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
			bBoxBullet.left = mbullet_Sprite.getPosition().x; 
			l_state = false;
		}
				mbullet_Sprite.move(mbullet_Velocity.x * time.asSeconds()*l_multiplier, mbullet_Velocity.y * time.asSeconds()*l_multiplier);
				bBoxBullet.left = mbullet_Sprite.getPosition().x; 
				bBoxBullet.top = mbullet_Sprite.getPosition().y;
			 
	}

	void drawBullet(sf::RenderWindow& l_window) {
		l_window.draw(mbullet_Sprite);
	}

	void replaceBullet(sf::Vector2f l_position) {
		mbullet_Sprite.setPosition(l_position);
		bBoxBullet.left = mbullet_Sprite.getPosition().x;
		bBoxBullet.top = mbullet_Sprite.getPosition().y;
	}

	sf::FloatRect BulletCollider() {
		return bBoxBullet;
	}

	void setBulletVelocity(sf::Vector2f l_velocity) {
		mbullet_Velocity = l_velocity;
	}
	void setBullettexture(std::string l_string) {
		mbullet_Texture.loadFromFile(l_string);
		mbullet_Sprite.setTexture(mbullet_Texture);
		bBoxBullet = mbullet_Sprite.getLocalBounds();
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
	if (!font.loadFromFile("..\\operationM.A.D\\Assets\\menufont.ttf")) {
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
	if (!font.loadFromFile("..\\operationM.A.D\\Assets\\menufont.ttf")) {
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
			if (!Etexture.loadFromFile("..\\operationM.A.D\\Assets\\lowSoldier.png")) {

				std::cout << "hi";
			}
		}
		if (Etype == 2) {
			if (!Etexture.loadFromFile("..\\operationM.A.D\\Assets\\highSoldier.png")) {

				std::cout << "bye";
			}
		}

		 Esprite.setTexture(Etexture);
		 Esprite.setPosition(Eposition); 
		 Ebullet.setBullet("..\\operationM.A.D\\Assets\\Ebullet.png",Esprite.getPosition(),sf::Vector2f(0,0) );
		 bBoxEnemy = Esprite.getLocalBounds();
		 bBoxEnemy.width = 39.0f;
		 bBoxEnemy.height = 41.0f;
		 bBoxEnemy.left = Esprite.getPosition().x;
		 bBoxEnemy.top = Esprite.getPosition().y;
		enemy.setAnimation(&Etexture, EimageCount, EswitchTime);


	}

	void Edraw(sf::RenderWindow& Ewindow, float time, int i) {//draws the enemy on screen
		//std::cout << Animation::uvRect.width << std::endl;

		enemy.Update(i, time);
		Esprite.setTextureRect(enemy.uvRect);
		Ewindow.draw(Esprite);
	}

	sf::FloatRect Ecollider() {
	 
		//bBoxEnemy.left = Esprite.getPosition().x;
		//bBoxEnemy.top = Esprite.getPosition().y;
		return bBoxEnemy;
	}
	sf::FloatRect Ebulletcollider() {
		return Ebullet.BulletCollider();
	}

	void Edeath(bool l_state) {
		state = l_state;
		//Esprite.getPosition().x - 10000.0f;
		//Esprite.getPosition().y + 10000.0f;
	}
	bool Ealive() {
		return state;
	}
	void E_rand_move_Box(bool l_state) {

		state = l_state;
		if (state) {
			bBoxEnemy.left = Esprite.getPosition().x-10000.0f;
			bBoxEnemy.top = Esprite.getPosition().y+ 10000.0f;
		}
	}
	void E_rand_move(sf::Vector2f l_position,float time){//defines the random movement of sf::Vector2f l_position
		Esprite.move(0.09, 0);
		 
		bBoxEnemy.left = Esprite.getPosition().x;
		bBoxEnemy.top = Esprite.getPosition().y;
		total_time += time;
		//std::cout << total_time << std::endl;
		
			if (Esprite.getPosition().x > l_position.x + 400.0f) {
				if (total_time > 6.0) {
					Esprite.setPosition(l_position.x - 400.0f, l_position.y);
					 
					bBoxEnemy.left = Esprite.getPosition().x;
					bBoxEnemy.top = Esprite.getPosition().y;
					state = false;
					total_time = 0.0f;
				}
			}
			if (state&&( Esprite.getPosition().x<l_position.x)) {
				Esprite.setPosition(l_position.x - 600.0f, l_position.y);

				bBoxEnemy.left = Esprite.getPosition().x;
				bBoxEnemy.top = Esprite.getPosition().y;
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
				Ebullet.setBulletVelocity(sf::Vector2f(-3.16, 3.16));
				if ((Esprite.getPosition().x - l_playerPosition.x < 200.0f) || (-Esprite.getPosition().x + l_playerPosition.x < 200.0f)) 
				Ebullet.Shoot(l_time, Esprite.getPosition(), true, 100);
			}
			if (EnemyAngle > 157.5f && EnemyAngle < 180.0f) {//South
				enemy.Update(2, time);
				Ebullet.setBulletVelocity(sf::Vector2f(0, 10));
				if ((Esprite.getPosition().x - l_playerPosition.x < 200.0f) || (-Esprite.getPosition().x + l_playerPosition.x < 200.0f))
				Ebullet.Shoot(l_time, Esprite.getPosition(), true, 100);

			}
			if (EnemyAngle > -157.5f && EnemyAngle < -112.5f) {//South east
				enemy.Update(4, time);
				Ebullet.setBulletVelocity(sf::Vector2f(3.16, 3.16));
				if ((Esprite.getPosition().x - l_playerPosition.x < 200.0f) || (-Esprite.getPosition().x + l_playerPosition.x < 200.0f))
				Ebullet.Shoot(l_time, Esprite.getPosition(), true, 10);

			}
			if (EnemyAngle > -180.0f && EnemyAngle < -157.5f) {//South
				enemy.Update(2, time);
				Ebullet.setBulletVelocity(sf::Vector2f(0, 10));
				if ((Esprite.getPosition().x - l_playerPosition.x < 200.0f) || (-Esprite.getPosition().x + l_playerPosition.x < 200.0f))
				Ebullet.Shoot(l_time, Esprite.getPosition(), true, 10);
			}
			if (EnemyAngle > 67.5f && EnemyAngle < 112.5f) {//West
				enemy.Update(1, time);
				Ebullet.setBulletVelocity(sf::Vector2f(-10, 0));
				if ((Esprite.getPosition().x - l_playerPosition.x < 200.0f) || (-Esprite.getPosition().x + l_playerPosition.x < 200.0f))
				Ebullet.Shoot(l_time, Esprite.getPosition(), true, 10);

			}
			if (EnemyAngle > 22.5 && EnemyAngle < 67.5f) {//North West
				enemy.Update(7, time);
				Ebullet.setBulletVelocity(sf::Vector2f(-3.16, -3.16));
				if ((Esprite.getPosition().x - l_playerPosition.x < 200.0f) || (-Esprite.getPosition().x + l_playerPosition.x < 200.0f))
				Ebullet.Shoot(l_time, Esprite.getPosition(), true, 10);

			}
			if (EnemyAngle > -22.5 && EnemyAngle < 22.5f) {//North
				enemy.Update(3, time);
				Ebullet.setBulletVelocity(sf::Vector2f(0, -10));
				if ((Esprite.getPosition().x - l_playerPosition.x < 200.0f) || (-Esprite.getPosition().x + l_playerPosition.x < 200.0f))
				Ebullet.Shoot(l_time, Esprite.getPosition(), true, 10);

			}
			if (EnemyAngle > -67.5f && EnemyAngle < -22.5f) {//North East
				enemy.Update(6, time);
				Ebullet.setBulletVelocity(sf::Vector2f(3.16, -3.16));
				if ((Esprite.getPosition().x - l_playerPosition.x < 200.0f) || (-Esprite.getPosition().x + l_playerPosition.x < 200.0f))
				Ebullet.Shoot(l_time, Esprite.getPosition(), true, 10);

			}
			if (EnemyAngle > -112.5f && EnemyAngle < -67.5f) {//East
				enemy.Update(0, time);
				Ebullet.setBulletVelocity(sf::Vector2f(10, 0));
				if ((Esprite.getPosition().x - l_playerPosition.x < 200.0f) || (-Esprite.getPosition().x + l_playerPosition.x < 200.0f))
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
	Boss() {

	}
	~Boss() {
	};
	void setBoss();
	bool Boss_cinematic_1(sf::Vector2f l_position);
	void Boss_draw(sf::RenderWindow& l_window) {
		
		l_window.draw(boss_Body_Sprite);
		
		boss_bullet.drawBullet(l_window);
		l_window.draw(boss_Mouth_Sprite );
		l_window.draw(boss_Head_Sprite );
		
	}
	
	 
	 void Boss_mechanics(sf::Vector2f l_position,float time,sf::Time l_time);
private:
	/*******BODY********/
	sf::Sprite boss_Body_Sprite;
	sf::Texture boss_Body_Texture;

	/*********HEAD***********/
	sf::Sprite boss_Head_Sprite;
	sf::FloatRect boss_Head_Box;
	sf::Texture boss_Head_Texture;

	sf::Sprite boss_Mouth_Sprite;
	sf::Texture boss_Mouth_Texture;
	sf::FloatRect boss_Mouth_Box;
	sf::Transform transform;
	float boss_health;
	float delta_angle = 0.0;
	float delta_time=0.0;
	float moveY=5.0;

	bool boss_step_1=false;
	bool boss_step_2=true;

	bullets boss_bullet;


};

void Boss::setBoss() {
	boss_Body_Texture.loadFromFile("..\\operationM.A.D\\Assets\\bossBody.png");
	boss_Body_Sprite.setTexture(boss_Body_Texture);

	boss_Head_Texture.loadFromFile("..\\operationM.A.D\\Assets\\bossHead.png");
	boss_Head_Sprite.setTexture(boss_Head_Texture);

	boss_Mouth_Texture.loadFromFile("..\\operationM.A.D\\Assets\\bossMouth.png");
	boss_Mouth_Sprite.setTexture(boss_Mouth_Texture);

	boss_Body_Sprite.setPosition(sf::Vector2f(4015.0, 1250.0));
	
	boss_Head_Sprite.setOrigin(sf::Vector2f(99.5, 100.0));
	boss_Head_Sprite.setPosition(sf::Vector2f(4128.0, 1260.0));
	boss_Mouth_Sprite.setOrigin(sf::Vector2f(30, 10.0));
	boss_Mouth_Sprite.setPosition(sf::Vector2f(4128.0, 1270.0));

	boss_bullet.setBullet("..\\operationM.A.D\\Assets\\bossBullet.png", sf::Vector2f(4110.0, 100.0), sf::Vector2f(0,0));

	 
}
bool Boss::Boss_cinematic_1(sf::Vector2f l_position) {
	if (l_position.x > 3000.0) {
		boss_step_1 = true;
		//std::cout << l_position.x << std::endl;

		boss_Head_Sprite.move(0, -moveY);
		boss_Body_Sprite.move(0, -moveY);
		boss_Mouth_Sprite.move(0, -moveY);
		if (boss_Head_Sprite.getPosition().y < 110.0) {
			moveY = 0.0f;
		}
		return true;
	
	}
	else
		return false;
	boss_step_1 = false;
}

void Boss::Boss_mechanics(sf::Vector2f l_position,float time,sf::Time l_time) {
	if (boss_step_1 ) {
		delta_time += time;
		 
		if (delta_time > 2.0) {
		 
			if (delta_time >= 4.0) {
			 
				delta_angle = 0.009f;
					 
			 
					 
				if ((boss_Head_Sprite.getRotation() > 25.0f)&&(boss_Head_Sprite.getRotation()<50.0f)){
					boss_step_2 = false;
					
				}
				if (boss_step_2) {
					boss_Head_Sprite.rotate(delta_angle);
					boss_Mouth_Sprite.rotate(delta_angle);


					if(boss_Head_Sprite.getRotation()<25.0f&& boss_Head_Sprite.getRotation()>15.0f)
					boss_bullet.setBulletVelocity(sf::Vector2f(-10, 10));
					if (boss_Head_Sprite.getRotation() < 15.0f && boss_Head_Sprite.getRotation() > 5.0f)
						boss_bullet.setBulletVelocity(sf::Vector2f(-5.0f, 13.0f));
					if (boss_Head_Sprite.getRotation() < 5.0f && boss_Head_Sprite.getRotation() > 0.0f)
						boss_bullet.setBulletVelocity(sf::Vector2f(0.0f, 14.5f));
					boss_bullet.Shoot(l_time, sf::Vector2f(4110.0, 100.0), true, 100);
				}
				if (!boss_step_2) {
					boss_Head_Sprite.rotate(-delta_angle);
					boss_Mouth_Sprite.rotate(-delta_angle);

					if(boss_Head_Sprite.getRotation()-360.0f>-15.0f&& boss_Head_Sprite.getRotation()-360<-5.0f)
					    boss_bullet.setBulletVelocity(sf::Vector2f(10.0f , 10.0f));

					if (boss_Head_Sprite.getRotation() - 360.0f > -25.0f && boss_Head_Sprite.getRotation()-360.0f < -15.0f)
						boss_bullet.setBulletVelocity(sf::Vector2f(+5.0f,13.0f));
					 
					if (boss_Head_Sprite.getRotation() - 360.0f > -5.0f && boss_Head_Sprite.getRotation() - 360.0f < 0.0f)
						boss_bullet.setBulletVelocity(sf::Vector2f(+5.0f, 13.0f));
					boss_bullet.Shoot(l_time, sf::Vector2f(4110.0, 100.0), true, 100);

				}
				if (boss_Head_Sprite.getRotation() - 360.0f < -25.0f && (!(boss_Head_Sprite.getRotation()<300.0f))) {
					boss_step_2 = true;
				}
				
			 
					 
			}
		}
		

	}
	 
}

class powerUp {
public:
	void set_powerUp() {
		type_1 = false;
		power_m = true;
		power_texture.loadFromFile("..\\operationM.A.D\\Assets\\powerup.png");
		power_sprite.setTexture(power_texture);
		power_sprite.setPosition(sf::Vector2f(2000.0f, 100.0f));
	}
	void power_M(sf::Vector2f l_position,float l_time) {
		current_time += l_time;
		if ( current_time>6.0) {
			type_1 = true;
			current_time = -10000000000;//doing this such that the timer never recovers
		}
		if (l_position.x > 2100.0) {
			type_1 = false;
		}
	}
	void power_move(float l_time) {//it isnt even close
		if ( type_1) {
			bBoxPower = power_sprite.getLocalBounds();
			
			power_sprite.move(-0.05f,  ycoordi);
			if (power_sprite.getPosition().y >160.1f) {
				 ycoordi += -0.01f;
			}
			if (power_sprite.getPosition().y < 99.0f) {
				ycoordi = 0.05f;
			}

			bBoxPower.left = power_sprite.getPosition().x;
			bBoxPower.top = power_sprite.getPosition().y;
		}
	}
	void power_draw(sf::RenderWindow& l_window) {
		if (power_m) {
			l_window.draw(power_sprite);
		}

	}
	sf::FloatRect power_collider( ) {
		return bBoxPower;
	}
	void power_final(std::vector<sf::FloatRect> &l_vector) {
		if (power_m) {
			type_1 = false;
			power_texture.loadFromFile("..\\operationM.A.D\\Assets\\powerL.png");
			power_sprite.setTexture(power_texture);
			bBoxPower = power_sprite.getLocalBounds();

			do {

				power_sprite.move(0, 30);
				bBoxPower.left = power_sprite.getPosition().x;
				bBoxPower.top = power_sprite.getPosition().y;
				std::cout << power_type(l_vector) << std::endl;
			} while (!power_type(l_vector));
		}
		
	}

	bool power_type(std::vector<sf::FloatRect>& l_vector) {
		for (int i = 0; i < 111; i++) {
			if (l_vector[i].intersects(bBoxPower)) {
				return true;
			}
			else
				false;
			}
	}

	void power_state(bool state) {
		power_m = state;
	}

	void OutOfTheWay() {//my naming consistency is really something
		bBoxPower.left = 4000.0f;
		bBoxPower.top = 1000.0f;
	}
private:
	sf::Sprite power_sprite;
	sf::Texture power_texture;
	sf::FloatRect bBoxPower;
	bool type_1;
	bool power_m;
	float ycoordi = 0.05f;
	float current_time=0.0;
};