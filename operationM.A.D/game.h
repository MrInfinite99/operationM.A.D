#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Entities.h"
#include <vector>
#include<set>
#include<math.h>
 
class Game:public CGraphic,protected Entity
{
public:
	Game();
	void run();
	std::vector<Enemy> high;
	sf::Texture mPlayerTexture;
	sf::Texture Running;
	sf::Texture Jumping;
	sf::Texture mopenMenuTexture;
	sf::Texture level1;
	sf::Texture level1grass;
	sf::Texture level1city;
	sf::Texture texCutscene;
	sf::Texture RunningD;
private:
	void processEvents();
	void render();
	void update();
private:
	sf::RenderWindow mWindow;
	sf:: Sprite mPlayer;
	sf::Sprite mopenMenu;
	sf::Sprite Cutscene;//just how many sprites maybe a vector??
	menu menu;

	sf::RectangleShape mPlatform;//to be removed 
	sf::Vector2f p_Position;
	sf::Vector2f old_Position;
	
	sf::View view2;//essentially the camera


	bool isJump;
	bool isRunning;
	bool isFrontFace;/*********/
	bool isBackFace;/**********/
	bool isShooting;
	bool isMouseLeft;

	bool isStarted;
	bool isPaused;
	bool mainMenu;


    bool Edeath;/*temporary fix fpr enemy death*/
	
	float gravity;
	float counter;
	float dt2;//time used for multiple thing like cutscenes and movement
	float Cutscene_dt = 0.0;//just for cutscenes
	float mouseAngle;
	Entity velocity;
	sf::Clock clock;
	sf::Time dt1;

	/*ANIMATIONS*/
	Animation animationF;
	Animation animationU;
	Animation animationD;
	
	
	
	Enemy low1;
	
	
	Enemy high1;
	Enemy high2;
	Enemy high3;
	Enemy high4;
	Enemy high5;
	Enemy high6;



	bullets p_bullets;
	sf::Event event;

	/*Bounding box*/
	
	sf::VertexArray background;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	sf::VertexArray grass;
	sf::VertexArray cityBack;
	sf::FloatRect bBoxPlayer;
	std::vector<sf::FloatRect> bBoxGrass;
	std::vector<sf::Sprite> grassSprite;
};
 

Game::Game() :mWindow{ sf::VideoMode(800,600),"M.A.D" }, mPlayer() {
	mopenMenuTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\openScene.png");
	mopenMenu.setTexture(mopenMenuTexture);
	p_Position.x = 400;
	p_Position.y = 300;
	mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\frontface.png");
	mPlayer.setPosition(400, 300);
	mPlayer.setTexture(mPlayerTexture);
 
	//mPlayer.setFillColor(sf::Color::Blue);
	//my youth do da animashion here
	Running.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\test.png");
	RunningD.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\runningD.png");
	animationD.setAnimation(&RunningD, sf::Vector2u(6, 2), 0.06f);
	 animationF.setAnimation(&Running, sf::Vector2u(6, 2), 0.006f);
	Jumping.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\jumping.png");
	animationU.setAnimation(&Jumping, sf::Vector2u(4, 1),0.0009f);

	 
	 
	 
	mPlatform.setSize(sf::Vector2f(100.0f, 50.0f));
	mPlatform.setPosition(0, 500);
	

	velocity.setVelocity(5.0f, 5.0f);
	
	
	//bullet.............................................................................
	p_bullets.setBullet("D:\\operationM.A.D\\operationM.A.D\\Assets\\bullet.png", sf::Vector2f(400,310), sf::Vector2f(10, 0)); //mPlayer.getPosition()



	isJump = false;
	isRunning = false;
	isShooting = false;
	isMouseLeft = false;
	isBackFace = false;
	isFrontFace = true;
	isStarted = true;
	isPaused = true;
	mainMenu = false;


	Edeath = false;

	gravity = 75.0f;
	counter = 0.0f;
	
	level1.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\backtex.png");
	level1grass.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\grass.png");
	level1city.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\cityBack.png");
	bBoxPlayer = mPlayer.getLocalBounds();//set the bounding parameters of the BBox
	
	//Back.scale(3, 3);
	high = { high2,high2,high3,high4,high5,high6 };
	for (int i = 0; i < 6; i++) {

		high[i].setEnemy(2, sf::Vector2u(1, 9), 0.0f, sf::Vector2f(700 + 200 * (i + 1), 100));

	}




	//collider = { mPlayer.getLocalBounds() ,bBoxBackground,bBoxGrass};
	menu.set_menu(mWindow.getSize().x, mWindow.getSize().y);
	 
		for (int i = 0; i < 111; i++) {
			sf::Texture text;
			text.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\grass.png");
			sf::Sprite sprite(text);
			grassSprite.push_back(sprite);
			grassSprite[i].setPosition(sf::Vector2f(i * 64, 340));
			 
		}
		for (int i = 0; i < 111; i++){
			sf::FloatRect frect;
			bBoxGrass.push_back(frect);
			bBoxGrass[i] = grassSprite[i].getLocalBounds();
			bBoxGrass[i].left= grassSprite[i].getPosition().x;
			bBoxGrass[i].top = grassSprite[i].getPosition().y;
			 
		}
}


