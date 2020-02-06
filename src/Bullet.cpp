#include "../include/Bullet.h"

Bullet::Bullet(Vector2f position, Vector2f size)
{
    this->bTexture = new Texture();
    this->bSprite = new Sprite();
    this->bTexture->loadFromMemory(bulletData, sizeof(bulletData));
    this->bSprite->setTexture(*bTexture);

    this->bSprite->setPosition(position);
    this->isBeingFired = true;

}

Bullet::~Bullet()
{
    log("bullet deleted lol");
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
