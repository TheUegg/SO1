#ifndef input_h
#define input_h

#include <iostream>
#include <SFML/Graphics.hpp>
#include<display.h>
//#include<main_class.h>
//#include<player.h>

class Input
{
public:
    Input(Display * display /*, Main * main, Player * player*/);

    void run();

    void draw_texture(unsigned int texture, int length, int height, float angle);

private:
    Display * display_;
    //Main * main_;
    //Player * player_;
};

#endif