#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include"Entities.h"
#include<vector>
#include<set>
#include<math.h>
#include<sstream>

 
class Game:public CGraphic,protected Entity
{
public:
	Game();
	void run();
	std::vector<Enemy> high;
	sf::Texture mPlayerTexture;//why are textures public
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

	sf::SoundBuffer rifle_buffer;
	sf::SoundBuffer death_buffer;
	sf::SoundBuffer running_buffer;

	sf::Font HiScoreFont;
    sf::Font LiveFont;
private:
	void processEvents();
	void render();
	void update();
private:
	sf::RenderWindow mWindow;
	sf::Sprite mPlayer;
	sf::Sprite mopenMenu;
	sf::Sprite mpauseMenu;
	sf::Sprite Cutscene;//just how many sprites maybe a vector??

	menu pause_menu;
	menu menu1;
	menu settingmenu;

	sf::RectangleShape mPlatform;//to be removed 
	sf::Vector2f p_Position;
	sf::Vector2f old_Position;
	
	sf::View view2;//essentially the camera
	sf::View view1;

	bool isJump;
	bool isRunning;
	bool isAlive;
	bool hasCollided;
	bool isDead;



	bool isFrontFace;/*********/
	bool isBackFace;/**********/
	bool islayingdown;
	bool isDiagonal;


	bool isShooting;
	bool isMouseLeft;

	bool isStarted;
	bool isPaused;
	bool mainMenu;
	bool helpMenu;
	bool settingsMenu;
	bool isReset;

	bool isSound;


	int MainMenuCounter;
	int HiScore;
	int NoOfLives;




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

	Boss Boss;

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
	

	//power up
	powerUp powerUp;

	//sounds and music 
	sf::Music music_cutscene;
	sf::Music music_main;

	std::vector<sf::SoundBuffer> sounds;//doesnt really make a differnce actually
	sf::Sound rifle_sound;
	sf::Sound death_sound;
	sf::Sound running_sound;
	
	std::stringstream ss;
	std::stringstream ss2;
	sf::Text HiScoreText;
	sf::Text LiveText;



};
 

