#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"window.h"
enum class Components{

};
 
class CGraphic{//sets what an entity is going to look like 
public:
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Vector2f position;
public:
	void set_position(float x, float y) {
		position.x = x;
		position.y = y;
		Sprite.setPosition(x, y);
			
	}


	void set_texture(std::string string) {
		Texture.loadFromFile(string);
		sf::Sprite l_sprite(Texture,sf::IntRect(0,0,32,32));
		Sprite = l_sprite;
	}

	sf::Texture& get_texture() {
		return Texture;
	}

	void set_sprite() {
		sf::Sprite l_sprite(Texture);
		Sprite = l_sprite;
	}

	sf::Sprite get_sprite() {
		return this->Sprite;
	}
	void scale(int x, int y) {
		Sprite.setScale(x, y);
	}

	CGraphic(std::string string) {
		set_texture(string);
		set_sprite();

	}
	CGraphic(){}
};
template<class T>
class Cposition {//position of an entity
public:
	T* x;
	T* y;
	sf::Vector2f position();
	Cposition(T a,T b){
		x = a;
		y = b;
		position(x, y);

	}

};
//Name of an entity
class Cname {

	std::string name;
public:
	Cname(std::string l_name) {
		name = l_name;
	}
	Cname();

	std::string getName(std::string l_name) {
		return l_name;
	}

};

class Vec2 {//General use vector
public:
	float x = 0;
	float y = 0;
	Vec2() {}
	Vec2(float l_x, float l_y) :x{ l_x }, y{ l_y }
	{}
	Vec2 operator + (Vec2& v) {
		return Vec2(x + v.x, y + v.y);
	}
};

