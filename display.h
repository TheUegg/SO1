#ifndef display_h
#define display_h

#include <iostream>
#include <SFML/Graphics.hpp>
#include <RenderWindow.hpp>
#include "enum.h"
#include "interface.h"
#include "input.h"
#include "battleShip.h"

class Display
{
public:
    Display(Interface * interface, Input * input);

    void draw_maze();
    void draw_battleShip();
    void draw_enemy(Name name);
    void draw_scores();
    //void set_game(Game *game); pode ser como se fose o main(controlador geral)
    void draw_texture(unsigned int texture, int lenght, int height, double angle);

    void start();
    void dead(int i);
    void finish();

    void run();

private:
    void load_and_bind_textures();

    sf::RenderWindow _display;

    //novos files
    Interface _interface;
    Input _input;
    //KeyInput _key;// talvez algo assim

    //maze texture
    sf::Texture maze_tex;
    sf::Sprite maze_sprite;

    //Shots texture
    sf::Texture shot_tex;
    sf::Sprite shot_sprite;
    
    //BattleShip textures
    sf::Texture battleShip_0_tex;
    sf::Texture battleShip_1_tex;
    sf::Texture battleShip_2_tex;
    sf::Texture battleShip_3_tex;
    int battleShip_sprite;
    sf::Sprite playerShip[4];


    //Enemy texture
    sf::Texture enemyShip_0_tex;
    sf::Texture enemyShip_1_tex;
    sf::Texture enemyShip_2_tex;
    sf::Texture enemyShip_3_tex;
    int enemyShip_sprite;
    sf::Sprite enemyShip[4];

    sf::Sprite enemies[];


    //UI texture
    sf::Texture score_tex;
    sf::Sprite score_sprite;

    sf::Texture ready_tex;
    sf::Sprite ready_sprite;
    
};

#endif