//The game loop begins.......................................................
void Game::run() {
 low1.setEnemy( 1, sf::Vector2u(6,1), 0.006f,sf::Vector2f(-50, 300));
 
	view2.setCenter(sf::Vector2f(400.f, 300.f));
	view2.setSize(sf::Vector2f(800.f, 600.f));
	 
	clock;//clcok starts***************************************************************CLOCK*********************************************
	createbackground(background,1,64,128,6,110,400-25);
	createbackground(grass, 1, 64,96, 1, 110,300-25);
	createbackground(cityBack, 1,504,302, 1, 10, 39);
	while (mWindow.isOpen()) {
		bBoxPlayer.left = mPlayer.getPosition().x;
		bBoxPlayer.top = mPlayer.getPosition().y;
		mWindow.setView(view2);
		dt1 = clock.restart();
		dt2 = dt1.asSeconds();
		mouseAngle = (180.0f / 3.1415f) * atan2f(-sf::Mouse::getPosition(mWindow).y + mPlayer.getPosition().y, sf::Mouse::getPosition(mWindow).x - 400.0f);
		//createbackground(background,sf::IntRect(0,0,2048,256));
		processEvents();
		update();
		render();
		 
	}
}

void Game::processEvents() {
	
	std::set<sf::Keyboard::Key> pressedKeys;
	sf::Vector2f coordi(0.f, 0.f);
	if (event.type == sf::Event::KeyPressed) {
		pressedKeys.insert(event.key.code);
	}
	else if (event.type == sf::Event::KeyReleased) {
		pressedKeys.erase(event.key.code);
	}
	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			mWindow.close();
		}
		else { 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				isStarted = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {//////////////////////TEMPORARY DEVELOPMENT BACKDOOR
				isPaused= false;
			}
			if (!isStarted) {
				if (!isPaused) {
					Cutscene_dt = 0.0;

					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
						isRunning = false;
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {//Run backwards
						//mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\backface.png");
						//mPlayer.setTexture(mPlayerTexture);
						isFrontFace = false;
						isBackFace = true;
						isRunning = true;
						mPlayerTexture = Running;
						animationF.Update(1, dt2);

						mPlayer.setTextureRect(animationF.uvRect);


						coordi.x -= velocity.getVelocity().x;
						view2.move(coordi);
						mPlayer.move(coordi);


					}
					else if (((!isRunning) && (isBackFace))) {
						isRunning = false;


						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\backface.png");
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);

					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)  ) {//Run front//&&(-22.5f < mouseAngle && mouseAngle < 22.5f)
						//mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\frontface.png");
						//mPlayer.setTexture(mPlayerTexture);
						isFrontFace = true;
						isRunning = true;
						isBackFace = false;
						mPlayerTexture = Running;
						animationF.Update(0, dt2);

						mPlayer.setTextureRect(animationF.uvRect);


						//sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						//mPlayer.setTextureRect(textureRect);

						coordi.x += velocity.getVelocity().x ;
						view2.move(coordi);
                        mPlayer.move(coordi);
					}
					else if ((!isRunning) && (isFrontFace)) {
						isRunning = false;
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\frontface.png");
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);

					}
					/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (-67.5f < mouseAngle && mouseAngle < -22.5f)) {
						mPlayerTexture = Running;
						animationF.Update(2, dt2);
						mPlayer.setTextureRect(animationF.uvRect);
						coordi.x += velocity.getVelocity().x;
						view2.move(coordi);

						mPlayer.move(coordi);
					}*/
				/*	if  ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (22.5f < mouseAngle && mouseAngle < 67.5f)){
					
						mPlayerTexture = RunningD;
							animationD.Update(0, dt2);
							mPlayer.setTextureRect(animationD.uvRect);
							coordi.x += velocity.getVelocity().x;
							view2.move(coordi);

							mPlayer.move(coordi);
					}*/
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {// lay down
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\layingDown.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);


					}
				   //Jumping and shooting controls brother
					if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {//jump mechanics................................
						isJump = true;//the O button corresponds to the number "0"

					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {//Shoot mechanics//the X button corresponds to the number "0"
						isShooting = true;
						//isMouseLeft = true;
					}
					else {
						isShooting = false;
						p_bullets.replaceBullet( sf::Vector2f(mPlayer.getPosition().x+10, mPlayer.getPosition().y + 15));
					} 
					if (mouseAngle>67.5f&& mouseAngle<112.5f) {
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\aimUp.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
						p_bullets.setBulletVelocity(sf::Vector2f(0,-10));
					}
					if (mouseAngle > 22.5f && mouseAngle < 67.5f) {
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\aimNE.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
						p_bullets.setBulletVelocity(sf::Vector2f(5, -5));
					}
					if (mouseAngle > 112.5f && mouseAngle < 157.5f) {
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\aimNW.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
						p_bullets.setBulletVelocity(sf::Vector2f(-5, -5));
					}
					if (mouseAngle > -67.5f && mouseAngle < -22.5f) {
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\aimSE.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
					}
					if (mouseAngle > -157.5f && mouseAngle < -112.5f) {
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\aimSW.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
					}
					if (mouseAngle > -112.5f && mouseAngle < -67.5f) {
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\aimS.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
					}


					if (mouseAngle > 157.5f &&  mouseAngle<180.0f) {
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\backface.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
					}
				}

				std::cout << mouseAngle<< std::endl;
			}
		}
		//apply gravity
	
	}
}

