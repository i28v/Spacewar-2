#ifndef BULLET_H
#define BULLET_H

#include "../data.h"
#include "bulletData.hpp"

class Bullet
{
    public:
        Bullet(Vector2f position, Vector2f size);
        virtual ~Bullet();
        bool isBeingFired;
        Vector2f getPosition();
        FloatRect getHitbox();

        float getPositionX();
        float getPositionY();
        void setPosition(Vector2f position);
        void move(Vector2f direction);
        void drawTo(RenderWindow& window);
    protected:

    private:
    Texture* bTexture;
    Sprite* bSprite;
};

#endif // BULLET_H
