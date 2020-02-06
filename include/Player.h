#ifndef PLAYER_H
#define PLAYER_H

#include "../data.h"
#include "playerData.hpp"

class Player
{
public:
    Player(Vector2f size, Vector2f position);
    virtual ~Player();
    void drawTo(RenderWindow& window);
    bool getVisibility();
    void setVisibility(bool value);
    int getHealth();
    short getDirection();
    void setDirection(short value);
    void addHealth(int amount);
    void subHealth(int amount);
    void setHealth(int amount);
    void move(Vector2f direction);
    Vector2f getPosition();

    float getPositionX();
    float getPositionY();

protected:

private:
    bool isVisible;
    int health;
    short direction;
    Texture* pTexture;
    Sprite* pSprite;
};

#endif // PLAYER_H