//Double buffer here and draw all that.........................
void Game::render()
{
	
	
	mWindow.clear(sf::Color::Black);
	if (isRunning == true) {

	}
	
	 
	mWindow.draw(background, &level1);
	mWindow.draw(grass, &level1grass);
	mWindow.draw(cityBack, &level1city);
	p_bullets.drawBullet(mWindow);
	
	if (!Edeath ){
		low1.Edraw(mWindow, dt2,0);
	}
	mWindow.draw(mPlatform);
	mWindow.draw(mPlayer);
	
	if (isStarted) {
		mWindow.draw(mopenMenu);
	}
	/************************************************CUTSCENES**********************************************************/
	if (!isStarted) {
		if (isPaused) {
			Cutscene_dt += dt2;
			texCutscene.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\scene2.png");
			Cutscene.setTexture(texCutscene);
			mWindow.draw(Cutscene);
			if (Cutscene_dt > .3) {
				texCutscene.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\scene3.png");
				Cutscene.setTexture(texCutscene);
				mWindow.draw(Cutscene);
			}
			if (Cutscene_dt > .6) {
				texCutscene.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\scene4.png");
				Cutscene.setTexture(texCutscene);
				mWindow.draw(Cutscene);
				if (Cutscene_dt > .9) {
					isPaused = false;
					mainMenu = true;
				}
			}

		}
	}
	if (!isStarted) {
		if (!isPaused) {
			if (mainMenu) {
				texCutscene.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\mainMenu.png");//Reusing the same sprite hell naw i am making another sprite for this
				Cutscene.setTexture(texCutscene);
				mWindow.draw(Cutscene);
				menu.menu_draw(mWindow);
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		high[i].Edraw(mWindow, dt2,i);

	}
	 
	mWindow.display();
}


void Game::update() {
	sf::Vector2f coordi(0.f, 0.f);
	//coordi.y += gravity * dt1.asSeconds();
	//mPlayer.move(coordi);

	if (mainMenu) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			menu.menu_moveDown(); 
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			menu.menu_moveUp();	 
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			mainMenu = false;
		}
	}


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
		if (isFrontFace) {
		//	p_bullets.setBulletVelocity(sf::Vector2f(10,0));
			p_bullets.Shoot(dt1, mPlayer.getPosition(), isShooting);
			
		}
		if (isBackFace) {
		//	p_bullets.setBulletVelocity(sf::Vector2f(-10,0));
			p_bullets.Shoot(dt1, mPlayer.getPosition(), isShooting);
		}
		 
	}
	 
	 
		
		/*(if (collision_detection(collider[0], collider[2])) {
			mPlayer.setPosition(400,300);
			std::cout << "working" << std::endl;
		}*/
	if (bBoxPlayer.intersects(low1.Ecollider())) {
		
		mPlayer.move(10,0);
		view2.move(10,0);
	}
	if (low1.Ecollider().intersects(p_bullets.BulletCollider())) {
		Edeath=true;
		
	}
	 //collission with grass
	for (int i = 0; i < 111;i++) {

		if (bBoxGrass[i].intersects(bBoxPlayer)) {
				 
				mPlayer.move(-coordi);
			}
		 
	}

	 
}
	
