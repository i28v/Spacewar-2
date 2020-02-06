#ifndef STAR_H
#define STAR_H
#include "../data.h"

class Star
{
    public:
        Star(Vector2f position, Vector2f size, Color color);
        virtual ~Star();
        void drawTo(RenderWindow& window);
        void setPosition(Vector2f position);
        void move(Vector2f direction);

        float getPositionX();
        float getPositionY();
        bool appearsOnGameRun;
    protected:

    private:
    RectangleShape* sRect;
};

#endif // STAR_H
