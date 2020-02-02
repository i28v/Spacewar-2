#include "Star.h"

Star::Star(Vector2f position, Vector2f size, Color color)
{
    this->sRect = new RectangleShape();
    this->sRect->setSize(size);
    this->sRect->setPosition(position);
    this->sRect->setFillColor(color);
}

Star::~Star()
{
    delete this->sRect;
}

void Star::drawTo(RenderWindow& window)
{
    window.draw(*this->sRect);
}

void Star::setPosition(Vector2f position)
{
    this->sRect->setPosition(position);
}

void Star::move(Vector2f direction)
{
    this->sRect->move(direction);
}

float Star::getPositionX()
{
    return this->sRect->getPosition().x;
}

float Star::getPositionY()
{
    return this->sRect->getPosition().y;
}
