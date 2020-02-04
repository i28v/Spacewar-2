#include "Star.h"

Star::Star(Vector2f position, Vector2f size, Color color)
{
	sRect = new RectangleShape();
	sRect->setSize(size);
	sRect->setPosition(position);
	sRect->setFillColor(color);
}

Star::~Star()
{
	delete sRect;
}

void Star::drawTo(RenderWindow& window)
{
	window.draw(*sRect);
}

void Star::setPosition(Vector2f position)
{
	sRect->setPosition(position);
}

void Star::move(Vector2f direction)
{
	sRect->move(direction);
}

float Star::getPositionX()
{
	return sRect->getPosition().x;
}

float Star::getPositionY()
{
	return sRect->getPosition().y;
}