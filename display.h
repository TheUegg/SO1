#ifndef display_h
#define display_h

#include <iostream>
#include <SFML/Graphics.hpp>

class Display
{
public:
    Display();
    
    sf::Sprite maze_sprite;
    sf::Sprite shot_sprite;
    sf::Sprite space_ship_sprite;
    sf::Sprite enemy_ship_sprite;

private:
    void load_and_bind_textures();

    sf::Texture maze_tex;
    sf::Texture shot_tex;
    sf::Texture space_ship_tex;
    sf::Texture enemy_ship_tex;
};

#endif