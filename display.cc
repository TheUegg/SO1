#include "display.h"
#include "battleShip.h"

Display::Display(Interface * interface, Input * input){
    load_and_bind_textures();
    _interface = *interface;
    _input = new Input(interface);
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
    playerShip[0].setTexture(battleShip_0_tex);
    playerShip[0].scale(-0.5, -0.5);

    playerShip[1].setTexture(battleShip_1_tex);
    playerShip[1].scale(-0.5, -0.5);

    playerShip[2].setTexture(battleShip_2_tex);
    playerShip[2].scale(-0.5, -0.5);

    playerShip[3].setTexture(battleShip_3_tex);
    playerShip[3].scale(-0.5, -0.5);


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
/*
void Display::draw_battleShip(){
    sf::Sprite sprite;
    sprite = playerShip[(int)(battleShip_sprite / 4)];
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
} */

/*void Display::start(){ //ok isso aqui vai precisar ser refeito pra ser a funcao que soh mostra o ready na tela um pouco antes de chamar o run, que faz o resto
    //draw_enemy(ENEMY_TOP_LEFT);
    //draw_enemy(ENEMY_TOP_RIGHT);
    //draw_enemy(ENEMY_BOTTOM_LEFT);
    //draw_enemy(ENEMY_BOTTOM_RIGHT);
    ready_sprite.setPosition(100,160);
    _display.draw(ready_sprite);
    _display.display();
}*/

void Display::run()
{
    _display = window(sf::VideoMode(1090, 750), "SFML works!");

    ready_sprite.setPosition(100,160);
    _display.draw(ready_sprite);
    _display.display();

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
                    _input.movePlayer(LEFT);
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    std::cout << "Keyboard direita!" << std::endl;
                    _input.movePlayer(RIGHT);
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    std::cout << "Keyboard para baixo!" << std::endl;
                    _input.movePlayer(DOWN);
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    std::cout << "Keyboard para cima!" << std::endl;
                    _input.movePlayer(UP);
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    std::cout << "Keyboard espaco!" << std::endl;
                    //player_.shoot();
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                    std::cout << "Keyboard P!" << std::endl;
                    //main_.pause();
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                    std::cout << "Keyboard Q!" << std::endl;
                    _display.close();
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    std::cout << "Keyboard para R!" << std::endl;
                    _input.reset();
                } else
                    std::cout << "Keyboard pressed = " << event.key.code << std::endl;
                break;
            
            }
        }
        _display.clear();
        _display.draw(maze_sprite);
                
        playerShip[_interface.get_direction(BATTLESHIP)].setPosition(_interface.get_position_px_x(BATTLESHIP),_interface.get_position_px_y(BATTLESHIP));
        _display.draw(playerShip[_interface.get_direction(BATTLESHIP)]);

        enemies[0] = enemyShip[ENEMY_TOP_LEFT].setPosition(_interface.get_position_px_x(ENEMY_TOP_LEFT),_interface.get_position_px_y(ENEMY_TOP_LEFT));
        _display.draw(enemies[0]);

        enemies[1] = enemyShip[ENEMY_TOP_RIGHT].setPosition(_interface.get_position_px_x(ENEMY_TOP_RIGHT),_interface.get_position_px_y(ENEMY_TOP_RIGHT));
        _display.draw(enemies[1]);

        enemies[2] = enemyShip[ENEMY_BOTTOM_LEFT].setPosition(_interface.get_position_px_x(ENEMY_BOTTOM_LEFT),_interface.get_position_px_y(ENEMY_BOTTOM_LEFT));
        _display.draw(enemies[2]);

        enemies[3] = enemyShip[ENEMY_BOTTOM_RIGHT].setPosition(_interface.get_position_px_x(ENEMY_BOTTOM_RIGHT),_interface.get_position_px_y(ENEMY_BOTTOM_RIGHT));
        _display.draw(enemies[3]);

        //shot_sprite.setPosition(204, 400);
        //_display.draw(shot_sprite);
        
        _display.display();
        
    }
}