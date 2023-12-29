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
	sf::Texture mpauseMenuTexture;
	sf::Texture level1;
	sf::Texture level1grass;
	sf::Texture level1city;
	sf::Texture texCutscene;
	sf::Texture RunningD;
	sf::Texture RunningD2;
private:
	void processEvents();
	void render();
	void update();
private:
	sf::RenderWindow mWindow;
	sf:: Sprite mPlayer;
	sf::Sprite mopenMenu;
	sf::Sprite mpauseMenu;
	sf::Sprite Cutscene;//just how many sprites maybe a vector??

	menu pause_menu;
	menu menu;

	sf::RectangleShape mPlatform;//to be removed 
	sf::Vector2f p_Position;
	sf::Vector2f old_Position;
	
	sf::View view2;//essentially the camera


	bool isJump;
	bool isRunning;
	bool isAlive;





	bool isFrontFace;/*********/
	bool isBackFace;/**********/
	bool islayingdown;
	bool isDiagonal;


	bool isShooting;
	bool isMouseLeft;

	bool isStarted;
	bool isPaused;
	bool mainMenu;


    
	
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
	Animation animationD2;
	
	
	
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
	sf::VertexArray levelDesign1_0;//towers
	sf::VertexArray levelDesign1_1;
	sf::VertexArray levelDesign2_0;
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
	RunningD2.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\runningD2.png");
	animationD.setAnimation(&RunningD, sf::Vector2u(6, 2), 0.06f);
	 animationF.setAnimation(&Running, sf::Vector2u(6, 2), 0.006f);
	 animationD2.setAnimation(&RunningD2, sf::Vector2u(6, 2), 0.006f);
	Jumping.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\jumping.png");
	animationU.setAnimation(&Jumping, sf::Vector2u(4, 1),0.0009f);

	 
	 
	 
	mPlatform.setSize(sf::Vector2f(100.0f, 50.0f));
	mPlatform.setPosition(0, 500);
	

	velocity.setVelocity(5.0f, 5.0f);
	
	
	//bullet.............................................................................
	p_bullets.setBullet("D:\\operationM.A.D\\operationM.A.D\\Assets\\bullet.png", sf::Vector2f(400,310), sf::Vector2f(10, 0)); //mPlayer.getPosition()



	isJump = false;
	isRunning = false;
	isAlive = true;
	isShooting = false;
	isMouseLeft = false;
	isBackFace = false;
	isFrontFace = true;
	islayingdown = false;
	isDiagonal = false;

	isStarted = true;
	isPaused = true;
	mainMenu = false;


	 

	gravity = 75.0f;
	counter = 0.0f;
	
	level1.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\backtex.png");
	level1grass.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\grass.png");
	level1city.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\cityBack.png");
	bBoxPlayer = mPlayer.getLocalBounds();//set the bounding parameters of the BBox
	
	//Back.scale(3, 3);
	high = { high2,high2,high3,high4,high5,high6 };
	for (int i = 0; i < 6; i++) {
		if((i!=1)&&(i!=2)&&(i!=5))
		high[i].setEnemy(2, sf::Vector2u(1, 9), 0.0f, sf::Vector2f(700 + 200 * (i + 1), 100));
		else {
			high[1].setEnemy(2, sf::Vector2u(1, 9), 0.0f, sf::Vector2f(700 + 200 * (1 + 1), 450));
			high[2].setEnemy(2, sf::Vector2u(1, 9), 0.0f, sf::Vector2f(700 +400 +200 * (2 + 1), 300));
			high[5].setEnemy(2, sf::Vector2u(1, 9), 0.0f, sf::Vector2f(700 + 400 + 200 * (5 + 1), 147));// 200, 700 + 400 + 200 * (5 + 1)
		}
	}




	//collider = { mPlayer.getLocalBounds() ,bBoxBackground,bBoxGrass};
	menu.set_menu(mWindow.getSize().x, mWindow.getSize().y,"PLAY","OPTIONS",5);
	pause_menu.set_menu(mWindow.getSize().x, mWindow.getSize().y,"RESTART","PRESS ESC TO QUIT",2);



		for (int i = 0; i < 111; i++) {//this is for the collision with the ground keep in mind they are not getting drawn ,but only a few of them from the back are 
			sf::Texture text;//drawn to conveneintly place the enemies in the enemy design(using vector grassSprite)
			text.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\grass.png");
			sf::Sprite sprite(text);
			grassSprite.push_back(sprite);
			if((i!=110)||(i!=109))
			grassSprite[i].setPosition(sf::Vector2f(i * 64, 340));
			else {
				grassSprite[110].setPosition(sf::Vector2f(700 + 200 * (0 + 1), 100));//using high[0] position 

				grassSprite[109].setPosition(sf::Vector2f(700 + 200 * (1 + 1), 400));
			}
			 
		}
		for (int i = 0; i < 111; i++){//setting up the bounding boxes for the grass sprites
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
	createbackground(background,1,64,128,6,79,400-25,0);//createbackground(sf::VertexArray& rVA,int l_tiletypes,int l_tilesize_x,int l_tilesize_y,int l_worldheight,int l_worldwidth,float l_positiony)
	createbackground(grass, 1, 64,96, 1, 79,300-25,0);
	createbackground(cityBack, 1,504,302, 1, 10, 39,0);
	createbackground(levelDesign1_0, 1, 64, 128, 6, 1, 153, 700 + 200 * (0 + 1));
	createbackground(levelDesign1_1, 1, 64, 128, 6, 1, 200, 700 +400+ 200 * (5 + 1));
	createbackground(levelDesign2_0, 1, 64, 96, 1, 1, 453, 700 + 200 * (1 + 1));
	while (mWindow.isOpen()) {
		bBoxPlayer.left = mPlayer.getPosition().x;
		bBoxPlayer.top = mPlayer.getPosition().y;
		mWindow.setView(view2);
		dt1 = clock.restart();
		dt2 = dt1.asSeconds();
		mouseAngle = (180.0f / 3.1415f) * atan2f(-sf::Mouse::getPosition(mWindow).y + mPlayer.getPosition().y, sf::Mouse::getPosition(mWindow).x - 400.0f);
		//createbackground(background,sf::IntRect(0,0,2048,256));
	
		render();
		processEvents();
		update();
		 
	}
}

