#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"systems.h"
class Game:public CGraphic,protected Entity
{
public:
	Game();
	void run();
private:
	void processEvents();
	void render();
	void update();
private:
	sf::RenderWindow mWindow;
	sf::RectangleShape mPlayer;
	sf::RectangleShape mPlatform;
	sf::Vector2f oldPosition;
	bool isJump;
	sf::View view2;
	float gravity;
	CGraphic bullet;
	CGraphic Back;
	Entity velocity;
};
 

Game::Game() :mWindow{ sf::VideoMode(800,600),"M.A.D" }, mPlayer() {
	mPlayer.setSize(sf::Vector2f(10.0f, 50.0f));
	mPlayer.setOrigin(mPlayer.getSize().x / 2, mPlayer.getSize().y / 2);
	mPlayer.setPosition(400, 300);
	mPlayer.setFillColor(sf::Color::Red);
	 



	mPlatform.setSize(sf::Vector2f(100.0f, 50.0f));
	mPlatform.setPosition(0, 500);
	

	velocity.setVelocity(5.0f, 5.0f);
	
	
	//bullet.............................................................................
	//bullet.set_texture("D:\\operationM.A.D\\operationM.A.D\\Assets\\bullet.png");
	//sf::Sprite& bulletSprite = bullet.get_sprite();
	//bullet.set_position(mPlayer.getPosition().x,mPlayer.getPosition().y);
	//bullet.............................................................................



	isJump = false;
	gravity = 5.0f;
	Back.set_texture("D:\\operationM.A.D\\operationM.A.D\\Assets\\back.png");
	Back.scale(3, 3);
	 
	 
}


//The game loop begins.......................................................
void Game::run() {
	view2.setCenter(sf::Vector2f(400.f, 300.f));
	view2.setSize(sf::Vector2f(800.f, 600.f));
	
	while (mWindow.isOpen()) {
		
		mWindow.setView(view2);
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


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {//jump mechanics................................
				coordi.y += -150;//impulse provided jump works

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				coordi.x -= velocity.getVelocity().x;
				view2.move(-5.f, 0.f);
				mPlayer.move(coordi);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				coordi.x += velocity.getVelocity().x;
				view2.move(5.0f, 0.f);
				//mWindow.setView(view2);
				mPlayer.move(coordi);

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				coordi.y += velocity.getVelocity().y;
				mPlayer.move(coordi);
			}

			//shooting mechanics goes here
			//Collision mechanics

		}
	}
		//apply gravity
	coordi.y += gravity/150;
	mPlayer.move(coordi);

}

//Double buffer here and draw all that.........................
void Game::render()
{
	mWindow.clear(sf::Color::Black);
	mWindow.draw(mPlatform);
	
	mWindow.draw(Back.get_sprite());
	mWindow.draw(mPlayer);
	mWindow.display();
}

void Game::update() {
	sf::Clock clock;
	if (isJump) {
		clock.restart();
		sf::Time time = clock.getElapsedTime();


		 
	}
	 
	
}
	
