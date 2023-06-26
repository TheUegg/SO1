#include "display.h"
#include "enum.h"

Display::Display(Interface * interface){
    load_and_bind_textures();
    _interface = *interface;
    battleShip_sprite = 0;
    enemyShip_sprite = 0;
}

void Display::finish(){
    _display.close();
}

void Display::load_and_bind_textures()
{
    // Bind map textures    
    maze_tex.loadFromFile("sprites/maze/screen.png");
    maze_sprite.setTexture(maze_tex);
    maze_sprite.scale(2, 2); //1086 x 746

    // Bind shots textures
    shot_tex.loadFromFile("sprites/space_ships/shot.png");
    shot_sprite.setTexture(shot_tex);
    shot_sprite.scale(-0.5, -0.5);

    // Bind battleShip
    battleShip_0_tex.loadFromFile("sprites/space_ships/space_ship1.png");
    battleShip_1_tex.loadFromFile("sprites/space_ships/space_ship2.png");
    battleShip_2_tex.loadFromFile("sprites/space_ships/space_ship3.png");
    battleShip_3_tex.loadFromFile("sprites/space_ships/space_ship4.png");

    // Bind battleShip textures
    battleShip[0].setTexture(battleShip_0_tex);
    battleShip[0].scale(-0.5, -0.5);

    battleShip[1].setTexture(battleShip_1_tex);
    battleShip[1].scale(-0.5, -0.5);

    battleShip[2].setTexture(battleShip_2_tex);
    battleShip[2].scale(-0.5, -0.5);

    battleShip[3].setTexture(battleShip_3_tex);
    battleShip[3].scale(-0.5, -0.5);


    // Bind enemyShip
    enemyShip_0_tex.loadFromFile("sprites/space_ships/enemy_space_ship1.png");
    enemyShip_1_tex.loadFromFile("sprites/space_ships/enemy_space_ship1.png");
    enemyShip_2_tex.loadFromFile("sprites/space_ships/enemy_space_ship1.png");
    enemyShip_3_tex.loadFromFile("sprites/space_ships/enemy_space_ship1.png");

    // Bind enemyShip textures
    enemyShip[0].setTexture(enemyShip_0_tex);
    enemyShip[0].scale(-0.5, -0.5);
    
    enemyShip[1].setTexture(enemyShip_1_tex);
    enemyShip[1].scale(-0.5, -0.5);
    
    enemyShip[2].setTexture(enemyShip_2_tex);
    enemyShip[2].scale(-0.5, -0.5);
    
    enemyShip[3].setTexture(enemyShip_3_tex);
    enemyShip[3].scale(-0.5, -0.5);
    
    // Bind UI textures
    score_tex.loadFromFile("sprites/ui/score_tex.png");
    score_sprite.setTexture(score_tex);

    ready_tex.loadFromFile("sprites/ui/ready_tex.png");
    ready_sprite.setTexture(ready_tex);
}

//coloquei numeros do calculo que eu fiz rapidinho mas pode precisar de ajustes
//dessa vez nao foi do cu
void Display::draw_maze(){
    int i, j;

    _display.clear();
    
    maze_sprite.setPosition(0,0);
    _display.draw(maze_sprite);

    score_sprite.setPosition(700,20);
    _display.draw(score_sprite);

}

void Display::draw_battleShip(){
    sf::Sprite sprite;
    sprite = battleShip[(int)(battleShip_sprite / 4)];
    sprite.setPosition(50, 50);
}

void Display::draw_enemy(Name name){
    sf::Sprite sprite;
    sprite = enemyShip[(int)(enemyShip_sprite / 4)];
    if (name == ENEMY_TOP_LEFT) {
        sprite.setPosition(15, 15);
    } else if (name == ENEMY_TOP_RIGHT)
    {
        sprite.setPosition(15, 75);
    } else if (name == ENEMY_BOTTOM_LEFT)
    {
        sprite.setPosition(75, 15);

    } else if (ENEMY_BOTTOM_RIGHT)
    {
        sprite.setPosition(75,75);
    }
    
    
    

    
}

void Display::start(){
    draw_enemy(ENEMY_TOP_LEFT);
    draw_enemy(ENEMY_TOP_RIGHT);
    draw_enemy(ENEMY_BOTTOM_LEFT);
    draw_enemy(ENEMY_BOTTOM_RIGHT);
    ready_sprite.setPosition(100,160);
    _display.draw(ready_sprite);
    _display.display();
}

void Display::run()
{
    _display(sf::VideoMode(1090, 750), "SFML works!");

    //Link: https://www.sfml-dev.org/tutorials/2.5/window-events.php
    //https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
    _display.setKeyRepeatEnabled(false);

    while (_display.isOpen())
    {
        sf::Event event;
        while (_display.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                 _display.close();
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
        _display.clear();
        _display.draw(maze_sprite);
                
        space_ship_sprite.setPosition(_interface.get_position_px_x(0),_interface.get_position_px_y(0));
        _display.draw(space_ship_sprite);
        
        //TODO organizar a lógica para colocar todos os inimigos
        enemy_ship_sprite.setPosition(245, 150);
        _display.draw(enemy_ship_sprite);

        //shot_sprite.setPosition(204, 400);
        //_display.draw(shot_sprite);
        
        _display.display();
        
    }
}