void Game::processEvents() {


	sf::Vector2f coordi(0.f, 0.f);

	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			mWindow.close();
		}

	}
}

//Double buffer here and draw all that.........................
void Game::render()
{
	

		mWindow.clear(sf::Color::Black);
		if (isAlive) {
		if (isRunning == true) {

		}


		mWindow.draw(background, &level1);
		mWindow.draw(grass, &level1grass);
		mWindow.draw(cityBack, &level1city);
		mWindow.draw(levelDesign1_0, &level1);
		mWindow.draw(levelDesign1_1, &level1);
		mWindow.draw(levelDesign2_0, &level1grass);

		if (!low1.Ealive()) {
			low1.Edraw(mWindow, dt2, 0);
		}
		
		p_bullets.drawBullet(mWindow);
		mWindow.draw(mPlatform);
		
		 
		mWindow.draw(mPlayer);
		

		for (int i = 0; i < 6; i++) {
			if (!high[i].Ealive()) {//not alive
				high[i].E_track_player(mWindow, sf::Vector2f(mPlayer.getPosition().x, mPlayer.getPosition().y), dt2, dt1);
				 
			}
		}

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


	}
		if (!isAlive) {
			 
			//mWindow.draw();texture to be added
			pause_menu.menu_draw(mWindow);
		}
	
	mWindow.display();
}