Game::Game() :mWindow{ sf::VideoMode(800,600),"M.A.D" }, mPlayer() {

	mopenMenuTexture.loadFromFile("..\\operationM.A.D\\Assets\\openScene.png");
	mopenMenu.setTexture(mopenMenuTexture);

	p_Position.x = 400;
	p_Position.y = 300;
	mPlayerTexture.loadFromFile("..\\operationM.A.D\\Assets\\frontface.png");
	mPlayer.setPosition(400, 300);
	mPlayer.setTexture(mPlayerTexture);

	//mPlayer.setFillColor(sf::Color::Blue);
	//my youth do da animashion here
	Running.loadFromFile("..\\operationM.A.D\\Assets\\test.png");
	RunningD.loadFromFile("..\\operationM.A.D\\Assets\\runningD.png");
	RunningD2.loadFromFile("..\\operationM.A.D\\Assets\\runningD2.png");
	animationD.setAnimation(&RunningD, sf::Vector2u(6, 2), 0.06f);
	animationF.setAnimation(&Running, sf::Vector2u(6, 2), 0.006f);
	animationD2.setAnimation(&RunningD2, sf::Vector2u(6, 2), 0.006f);
	Jumping.loadFromFile("..\\operationM.A.D\\Assets\\jumping.png");
	animationU.setAnimation(&Jumping, sf::Vector2u(4, 1), 0.0009f);




	mPlatform.setSize(sf::Vector2f(100.0f, 50.0f));
	mPlatform.setPosition(0, 500);


	velocity.setVelocity(5.0f, 5.0f);


	//bullet.............................................................................
	p_bullets.setBullet("..\\operationM.A.D\\Assets\\bullet.png", sf::Vector2f(400, 310), sf::Vector2f(10, 0)); //mPlayer.getPosition()



	isJump = false;
	isRunning = false;
	isAlive = false;
	hasCollided = false;
	isDead = false;


	isShooting = false;
	isMouseLeft = false;


	isBackFace = false;
	isFrontFace = true;
	islayingdown = false;
	isDiagonal = false;

	isStarted = true;
	isPaused = true;
	mainMenu = false;
	helpMenu = false;
	settingsMenu = false;
	isReset = false;

	isSound = true;

	/*float*/
	gravity = 75.0f;
	counter = 0.0f;

	/*int*/
	NoOfLives = 3;
	HiScore = 0;
	MainMenuCounter = 0;

	level1.loadFromFile("..\\operationM.A.D\\Assets\\backtex.png");
	level1grass.loadFromFile("..\\operationM.A.D\\Assets\\grass.png");
	level1city.loadFromFile("..\\operationM.A.D\\Assets\\cityBack.png");
	bBoxPlayer = mPlayer.getLocalBounds();//set the bounding parameters of the BBox

	//Back.scale(3, 3);
	high = { high2,high2,high3,high4,high5,high6 };
	for (int i = 0; i < 6; i++) {
		if ((i != 1) && (i != 2) && (i != 5))
			high[i].setEnemy(2, sf::Vector2u(1, 9), 0.0f, sf::Vector2f(700 + 200 * (i + 1), 100));
		else {
			high[1].setEnemy(2, sf::Vector2u(1, 9), 0.0f, sf::Vector2f(700 + 200 * (1 + 1), 450));
			high[2].setEnemy(2, sf::Vector2u(1, 9), 0.0f, sf::Vector2f(700 + 400 + 200 * (2 + 1), 300));
			high[5].setEnemy(2, sf::Vector2u(1, 9), 0.0f, sf::Vector2f(700 + 400 + 200 * (5 + 1), 147));// 200, 700 + 400 + 200 * (5 + 1)
		}
	}




	//collider = { mPlayer.getLocalBounds() ,bBoxBackground,bBoxGrass};
	menu1.set_menu(mWindow.getSize().x, mWindow.getSize().y, "PLAY", "OPTIONS", 5);//5 is a factor width/factor
	pause_menu.set_menu(mWindow.getSize().x, mWindow.getSize().y, "RESTART", "QUIT", 2);
	settingmenu.set_menu(mWindow.getSize().x, mWindow.getSize().y, "SOUND OFF","BACK",5);


	for (int i = 0; i < 111; i++) {//this is for the collision with the ground keep in mind they are not getting drawn ,but only a few of them from the back are 
		sf::Texture text;//drawn to conveneintly place the enemies in the enemy design(using vector grassSprite)
		text.loadFromFile("..\\operationM.A.D\\Assets\\grass.png");
		sf::Sprite sprite(text);
		grassSprite.push_back(sprite);
		if ((i != 110) || (i != 109))
			grassSprite[i].setPosition(sf::Vector2f(i * 64, 340));
		else {
			grassSprite[110].setPosition(sf::Vector2f(700 + 200 * (0 + 1), 100));//using high[0] position 

			grassSprite[109].setPosition(sf::Vector2f(700 + 200 * (1 + 1), 400));
		}

	}
	for (int i = 0; i < 111; i++) {//setting up the bounding boxes for the grass sprites
		sf::FloatRect frect;
		bBoxGrass.push_back(frect);
		bBoxGrass[i] = grassSprite[i].getLocalBounds();
		bBoxGrass[i].left = grassSprite[i].getPosition().x;
		bBoxGrass[i].top = grassSprite[i].getPosition().y;

	}

	//powerUp
	powerUp.set_powerUp();

	Boss.setBoss();
	if (!music_cutscene.openFromFile("..\\operationM.A.D\\Assets\\cutscene1.wav")) {
		std::cout << "music_cutscene not loading" << std::endl;
	}
	music_main.openFromFile("..\\operationM.A.D\\Assets\\mainmusic.flac");
	sounds.push_back(rifle_buffer);
	sounds.push_back(death_buffer);
	sounds.push_back(running_buffer);
	sounds[0].loadFromFile("..\\operationM.A.D\\Assets\\rifle.wav");
	sounds[1].loadFromFile("..\\operationM.A.D\\Assets\\death.wav");
	sounds[2].loadFromFile("..\\operationM.A.D\\Assets\\runningSound.wav");
	rifle_sound.setBuffer(sounds[0]);
	death_sound.setBuffer(sounds[1]);
	running_sound.setBuffer(sounds[2]);

	//text for the HiScore
	HiScoreFont.loadFromFile("..\\operationM.A.D\\Assets\\menufont.ttf");
	HiScoreText.setFont(HiScoreFont);
	HiScoreText.setFillColor(sf::Color::Color(128,128,128));
	HiScoreText.setCharacterSize(30);
	
	LiveFont.loadFromFile("..\\operationM.A.D\\Assets\\menufont.ttf");
	LiveText.setFont(LiveFont);
	LiveText.setFillColor(sf::Color::Color(128, 128, 128));
	LiveText.setCharacterSize(30);
}
//The game loop begins.......................................................
void Game::run() {
 low1.setEnemy( 1, sf::Vector2u(6,1), 0.006f,sf::Vector2f(-50, 300));
 HiScoreText.setPosition(0.0f, 0.0f);
 ss << "Hi Score = " << HiScore;
 HiScoreText.setString(ss.str());

 LiveText.setPosition(600, 0);
 ss2 << "LIVES = " << NoOfLives;
 LiveText.setString(ss2.str());
 
	
	 music_cutscene.play();
	 music_cutscene.setPlayingOffset(sf::seconds(6.0f));
	 music_cutscene.setVolume(25.0f);
	 if (!isPaused) {
		 music_cutscene.stop();
		 music_main.play();
		 if (!isAlive) {
			 music_main.stop();

		 }
	 }
 

	view2.setCenter(sf::Vector2f(400.f, 300.f));
	view2.setSize(sf::Vector2f(800.f, 600.f));
	view1.setCenter(sf::Vector2f(400.f, 300.f));
	view1.setSize(sf::Vector2f(800.f, 600.f));
	 
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

 
void Game::render()
{

	mWindow.clear(sf::Color::Black);
	if (isDead) {

		mWindow.setView(view2);
		mWindow.draw(grass, &level1grass);
		mWindow.draw(cityBack, &level1city);
		Boss.Boss_draw(mWindow);
		mWindow.draw(background, &level1);
		mWindow.draw(grass, &level1grass);

		mWindow.draw(levelDesign1_0, &level1);
		mWindow.draw(levelDesign1_1, &level1);
		mWindow.draw(levelDesign2_0, &level1grass);

		if (!low1.Ealive()) {
			low1.Edraw(mWindow, dt2, 0);
		}

		p_bullets.drawBullet(mWindow);
		mWindow.draw(mPlatform);

		for (int i = 0; i < 6; i++) {
			if (!high[i].Ealive()) {//not alive
				high[i].E_track_player(mWindow, sf::Vector2f(mPlayer.getPosition().x, mPlayer.getPosition().y), dt2, dt1);

			}
		}

		powerUp.power_draw(mWindow);
		mWindow.draw(mPlayer);
		

		/*************HUD***************/
		mWindow.setView(view1);
		mWindow.draw(HiScoreText);
		mWindow.draw(LiveText);


		

	} 
	mWindow.setView(view1);
		if (isStarted) {
			mWindow.draw(mopenMenu);
		}
		/************************************************CUTSCENES**********************************************************/
		if (!isStarted) {
			if (isPaused) {
				Cutscene_dt += dt2;
				texCutscene.loadFromFile("..\\operationM.A.D\\Assets\\scene2.png");
				Cutscene.setTexture(texCutscene);
				mWindow.draw(Cutscene);
				if (Cutscene_dt > 3.0) {
					texCutscene.loadFromFile("..\\operationM.A.D\\Assets\\scene3.png");
					Cutscene.setTexture(texCutscene);
					mWindow.draw(Cutscene);
				}
				if (Cutscene_dt > 6.0) {
					texCutscene.loadFromFile("..\\operationM.A.D\\Assets\\scene4.png");
					Cutscene.setTexture(texCutscene);
					mWindow.draw(Cutscene);
					if (Cutscene_dt > 9.0) {
						isPaused = false;
						mainMenu = true;
					}
				}

			}
		}
		if (!isStarted) {
			if (!isPaused) {
				if (mainMenu) {
					texCutscene.loadFromFile("..\\operationM.A.D\\Assets\\mainMenu.png");//Reusing the same sprite hell naw i am making another sprite for this
					Cutscene.setTexture(texCutscene);
					mWindow.draw(Cutscene);
					menu1.menu_draw(mWindow);
				}
			}
		}
		if (helpMenu) {
			Cutscene_dt += dt2;
			texCutscene.loadFromFile("..\\operationM.A.D\\Assets\\helpMenu.png");
			Cutscene.setTexture(texCutscene);
			mWindow.draw(Cutscene);
			if (Cutscene_dt > 3.0f) {
				helpMenu = false;
				Cutscene_dt = 0.0f;
				isDead = true;
				isAlive = true;
			}
		}
		if (settingsMenu) {
			texCutscene.loadFromFile("..\\operationM.A.D\\Assets\\pauseMenu.png");
			Cutscene.setTexture(texCutscene);
			mWindow.draw(Cutscene);
			settingmenu.menu_draw(mWindow);

		}

		if (isReset) {
		 
			texCutscene.loadFromFile("..\\operationM.A.D\\Assets\\pauseMenu2.png");
			Cutscene.setTexture(texCutscene);
			mWindow.draw(Cutscene);

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
	//	isPaused = false;
	}
	/********************************************MENU******************************************************/
	if (mainMenu) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			menu1.menu_moveDown();
			MainMenuCounter = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			menu1.menu_moveUp();

			MainMenuCounter = 0;

		}
		if (MainMenuCounter == 0) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				mainMenu = false;
				helpMenu = true;
				Cutscene_dt = 0.0f;
				MainMenuCounter = 0;
			}
		}
		if (MainMenuCounter == 1) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

				mainMenu = false;
				settingsMenu = true;
				MainMenuCounter = 0;

			}
		}
	}
	if (settingsMenu) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			settingmenu.menu_moveDown();
			MainMenuCounter = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			settingmenu.menu_moveUp();

			MainMenuCounter = 0;
		}
		if (MainMenuCounter == 0) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				isSound = false;
			}
		}
		if (MainMenuCounter == 1) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				mainMenu = true;
				settingsMenu = false;
				MainMenuCounter = -1;

			}
		}
	}

	if (!isStarted) {
		if (!isPaused) {
			
			
				if (isReset) {
					std::cout << "hi" << std::endl;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
						pause_menu.menu_moveDown();
						MainMenuCounter = 1;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
						pause_menu.menu_moveUp();
						MainMenuCounter = 0;
					}
					if (MainMenuCounter == 1) {
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
							mWindow.close();
						}
					}
				   
					if (MainMenuCounter == 0) {
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
							isReset = false;
							mainMenu = true;
							MainMenuCounter = -1;
							
						}
					}
				}
		
				if (isDead) {
					

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {// lay down
						mPlayerTexture.loadFromFile("..\\operationM.A.D\\Assets\\layingDown.png");
						mPlayer.setTexture(mPlayerTexture);
						sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
						mPlayer.setTextureRect(textureRect);
						std::cout << "S key pressed" << std::endl;
						islayingdown = true;

					}
					else
						islayingdown = false;
					//Jumping and shooting controls brother


					if ((!islayingdown) || (!isDiagonal)) {
						if (mouseAngle > 67.5f && mouseAngle < 112.5f) {
							mPlayerTexture.loadFromFile("..\\operationM.A.D\\Assets\\aimUp.png");
							mPlayer.setTexture(mPlayerTexture);
							sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
							mPlayer.setTextureRect(textureRect);
							p_bullets.setBulletVelocity(sf::Vector2f(0, -5));
						}
						if ((!(sf::Keyboard::isKeyPressed(sf::Keyboard::D))) && (mouseAngle > 22.5f && mouseAngle < 67.5f)) {
							mPlayerTexture.loadFromFile("..\\operationM.A.D\\Assets\\aimNE.png");
							mPlayer.setTexture(mPlayerTexture);
							sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
							mPlayer.setTextureRect(textureRect);
							p_bullets.setBulletVelocity(sf::Vector2f(2.23, -2.23));
						}
						if ((!(sf::Keyboard::isKeyPressed(sf::Keyboard::D))) && (mouseAngle > 112.5f && mouseAngle < 157.5f)) {//north west
							mPlayerTexture.loadFromFile("..\\operationM.A.D\\Assets\\aimNW.png");
							mPlayer.setTexture(mPlayerTexture);
							sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
							mPlayer.setTextureRect(textureRect);
							p_bullets.setBulletVelocity(sf::Vector2f(-2.23, -2.23));
						}
						if (mouseAngle > -67.5f && mouseAngle < -22.5f) {//South East
							mPlayerTexture.loadFromFile("..\\operationM.A.D\\Assets\\aimSE.png");
							mPlayer.setTexture(mPlayerTexture);
							sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
							mPlayer.setTextureRect(textureRect);
							p_bullets.setBulletVelocity(sf::Vector2f(2.23, 2.23));
						}
						if (mouseAngle > -157.5f && mouseAngle < -112.5f) {//South west
							mPlayerTexture.loadFromFile("..\\operationM.A.D\\Assets\\aimSW.png");
							mPlayer.setTexture(mPlayerTexture);
							sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
							mPlayer.setTextureRect(textureRect);
							p_bullets.setBulletVelocity(sf::Vector2f(-2.23, 2.23));
						}
						if (mouseAngle > -112.5f && mouseAngle < -67.5f) {//south
							mPlayerTexture.loadFromFile("..\\operationM.A.D\\Assets\\aimS.png");
							mPlayer.setTexture(mPlayerTexture);
							sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
							mPlayer.setTextureRect(textureRect);
							p_bullets.setBulletVelocity(sf::Vector2f(0, 5));
						}


						if ((mouseAngle > 157.5f && mouseAngle < 180.0f) || (mouseAngle > -180.0f && mouseAngle < -157.5f)) {//west
							mPlayerTexture.loadFromFile("..\\operationM.A.D\\Assets\\backface.png");
							mPlayer.setTexture(mPlayerTexture);
							sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
							mPlayer.setTextureRect(textureRect);
							p_bullets.setBulletVelocity(sf::Vector2f(-5, 0));
						}

						if ((!(sf::Keyboard::isKeyPressed(sf::Keyboard::D))) && (mouseAngle > -22.5f && mouseAngle < 22.5f)) {//east
							mPlayerTexture.loadFromFile("..\\operationM.A.D\\Assets\\frontface.png");
							mPlayer.setTexture(mPlayerTexture);
							sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
							mPlayer.setTextureRect(textureRect);
							p_bullets.setBulletVelocity(sf::Vector2f(5, 0));
						}
					}

					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
						isRunning = false;
					}
					if (!isDiagonal) {
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {//Run backwards
							//mPlayerTexture.loadFromFile("D:\\operationM.A.D\\operationM.A.D\\Assets\\backface.png");
							//mPlayer.setTexture(mPlayerTexture);
							isFrontFace = false;
							isBackFace = true;
							isRunning = true;
							mPlayerTexture = Running;
							animationF.Update(1, dt2);

							mPlayer.setTextureRect(animationF.uvRect);
							if (isSound) {
								if (!running_sound.getStatus()) {
									running_sound.play();
									running_sound.setPlayingOffset(sf::seconds(0.5));
								}
							}

							coordi.x -= velocity.getVelocity().x / 10;
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
							if (isSound) {
								if (!running_sound.getStatus()) {
									running_sound.play();
									running_sound.setPlayingOffset(sf::seconds(0.5));
								}
							}

							coordi.x += velocity.getVelocity().x / 10;
							view2.move(coordi);
							mPlayer.move(coordi);
						}

					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (mouseAngle > -67.5f && mouseAngle < -22.5f)) {
						mPlayerTexture = RunningD2;
						animationD2.Update(0, dt2);
						mPlayer.setTextureRect(animationF.uvRect);
						coordi.x += velocity.getVelocity().x / 100;
						view2.move(coordi);
						mPlayer.move(coordi);
						p_bullets.setBulletVelocity(sf::Vector2f(2.23, 2.23));
						isDiagonal = true;
						if (isSound) {
							if (!running_sound.getStatus()) {
								running_sound.play();
								running_sound.setPlayingOffset(sf::seconds(0.5));
							}
						}
					}
					else
						isDiagonal = false;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (mouseAngle > -157.5f && mouseAngle < -122.5f)) {
						mPlayerTexture = RunningD2;
						animationD2.Update(1, dt2);
						mPlayer.setTextureRect(animationF.uvRect);
						coordi.x -= velocity.getVelocity().x / 100;
						view2.move(coordi);
						mPlayer.move(coordi);
						p_bullets.setBulletVelocity(sf::Vector2f(-2.23, 2.23));
						isDiagonal = true;
						if (isSound) {
							if (!running_sound.getStatus()) {
								running_sound.play();
								running_sound.setPlayingOffset(sf::seconds(0.5));
							}
						}
					}
					else
						isDiagonal = false;
					if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (22.5f < mouseAngle && mouseAngle < 67.5f)) {//north east

						mPlayerTexture = RunningD;
						animationD.Update(0, dt2);
						mPlayer.setTextureRect(animationD.uvRect);
						coordi.x += velocity.getVelocity().x / 100;
						view2.move(coordi);
						if (isSound) {
							if (!running_sound.getStatus()) {
								running_sound.play();
								running_sound.setPlayingOffset(sf::seconds(0.5));
							}
						}
						mPlayer.move(coordi);
						p_bullets.setBulletVelocity(sf::Vector2f(2.23, -2.23));
					}
					if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (122.5f < mouseAngle && mouseAngle < 157.5f)) {//north west

						mPlayerTexture = RunningD;
						animationD.Update(1, dt2);
						mPlayer.setTextureRect(animationD.uvRect);
						coordi.x -= velocity.getVelocity().x / 100;
						view2.move(coordi);
						if (isSound) {
							if (!running_sound.getStatus()) {
								running_sound.play();
								running_sound.setPlayingOffset(sf::seconds(0.5f));
							}
						}
						mPlayer.move(coordi);
						p_bullets.setBulletVelocity(sf::Vector2f(-2.23f, -2.23f));
					}

					if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {//jump mechanics................................
						isJump = true;//the O button corresponds to the number "0"

					}

					/*******SHOOTING*********/
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {//Shoot mechanics//the X button corresponds to the number "0"
						isShooting = true;
						if (isSound) {
							if (!rifle_sound.getStatus()) {
								rifle_sound.play();
							}
						}

					}
					else {
						//rifle_sound.stop();
						isShooting = false;
						p_bullets.replaceBullet(sf::Vector2f(mPlayer.getPosition().x + 10.0f, mPlayer.getPosition().y + 15.0f));

					}

					/****************/
					if (mPlayer.getPosition().x < 400.0f) {
						coordi.x += velocity.getVelocity().x * 10.0f;
						view2.move(coordi);

						mPlayer.move(coordi);
					}
					if (mPlayer.getPosition().x > 4500.0f) {
						coordi.x -= velocity.getVelocity().x * 10.0f;
						view2.move(coordi);

						mPlayer.move(coordi);
					}


					//std::cout << mouseAngle<< std::endl;

					coordi.y += gravity * dt1.asSeconds();
					mPlayer.move(coordi);




					if (isJump) {
						mPlayer.move(0, -gravity * 2 * dt1.asSeconds());
						counter += gravity * 2 * dt1.asSeconds();
						mPlayerTexture = Jumping;
						animationU.Update(0, dt2);
						mPlayer.setTextureRect(animationU.uvRect);

						bBoxPlayer.left = mPlayer.getPosition().x;
						bBoxPlayer.top = mPlayer.getPosition().y;
						if (counter > 100) {
							isJump = false;
							animationU.Update(0, dt2);
							mPlayer.setTextureRect(animationU.uvRect);
							bBoxPlayer.left = mPlayer.getPosition().x;
							bBoxPlayer.top = mPlayer.getPosition().y;
							counter = 0.0f;
						}
					}
					if (isShooting) {

						p_bullets.Shoot(dt1, mPlayer.getPosition(), isShooting, 2000);

					}


					/*******************COLLISION***********************/
					if (!(NoOfLives < 1)) {
						for (int i = 0; i < 6; i++) {
							if (bBoxPlayer.intersects(high[i].Ebulletcollider())) {
								NoOfLives--;
								if (NoOfLives < 1) {
									isAlive = false;
								}
								std::stringstream ssLives;
								ssLives << "LIVES = " << NoOfLives;
								LiveText.setString(ssLives.str());
							}
						}
						/*********LOW1********/
						low1.E_rand_move(mPlayer.getPosition(), dt2);//random movement of enemy soldier
						if (bBoxPlayer.intersects(low1.Ecollider())) {
							NoOfLives--;
							if (NoOfLives < 1) {
								//isAlive = false;
							}
							std::stringstream ssLives;
							ssLives << "LIVES = " << NoOfLives;
							LiveText.setString(ssLives.str());
							HiScore = 0;
						}
					}


					if (low1.Ecollider().intersects(p_bullets.BulletCollider())) {
						low1.Edeath(true);
						//low1.E_rand_move_Box(true);
						HiScore += 100;
						std::stringstream ssHiScore;
						ssHiScore << "Hi Score = " << HiScore;
						HiScoreText.setString(ssHiScore.str());


					}

					for (int i = 0; i < 6; i++) {
						if (high[i].Ecollider().intersects(p_bullets.BulletCollider())) {
							high[i].Edeath(true);
							HiScore += 100;
							std::stringstream ssHiScore;
							ssHiScore << "Hi Score = " << HiScore;

							HiScoreText.setString(ssHiScore.str());

							//	death_sound.play();
						}
					}

					//collission with grass
					for (int i = 0; i < 111; i++) {

						if (bBoxGrass[i].intersects(bBoxPlayer)) {

							mPlayer.move(-coordi);
						}

					}


					//power up mechanism
					powerUp.power_M(mPlayer.getPosition(), dt2);

					if (p_bullets.BulletCollider().intersects(powerUp.power_collider())) {
						powerUp.power_final(bBoxGrass);
					}
					powerUp.power_move(dt2);

					if (bBoxPlayer.intersects(powerUp.power_collider())) {

						powerUp.OutOfTheWay();
						powerUp.power_state(false);
						p_bullets.setBullettexture("..\\operationM.A.D\\Assets\\laser.png");
						rifle_buffer.loadFromFile("..\\operationM.A.D\\Assets\\lasergun.wav");
						rifle_sound.setBuffer(rifle_buffer);
						rifle_sound.setVolume(100.0f);

					}
					/****************BOSS*********************/
					if (Boss.Boss_cinematic_1(mPlayer.getPosition())) {
						if (mPlayer.getPosition().x <= 3900.0) {
							mPlayer.move(10.0f, 0.0f);
							view2.move(10.0f, 0.0f);
						}
						if (mPlayer.getPosition().x >= 4300.0) {
							mPlayer.move(-10.0f, 0.0f);
							view2.move(-10.0f, 0.0f);
						}
					}

					Boss.Boss_mechanics(mPlayer.getPosition(), dt2, dt1);
					//std::cout << Boss.Boss_cinematic_1(mPlayer.getPosition()) << std::endl;


					if (!isAlive) {
						
						
							mPlayerTexture.loadFromFile("..\\operationM.A.D\\Assets\\deadface.png");
							mPlayer.setTexture(mPlayerTexture);
							sf::IntRect textureRect(0, 0, mPlayerTexture.getSize().x, mPlayerTexture.getSize().y);
							mPlayer.setTextureRect(textureRect);
							Cutscene_dt += dt2;
						
						
						if (Cutscene_dt > 5.0) {
							isReset = true;
							isDead = false;
						}

					}
				}
				
 
			}
		}
	}

	
