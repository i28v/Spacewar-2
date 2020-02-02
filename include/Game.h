#ifndef GAME_H
#define GAME_H
#include "../data.h"
#include "Player.h"
#include "Bullet.h"
#include "Star.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        void start();

    protected:

    private:
    RenderWindow* window;
    Event* event;
    Player* player;
    Clock gameClock;
    Time gameTime;
    Clock fireClock;
    Time fireTime;
    Clock pressSpacebarClock;
    Time pressSpacebarTime;
    // std::vector<AlienShip> alienShips;
    // std::vector<Asteroid> asteroids;
    std::vector<Bullet*> playerBullets;
    std::vector<Star*> backgroundStars;
    bool gameOver;
    bool paused;
    bool fireBullet;
    bool firstUpdateCycle;
    int numberOfBulletsBeingFired;
    void init();
    void events(RenderWindow& window, Event& event);
    void input();
    void draw(RenderWindow& window);
    void update();
};

#endif // GAME_H