void Game::update() {
	sf::Vector2f coordi(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		isStarted = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {//////////////////////TEMPORARY DEVELOPMENT BACKDOOR
		isPaused = false;
	}
	if (!isStarted) {
		if (!isPaused) {
			if (isAlive) {
				Cutscene_dt = 0.0;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {// lay down
					mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\layingDown.png");
					mPlayer.setTexture(mPlayerTexture);
					sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
					mPlayer.setTextureRect(textureRect);
					std::cout << "S key pressed" << std::endl;
					islayingdown = true;

				}
				else
					islayingdown = false;
				//Jumping and shooting controls brother
			
					
					if ((!islayingdown)||(!isDiagonal)) {
					if (mouseAngle > 67.5f && mouseAngle < 112.5f) {
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\aimUp.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
						p_bullets.setBulletVelocity(sf::Vector2f(0, -5));
					}
					if ((!(sf::Keyboard::isKeyPressed(sf::Keyboard::D))) && (mouseAngle > 22.5f && mouseAngle < 67.5f)) {
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\aimNE.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
						p_bullets.setBulletVelocity(sf::Vector2f(2.23, -2.23));
					}
					if ((!(sf::Keyboard::isKeyPressed(sf::Keyboard::D))) && (mouseAngle > 112.5f && mouseAngle < 157.5f)) {//north west
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\aimNW.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
						p_bullets.setBulletVelocity(sf::Vector2f(-2.23, -2.23));
					}
					if (mouseAngle > -67.5f && mouseAngle < -22.5f) {//South East
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\aimSE.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
						p_bullets.setBulletVelocity(sf::Vector2f(2.23, 2.23));
					}
					if (mouseAngle > -157.5f && mouseAngle < -112.5f) {//South west
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\aimSW.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
						p_bullets.setBulletVelocity(sf::Vector2f(-2.23, 2.23));
					}
					if (mouseAngle > -112.5f && mouseAngle < -67.5f) {//south
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\aimS.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
						p_bullets.setBulletVelocity(sf::Vector2f(0, 5));
					}


					if ((mouseAngle > 157.5f && mouseAngle < 180.0f) || (mouseAngle > -180.0f && mouseAngle < -157.5f)) {//west
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\backface.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
						p_bullets.setBulletVelocity(sf::Vector2f(-5, 0));
					}

					if ((!(sf::Keyboard::isKeyPressed(sf::Keyboard::D))) && (mouseAngle > -22.5f && mouseAngle < 22.5f)) {//east
						mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\frontface.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
						p_bullets.setBulletVelocity(sf::Vector2f(5, 0));
					}
				}

				if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					isRunning = false;
				}
				if(!isDiagonal) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {//Run backwards
						//mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\backface.png");
						//mPlayer.setTexture(mPlayerTexture);
						isFrontFace = false;
						isBackFace = true;
						isRunning = true;
						mPlayerTexture = Running;
						animationF.Update(1, dt2);

						mPlayer.setTextureRect(animationF.uvRect);


						coordi.x -= velocity.getVelocity().x / 100;
						view2.move(coordi);
						mPlayer.move(coordi);
						p_bullets.setBulletVelocity(sf::Vector2f(-5.0f, 0.0f));


					}
					 

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
						isFrontFace = true;
						isRunning = true;
						isBackFace = false;
						mPlayerTexture = Running;
						animationF.Update(0, dt2);

						mPlayer.setTextureRect(animationF.uvRect);




						coordi.x += velocity.getVelocity().x / 100;
						view2.move(coordi);
						mPlayer.move(coordi);
					}
					 
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (mouseAngle >-67.5f  && mouseAngle < -22.5f)) {
					mPlayerTexture = RunningD2;
					animationD2.Update(0, dt2);
					mPlayer.setTextureRect(animationF.uvRect);
					coordi.x += velocity.getVelocity().x/100;
					view2.move(coordi);
                    mPlayer.move(coordi);
					p_bullets.setBulletVelocity(sf::Vector2f(2.23,2.23));
					isDiagonal = true;
				}
				else
					isDiagonal = false;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (mouseAngle >-157.5f && mouseAngle < -122.5f)) {
					mPlayerTexture = RunningD2;
					animationD2.Update(1, dt2);
					mPlayer.setTextureRect(animationF.uvRect);
					coordi.x -= velocity.getVelocity().x/100;
					view2.move(coordi);
					mPlayer.move(coordi);
					p_bullets.setBulletVelocity(sf::Vector2f(-2.23, 2.23));
					isDiagonal = true;
				}
				else
					isDiagonal = false;
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (22.5f < mouseAngle && mouseAngle < 67.5f)) {//north east

					mPlayerTexture = RunningD;
					animationD.Update(0, dt2);
					mPlayer.setTextureRect(animationD.uvRect);
					coordi.x += velocity.getVelocity().x / 100;
					view2.move(coordi);

					mPlayer.move(coordi);
					p_bullets.setBulletVelocity(sf::Vector2f(2.23, -2.23));
				}
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (122.5f < mouseAngle && mouseAngle < 157.5f)) {//north west

					mPlayerTexture = RunningD;
					animationD.Update(1, dt2);
					mPlayer.setTextureRect(animationD.uvRect);
					coordi.x -= velocity.getVelocity().x / 100;
					view2.move(coordi);

					mPlayer.move(coordi);
					p_bullets.setBulletVelocity(sf::Vector2f(-2.23, -2.23));
				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {//jump mechanics................................
					isJump = true;//the O button corresponds to the number "0"

				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {//Shoot mechanics//the X button corresponds to the number "0"
					isShooting = true;
					//isMouseLeft = true;
				}
				else {
					isShooting = false;
					p_bullets.replaceBullet(sf::Vector2f(mPlayer.getPosition().x + 10, mPlayer.getPosition().y + 15));
				}
				if (mPlayer.getPosition().x < 400.0f) {
					coordi.x += velocity.getVelocity().x * 10;
					view2.move(coordi);

					mPlayer.move(coordi);
				}
				if (mPlayer.getPosition().x > 4500.0f) {
					coordi.x -= velocity.getVelocity().x * 10;
					view2.move(coordi);

					mPlayer.move(coordi);
				}
			}

			//std::cout << mouseAngle<< std::endl;

		}
	}


	coordi.y += gravity * dt1.asSeconds();
	mPlayer.move(coordi);

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
	if (!isAlive) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			pause_menu.menu_moveDown();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			pause_menu.menu_moveUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			mWindow.close();
		}
	}


	if (isJump) {
		mPlayer.move(0, -gravity*2 * dt1.asSeconds());
		counter += gravity * 2 * dt1.asSeconds();
		mPlayerTexture = Jumping;
		animationU.Update(0, dt2);
		mPlayer.setTextureRect(animationU.uvRect);
		//std::cout << counter << std::endl;
		bBoxPlayer.left = mPlayer.getPosition().x;
		bBoxPlayer.top = mPlayer.getPosition().y;
		if (counter > 300) {
			isJump = false;
			counter = 0.0f;
		}
	 }
	if (isShooting) {
		 
			p_bullets.Shoot(dt1, mPlayer.getPosition(), isShooting,2000);
			
		}
		 
		 
	
	for (int i = 0; i < 6; i++) {
		if (bBoxPlayer.intersects(high[i].Ebulletcollider())) {
			//isAlive = false;
		}
	}
	 /***********************************LOW1*******************************************/
	if (bBoxPlayer.intersects(low1.Ecollider())) {
		
	//	low1.E_rand_move_Box(true);
		 
	}
	
	if (low1.Ecollider().intersects(p_bullets.BulletCollider())) {
		//low1.Edeath(true);
		//low1.E_rand_move_Box(true);
		
	}
	low1.E_rand_move(mPlayer.getPosition(),dt2);
	for (int i = 0; i < 6; i++) {
		if (high[i].Ecollider().intersects(p_bullets.BulletCollider())) {
			high[i].Edeath(true);
		}
	}
	 //collission with grass
	for (int i = 0; i < 111;i++) {

		if (bBoxGrass[i].intersects(bBoxPlayer)) {
				 
				mPlayer.move(-coordi);
			}
		 
	}
	//collission with 4th wall


	
}
	
