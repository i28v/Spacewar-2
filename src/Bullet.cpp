#include "Bullet.h"

Bullet::Bullet(Vector2f position, Vector2f size)
{
    this->bTexture = new Texture();
    this->bSprite = new Sprite();
    this->bTexture->loadFromMemory(bulletData, sizeof(bulletData));
    this->bSprite->setTexture(*this->bTexture);

    this->bSprite->setPosition(position);
    this->isBeingFired = true;
}

Bullet::~Bullet()
{
    delete this->bTexture;
    delete this->bSprite;
}

Vector2f Bullet::getPosition()
{
    return this->bSprite->getPosition();
}

FloatRect Bullet::getHitbox()
{
    return this->bSprite->getGlobalBounds();
}

float Bullet::getPositionX()
{
    return this->bSprite->getPosition().x;
}

float Bullet::getPositionY()
{
    return this->bSprite->getPosition().y;
}

void Bullet::drawTo(RenderWindow& window)
{
    window.draw(*this->bSprite);
}

void Bullet::move(Vector2f direction)
{
    this->bSprite->move(direction);
}

void Bullet::setPosition(Vector2f position)
{
    this->bSprite->setPosition(position);
}
