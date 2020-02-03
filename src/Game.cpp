#include "Game.h"

Game::Game()
{

}

void Game::init()
{
    this->window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, WINDOW_STYLE);
    this->event = new Event();
    this->player = new Player({2.0f, 2.0f}, {320, 500});
    this->player->setVisibility(true);
    this->gameOver = false;
    this->paused = false;
    this->fireBullet = false;
    this->removeSpawnStars = true;
    this->gameClock.restart();
    this->fireClock.restart();
    this->pressSpacebarClock.restart();
    this->removeSpawnStarsClock.restart();
    for(int i = 0; i < 150; i++)
    {
        starSize = rand() % 2 + 1;
        this->backgroundStars.push_back(new Star({static_cast<float>(rand() % 800), static_cast<float>(rand() % 600)}, {starSize, starSize}, Color::White));
        this->backgroundStars[i]->appearsOnGameRun = true;
    }
}

Game::~Game()
{
    delete this->window;
    delete this->event;
    delete this->player;
    for(int i = 0; i < this->playerBullets.size(); i++)
    {
        this->playerBullets.erase(this->playerBullets.begin());
    }
    for(int i = 0; i < this->backgroundStars.size(); i++)
    {
        this->backgroundStars.erase(this->backgroundStars.begin());
    }
}

void Game::events(RenderWindow& window, Event& event)
{
    while(window.pollEvent(event))
    {
        if(event.type == Event::Closed)
        {
            window.close();
            exit(0);
        }
    }
}

void Game::input()
{
    this->pressSpacebarTime = this->pressSpacebarClock.getElapsedTime();
    if(kbpress(kb::Up)) this->player->setDirection(UP);
    if(kbpress(kb::Down)) this->player->setDirection(DOWN);
    if(kbpress(kb::Left)) this->player->setDirection(LEFT);
    if(kbpress(kb::Right)) this->player->setDirection(RIGHT);
    if(kbpress(kb::Space) && this->pressSpacebarTime.asMilliseconds() > 100)
    {
        this->fireBullet = true;
        this->pressSpacebarClock.restart();
    }
    else if(!kbpress(kb::Up) && !kbpress(kb::Down) && !kbpress(kb::Left) && !kbpress(kb::Right))
    {
        this->player->setDirection(STILL);
    }
}

void Game::update()
{
    this->gameTime = this->gameClock.getElapsedTime();
    this->fireTime = this->fireClock.getElapsedTime();
    this->removeSpawnStarsTime = this->removeSpawnStarsClock.getElapsedTime();
    /*
    if(this->removeSpawnStarsTime.asSeconds() > 10 && this->removeSpawnStars == true)
    {
          this->removeSpawnStars = false;
          for(int i = 0; i < 150; i++)
          {
              this->backgroundStars.erase(this->backgroundStars.end() - 1);
          }
    }
    */
    starSize = rand() % 2 + 1;
    this->backgroundStars.push_back(new Star({static_cast<float>(rand() % 800), static_cast<float>(rand() % -1)}, {starSize, starSize}, Color::White));
    for(int i = 0; i < backgroundStars.size(); i++)
    {
        this->backgroundStars[i]->move({0.0f, 4.0f});
        if(this->backgroundStars[i]->getPositionY() > 670  && this->removeSpawnStarsTime.asSeconds() > 3.5f /* this->backgroundStars[i]->appearsOnGameRun == false */ )
        {
            this->backgroundStars.erase(this->backgroundStars.begin());
        }
    }
    switch(this->player->getDirection())
    {
    case STILL:
        break;
    case UP:
        if(this->player->getPositionY() > 390)
        {
            this->player->move({0.0f, -3.0f});
        }
        break;
    case DOWN:
        if(this->player->getPositionY() < 569)
        {
            this->player->move({0.0f, 3.0f});
        }
        break;
    case LEFT:
        if(this->player->getPositionX() > 0)
        {
            this->player->move({-3.0f, 0.0f});
        }
        break;
    case RIGHT:
        if(this->player->getPositionX() < 770)
        {
            this->player->move({3.0f, 0.0f});
        }
    }
    if(this->fireBullet == true)
    {
        if(this->fireTime.asMilliseconds() > 200)
        {
            this->fireClock.restart();
            this->fireBullet = false;
            this->playerBullets.push_back(new Bullet({this->player->getPositionX() + 10, this->player->getPositionY()}, {3.0f, 3.0f}));
            this->numberOfBulletsBeingFired++;
        }
    }
    if(this->numberOfBulletsBeingFired > 0)
    {
        for(int i = 0; i < this->playerBullets.size(); i++)
        {
            this->playerBullets[i]->move({0.0f, -5.0f});
            if(this->playerBullets[i]->getPositionY() < -50)
            {
                numberOfBulletsBeingFired--;
                this->playerBullets.erase(this->playerBullets.begin());
            }
        }
    }
}

void Game::draw(RenderWindow& window)
{
    window.clear(sf::Color::Black);
    for(int i = 0; i < this->backgroundStars.size(); i++)
    {
        this->backgroundStars[i]->drawTo(window);
    }
    this->player->drawTo(window);
    if(this->numberOfBulletsBeingFired > 0)
    {
        for(int i = 0; i < this->playerBullets.size(); i++)
        {
            this->playerBullets[i]->drawTo(window);
        }
    }
    window.display();
}

void Game::start()
{
    this->init();
    while(true)
    {
        while(this->paused == false)
        {
            while(this->gameOver == false)
            {
                this->events(*this->window, *this->event);
                this->input();
                this->update();
                this->draw(*this->window);
               // std::cout << this->backgroundStars.size() << std::endl;
                Sleep(16);
            }
        }
    }
}

