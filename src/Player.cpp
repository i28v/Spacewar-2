#include "Player.h"

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
    delete this->pTexture;
    delete this->pSprite;
}

void Player::drawTo(RenderWindow& window)
{
    if(this->isVisible == true)
    {
        window.draw(*this->pSprite);
    }
}

bool Player::getVisibility()
{
    return this->isVisible;
}

void Player::setVisibility(bool value)
{
    this->isVisible = value;
}

int Player::getHealth()
{
    return this->health;
}

short Player::getDirection()
{
    return this->direction;
}

void Player::setDirection(short value)
{
    this->direction = value;
}

Vector2f Player::getPosition()
{
    return this->pSprite->getPosition();
}

float Player::getPositionX()
{
    return this->pSprite->getPosition().x;
}

float Player::getPositionY()
{
    return this->pSprite->getPosition().y;
}

void Player::move(Vector2f direction)
{
    this->pSprite->move(direction);
}

void Player::addHealth(int amount)
{
    this->health += amount;
}

void Player::subHealth(int amount)
{
    this->health -= amount;
}

void Player::setHealth(int amount)
{
    this->health = amount;
}

