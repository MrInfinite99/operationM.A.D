#pragma once
#include<SFML/Graphics.hpp>

//#include"Entities.h"

 

sf::VertexArray background;

//background.setPrimitiveType(sf::Quads);
int createbackground(sf::VertexArray& rVA, sf::IntRect area) {

	const int TILE_SIZE = 32;
	const int TILE_TYPES = 2;
	const int VERTS_IN_QUAD = 4;

	int worldWidth = area.width / TILE_SIZE;//width in term of tiles
	int worldHeight = area.height / TILE_SIZE;//height in term of tiles

	rVA.setPrimitiveType(sf::Quads);
	rVA.resize(static_cast<size_t>(worldWidth) * worldHeight * VERTS_IN_QUAD);

	int currentVertex = 0;

	for (int w = 0; w < worldWidth; w++) {
		for (int h = 0; h < worldHeight; h++) {
			rVA[static_cast<size_t>(currentVertex) + 0].position = sf::Vector2f(w * TILE_SIZE, h * TILE_SIZE);

			rVA[static_cast<size_t>(currentVertex) + 1].position = sf::Vector2f((w + 1) * TILE_SIZE, (h)*TILE_SIZE);

			rVA[static_cast<size_t>(currentVertex) + 2].position = sf::Vector2f(w * TILE_SIZE, (h + 1) * TILE_SIZE);

			rVA[static_cast<size_t>(currentVertex) + 3].position = sf::Vector2f((w + 1) * TILE_SIZE, (h + 1) * TILE_SIZE);

			//tex coordinates
			rVA[static_cast<size_t>(currentVertex) + 0].texCoords = sf::Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);

			rVA[static_cast<size_t>(currentVertex) + 1].texCoords = sf::Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);

			rVA[static_cast<size_t>(currentVertex) + 0].texCoords = sf::Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);

			rVA[static_cast<size_t>(currentVertex) + 0].texCoords = sf::Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);

            currentVertex = currentVertex + VERTS_IN_QUAD;//reminder that VERTS_IN_QUAD == four 4
		}
	}
		return TILE_SIZE;


}



class Animation {
public:
	Animation(sf::Texture* texture,sf::Vector2u imageCount,float switchTime);
	Animation(){
		//std::cout << "hi";
	}
	~Animation() {
		//std::cout << "bye";
	}
	void Update(int row, float deltaTime);
	void setAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
		this->imageCount = imageCount;
		this->switchTime = switchTime;
		totalTime = 0.0f;
		currentImage.x = 0;
		
		uvRect.width = texture->getSize().x / float(imageCount.x);
		uvRect.height = texture->getSize().y / float(imageCount.y);
	}

public:
	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height= texture->getSize().y/ float(imageCount.y);
}
void Animation::Update(int row, float deltaTime) {
	currentImage.y = row;
	totalTime += deltaTime;
	 
	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;
		 

		if (currentImage.x >= imageCount.x) {
			currentImage.x = 0;
		}
	}
	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}


class collision {
public:
	collision();
	~collision();

	bool PointvsRect();
private:
	sf::Vector2f pos;
	sf::Vector2f size;
};