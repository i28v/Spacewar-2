#ifndef DATA_INCLUDED
#define DATA_INCLUDED

#define DEBUG true

#define log(MSG)                                       \
{                                                      \
    if(DEBUG == true) {std::cout << MSG << std::endl;} \
}


#if defined (__WIN32)
#include <windows.h>
#elif defined (__linux)
#include <unistd.h>
#define Sleep(m) usleep(m * 1000)
#endif

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800
#define WINDOW_NAME "Spacewar"
#define WINDOW_STYLE Style::Titlebar | Style::Close
#define kbpress Keyboard::isKeyPressed
#define kb Keyboard
#define STILL 0
#define UP    1
#define DOWN  2
#define LEFT  3
#define RIGHT 4






#endif // DATA_INCLUDED
