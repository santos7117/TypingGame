#pragma once
#include <SFML\Graphics.hpp>
class Animation
{
public:
    Animation() {}
	Animation(sf::Texture *texture,sf::Vector2u imageCount, float switchTime)
	{
	this-> imageCount = imageCount;
	this->switchTime = switchTime;

	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x); //width and height of single texture
	uvRect.height = texture->getSize().y / float(imageCount.y);

	}

	void Update(int row, float deltaTime)
	{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
        {
            currentImage.x = 0;
            currentImage.y += 1;
        }

	}
	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;

	}

public:
	sf::IntRect uvRect;
	sf::Vector2u currentImage;

private:
	sf::Vector2u imageCount;

	float totalTime;
	float switchTime;

};


