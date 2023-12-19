#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Entities.h"
 
class Game:public CGraphic,protected Entity
{
public:
	Game();
	void run();
	sf::Texture mPlayerTexture;
	sf::Texture Running;
	sf::Texture Jumping;
	
private:
	void processEvents();
	void render();
	void update();
private:
	sf::RenderWindow mWindow;
	sf:: Sprite mPlayer;
	
	sf::RectangleShape mPlatform;
	sf::Vector2f p_Position;
	 
	sf::Texture backTex;
	bool isJump;
	bool isRunning;
	bool isShooting;
	bool isMouseLeft;
	sf::View view2;
	float gravity;
	float counter;
	 
	Entity velocity;
	sf::Clock clock;
	sf::Time dt1;
	float dt2;
	Animation animationF;
	Animation animationU;
	Enemy low1;

	bullets p_bullets;
};
 

Game::Game() :mWindow{ sf::VideoMode(800,600),"M.A.D" }, mPlayer() {
	//mPlayer.setSize(sf::Vector2f(50.0f, 50.0f));
	//mPlayer.setScale(2, 2);
	//mPlayer.setOrigin(mPlayer.getSize().x / 2, mPlayer.getSize().y / 2);
	//mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\aimUp.png");
	
	p_Position.x = 400;
	p_Position.y = 300;
	mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\frontface.png");
	mPlayer.setPosition(400, 300);
	mPlayer.setTexture(mPlayerTexture);
 
	//mPlayer.setFillColor(sf::Color::Blue);
	
	//my youth do da animashion here
	Running.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\running.png");
	 animationF.setAnimation(&Running, sf::Vector2u(6, 2), 0.006f);
	Jumping.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\jumping.png");
	animationU.setAnimation(&Jumping, sf::Vector2u(4, 1),0.0009f);

	 
	 
	 
	mPlatform.setSize(sf::Vector2f(100.0f, 50.0f));
	mPlatform.setPosition(0, 500);
	

	velocity.setVelocity(5.0f, 5.0f);
	
	
	//bullet.............................................................................
	p_bullets.setBullet("D:\\operationM.A.D\\operationM.A.D\\Assets\\bullet.png", mPlayer.getPosition(), sf::Vector2f(10, 0));



	isJump = false;
	isRunning = false;
	isShooting = false;
	isMouseLeft = false;
	gravity = 75.0f;
	counter = 0.0f;
	backTex.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\backtex.png");
	//Back.scale(3, 3);
	
	 
}


//The game loop begins.......................................................
void Game::run() {
 low1.setEnemy( 1, sf::Vector2u(6,1), 0.006f,sf::Vector2f(-50, 300));
	view2.setCenter(sf::Vector2f(400.f, 300.f));
	view2.setSize(sf::Vector2f(800.f, 600.f));
	clock;//clcok starts***************************************************************CLOCK*********************************************
	while (mWindow.isOpen()) {
		
		mWindow.setView(view2);
		dt1 = clock.restart();
		dt2 = dt1.asSeconds();
		//createbackground(background,sf::IntRect(0,0,2048,256));
		processEvents();
		update();
		render();
	}
}

void Game::processEvents() {
	sf::Event event;
	sf::Vector2f coordi(0.f, 0.f);
	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			mWindow.close();
		}
		else {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\aimUp.png");
				mPlayer.setTexture(mPlayerTexture);
				sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
				mPlayer.setTextureRect(textureRect);

				}
			else {
				//mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\frontface.png");
			}
			
			 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				//mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\backface.png");
				//mPlayer.setTexture(mPlayerTexture);

				mPlayerTexture = Running;
				animationF.Update(1, dt2);

				mPlayer.setTextureRect(animationF.uvRect);
				//sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
				//mPlayer.setTextureRect(textureRect);

				coordi.x -= velocity.getVelocity().x;
				view2.move(coordi);
				mPlayer.move(coordi);
			
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				//mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\frontface.png");
				//mPlayer.setTexture(mPlayerTexture);
				mPlayerTexture = Running;
				animationF.Update(0, dt2);
				 
				mPlayer.setTextureRect(animationF.uvRect);

				
				//sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
				//mPlayer.setTextureRect(textureRect);
				
				coordi.x += velocity.getVelocity().x;
				view2.move(coordi);
				//mWindow.setView(view2);
				mPlayer.move(coordi);

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\layingDown.png");
				mPlayer.setTexture(mPlayerTexture);
				sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
				mPlayer.setTextureRect(textureRect);
				 
				 
			}

          //Jumping and shooting controls brother

			if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {//jump mechanics................................
				isJump = true;
				
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {//Shoot mechanics
				isShooting = true;
				//isMouseLeft = true;
			}
			else {
				isShooting = false;
				p_bullets.replaceBullet(mPlayer.getPosition());
			}

			//if(sf::Event::MouseButtonReleased)
			 
			 

			 
			
			//Collision mechanics

		}
	}
		//apply gravity
	//coordi.y += gravity*dt1.asSeconds();
	//mPlayer.move(coordi);

}

//Double buffer here and draw all that.........................
void Game::render()
{
	mWindow.clear(sf::Color::Black);
	if (isRunning == true) {

	}
	p_bullets.drawBullet(mWindow);
	low1.Edraw(mWindow, dt2);
	mWindow.draw(mPlayer);
	mWindow.draw(mPlatform);
	mWindow.display();
}



//jumping is almost done
void Game::update() {
	if (isJump) {
		mPlayer.move(0, -gravity*2 * dt1.asSeconds());
		counter += gravity * 2 * dt1.asSeconds();
		mPlayerTexture = Jumping;
		animationU.Update(0, dt2);
		mPlayer.setTextureRect(animationU.uvRect);
		//std::cout << counter << std::endl;
		if (counter > 300) {
			isJump = false;
			counter = 0.0f;
		}
	 }
	if (isShooting) {
		p_bullets.Shoot(dt1, mPlayer.getPosition(),isShooting);

	}
	 
	
}
	
