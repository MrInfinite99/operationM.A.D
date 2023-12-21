#pragma once
#include<SFML/Graphics.hpp>

//#include"Entities.h"

 


//background.setPrimitiveType(sf::Quads);
int createbackground(sf::VertexArray& rVA,int l_tiletypes,int l_tilesize_x,int l_tilesize_y,int l_worldheight,int l_worldwidth,float l_positiony,sf::FloatRect area) {//, sf::IntRect area

	 int tile_size_x = l_tilesize_x;
	 int tile_size_y = l_tilesize_y;
	  int tile_types = l_tiletypes;
	const int VERTS_IN_QUAD = 4;

	int worldWidth = l_worldwidth;//width in term of tiles make sure that the actual world width is divisible by the tilesize
	int worldHeight = l_worldheight;//height in term of tiles

	rVA.setPrimitiveType(sf::Quads);
	rVA.resize(worldWidth * worldHeight * VERTS_IN_QUAD);

	int currentVertex = 0;

	for (int w = 0; w < worldWidth; w++) {
		for (int h = 0; h < worldHeight; h++) {
			rVA[currentVertex + 0].position = sf::Vector2f(w * tile_size_x, l_positiony+h * tile_size_y);

			rVA[currentVertex + 1].position = sf::Vector2f((w + 1) * tile_size_x, l_positiony +(h)*tile_size_y);
			rVA[currentVertex + 2].position = sf::Vector2f((w + 1) * tile_size_x, l_positiony +(h + 1) * tile_size_y);
			rVA[ currentVertex+ 3].position = sf::Vector2f(w * tile_size_x, l_positiony + (h + 1) * tile_size_y);

			

			//tex coordinates
			rVA[currentVertex + 3].texCoords = sf::Vector2f(0, 0 + tile_types * tile_size_y);

			rVA[currentVertex + 2].texCoords = sf::Vector2f(tile_size_x, 0 +tile_types * tile_size_y);

			rVA[currentVertex+ 1].texCoords = sf::Vector2f(tile_size_x, 0);//TILE_SIZE + TILE_TYPES * TILE_SIZE

			rVA[currentVertex+ 0].texCoords = sf::Vector2f(0, 0);//TILE_SIZE + TILE_TYPES * TILE_SIZE

            currentVertex = currentVertex + VERTS_IN_QUAD;//reminder that VERTS_IN_QUAD == four 4
		}
	} 
	return tile_size_x;


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
bool collision_detection(sf::IntRect& rect1, sf::IntRect& rect2) {
	return rect1.intersects(rect2);
}