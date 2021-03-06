#include "../include/Player.h"

Player::Player(Vector2f size, Vector2f position)
{
    this->pTexture = new Texture();
    this->pSprite = new Sprite();
    this->pTexture->loadFromMemory(playerData, sizeof(playerData));
    this->pSprite->setTexture(*pTexture);
    this->pSprite->setScale(size);
    this->pSprite->setPosition(position);

}

Player::~Player()
{
    delete pTexture;
    delete pSprite;

}

void Player::drawTo(RenderWindow& window)
{
    if(isVisible == true)
    {
        window.draw(*pSprite);
    }
}

bool Player::getVisibility()
{
    return isVisible;
}

void Player::setVisibility(bool value)
{
    isVisible = value;
}

int Player::getHealth()
{
    return health;
}

short Player::getDirection()
{
    return direction;
}

void Player::setDirection(short value)
{
    direction = value;
}

Vector2f Player::getPosition()
{
    return pSprite->getPosition();
}

float Player::getPositionX()
{
    return pSprite->getPosition().x;
}

float Player::getPositionY()
{
    return pSprite->getPosition().y;
}

void Player::move(Vector2f direction)
{
    pSprite->move(direction);
}

void Player::addHealth(int amount)
{
    health += amount;
}

void Player::subHealth(int amount)
{
    health -= amount;
}

void Player::setHealth(int amount)
{
    health = amount;
}

