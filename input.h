#ifndef input_h
#define input_h

#include <iostream>
#include <SFML/Graphics.hpp>
#include "interface.h"
#include "enum.h"
//#include<main_class.h>
//#include<player.h>

class Input
{
public:
    Input(Interface * interface);

    void movePlayer(Direction direc);

    void shootPlayer();

    void pause();

    void reset();

    //void run();

    //void draw_texture(unsigned int texture, int length, int height, float angle);

private:
    Interface * _interface;
    //Main * main_;
    //Player * player_;
};

#endif