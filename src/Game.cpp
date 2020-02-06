#include "../include/Game.h"

Game::Game()
{

}

void Game::init()
{
    window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, WINDOW_STYLE);
    event = new Event();
    player = new Player({2.0f, 2.0f}, {320, 500});
    player->setVisibility(true);
    gameOver = false;
    paused = false;
    fireBullet = false;
    removeSpawnStars = true;
    gameClock.restart();
    fireClock.restart();
    pressSpacebarClock.restart();
    removeSpawnStarsClock.restart();
    for(int i = 0; i < 150; i++)
    {
        starSize = rand() % 2 + 1;
        backgroundStars.push_back(new Star({static_cast<float>(rand() % 800), static_cast<float>(rand() % 600)}, {starSize, starSize}, Color::White));
        backgroundStars[i]->appearsOnGameRun = true;
    }
}

Game::~Game()
{

}

void Game::cleanUp()
{
    log("Destroying Game object");
    delete window;
    delete event;
    delete player;
    for(int i = 0; i < playerBullets.size(); i++)
    {
        Bullet* tmp = playerBullets[i];
        delete(tmp);
     //   playerBullets.erase(playerBullets.begin() + i);
    }
    for(int i = 0; i < backgroundStars.size(); i++)
    {
        Star* tmp = backgroundStars[i];
        delete(tmp);
    }
}

void Game::events(RenderWindow& window, Event& event)
{
    while(window.pollEvent(event))
    {
        if(event.type == Event::Closed)
        {
            window.close();
            cleanUp();
            exit(0);
        }
    }
}

void Game::input()
{
    pressSpacebarTime = pressSpacebarClock.getElapsedTime();
    if(kbpress(kb::Up)) player->setDirection(UP);
    if(kbpress(kb::Down)) player->setDirection(DOWN);
    if(kbpress(kb::Left)) player->setDirection(LEFT);
    if(kbpress(kb::Right)) player->setDirection(RIGHT);
    if(kbpress(kb::Space) && pressSpacebarTime.asMilliseconds() > 100)
    {
        fireBullet = true;
        pressSpacebarClock.restart();
    }
    else if(!kbpress(kb::Up) && !kbpress(kb::Down) && !kbpress(kb::Left) && !kbpress(kb::Right))
    {
        player->setDirection(STILL);
    }
}

void Game::update()
{
    gameTime = gameClock.getElapsedTime();
    fireTime = fireClock.getElapsedTime();
    removeSpawnStarsTime = removeSpawnStarsClock.getElapsedTime();
    /*
    if(removeSpawnStarsTime.asSeconds() > 10 && removeSpawnStars == true)
    {
          removeSpawnStars = false;
          for(int i = 0; i < 150; i++)
          {
              backgroundStars.erase(backgroundStars.end() - 1);
          }
    }
    */
    starSize = rand() % 2 + 1;
    backgroundStars.push_back(new Star({static_cast<float>(rand() % 800), static_cast<float>(rand() % -1)}, {starSize, starSize}, Color::White));
    for(int i = 0; i < backgroundStars.size(); i++)
    {
        backgroundStars[i]->move({0.0f, 4.0f});
        if(backgroundStars[i]->getPositionY() > 670  && removeSpawnStarsTime.asSeconds() > 3.5f /* backgroundStars[i]->appearsOnGameRun == false */ )
        {
            Star* tmp = backgroundStars[i]; // we need to create a pointer to the current star so we can delete it later
            backgroundStars.erase(backgroundStars.begin() + i); // the star gets removed from the vector, but it's still in memory
            delete (tmp); // but we still have the memory address so it can be deleted
        }
    }
    switch(player->getDirection())
    {
    case STILL:
        break;
    case UP:
        if(player->getPositionY() > 390)
        {
            player->move({0.0f, -3.0f});
        }
        break;
    case DOWN:
        if(player->getPositionY() < 569)
        {
            player->move({0.0f, 3.0f});
        }
        break;
    case LEFT:
        if(player->getPositionX() > 0)
        {
            player->move({-3.0f, 0.0f});
        }
        break;
    case RIGHT:
        if(player->getPositionX() < 770)
        {
            player->move({3.0f, 0.0f});
        }
    }
    if(fireBullet == true)
    {
        if(fireTime.asMilliseconds() > 200)
        {
            fireClock.restart();
            fireBullet = false;
            playerBullets.push_back(new Bullet({player->getPositionX() + 10, player->getPositionY()}, {3.0f, 3.0f}));
            numberOfBulletsBeingFired++;
        }
    }
    if(numberOfBulletsBeingFired > 0)
    {
        for(int i = 0; i < playerBullets.size(); i++)
        {
            playerBullets[i]->move({0.0f, -5.0f});
            if(playerBullets[i]->getPositionY() < -50)
            {
                numberOfBulletsBeingFired--;
                Bullet* tmp = playerBullets[i];
                playerBullets.erase(playerBullets.begin() + i);
                delete(tmp);
            }
        }
    }
}

void Game::draw(RenderWindow& window)
{
    window.clear(sf::Color::Black);
    for(int i = 0; i < backgroundStars.size(); i++)
    {
        backgroundStars[i]->drawTo(window);
    }
    player->drawTo(window);
    if(numberOfBulletsBeingFired > 0)
    {
        for(int i = 0; i < playerBullets.size(); i++)
        {
            playerBullets[i]->drawTo(window);
        }
    }
    window.display();
}

void Game::start()
{
    init();
    while(true)
    {
        while(paused == false)
        {
            while(gameOver == false)
            {
                events(*window, *event);
                input();
                update();
                draw(*window);
               // std::cout << backgroundStars.size() << std::endl;
                Sleep(16);
            }
        }
    }
}

