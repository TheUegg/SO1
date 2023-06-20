#include "input.h"


Input::Input(Display * display /*, Main * main, Player * player*/)
{
    this->display_=display;
    //this->main_=main;
    //this->player_=player;
}

void Input::draw_texture(unsigned int texture, int length, int height, float angle)
{
}

void Input::run()
{
    sf::RenderWindow window(sf::VideoMode(900, 560), "SFML works!");

    //Link: https://www.sfml-dev.org/tutorials/2.5/window-events.php
    //https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
    window.setKeyRepeatEnabled(false);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                 window.close();
                 break;
            
            // key pressed
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    std::cout << "Keyboard esquerda!" << std::endl;
                    //player_.moveLeft();
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    std::cout << "Keyboard direita!" << std::endl;
                    //player_.moveRight();
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    std::cout << "Keyboard para baixo!" << std::endl;
                    //player_.moveDown();
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    std::cout << "Keyboard para cima!" << std::endl;
                    //player_.moveUp();
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    std::cout << "Keyboard espaco!" << std::endl;
                    //player_.shoot();
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                    std::cout << "Keyboard P!" << std::endl;
                    //main_.pause();
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                    std::cout << "Keyboard Q!" << std::endl;
                    //main_.exit();
                    //ou podemos fazer direto um
                    window.close();
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    std::cout << "Keyboard para R!" << std::endl;
                    //main_.reset();
                } else
                    std::cout << "Keyboard pressed = " << event.key.code << std::endl;
                break;
            
            }
        }

        window.clear();
        window.draw(display_.maze_sprite);
        
        display_.space_ship_sprite.setPosition(220, 365);
        window.draw(space_ship_sprite);
        
        display_.enemy_ship_sprite.setPosition(245, 150);
        window.draw(display_.enemy_ship_sprite);

        display_.shot_sprite.setPosition(204, 400);
        window.draw(display_.shot_sprite);
        
        window.display();
    }
}
