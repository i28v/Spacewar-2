#include "Bullet.h"

Bullet::Bullet(Vector2f position, Vector2f size)
{
	bTexture = new Texture();
	bSprite = new Sprite();
	bTexture->loadFromMemory(bulletData, sizeof(bulletData));
	bSprite->setTexture(*bTexture);

	bSprite->setPosition(position);
	isBeingFired = true;
}

Bullet::~Bullet()
{
	delete bTexture;
	delete bSprite;
}

Vector2f Bullet::getPosition()
{
	return bSprite->getPosition();
}

FloatRect Bullet::getHitbox()
{
	return bSprite->getGlobalBounds();
}

float Bullet::getPositionX()
{
	return bSprite->getPosition().x;
}

float Bullet::getPositionY()
{
	return bSprite->getPosition().y;
}

void Bullet::drawTo(RenderWindow& window)
{
	window.draw(*bSprite);
}

void Bullet::move(Vector2f direction)
{
	bSprite->move(direction);
}

void Bullet::setPosition(Vector2f position)
{
	bSprite->setPosition(position);
}