#include "display.h"

Display::Display(){
    load_and_bind_textures();

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
    maze_sprite.scale(1.5, 1.5);

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

//coloquei numeros do cu
void Display::draw_maze(){
    int i, j;

    _display.clear();
    
    maze_sprite.setPosition(0,30);
    _display.draw(maze_sprite);

    score_sprite.setPosition(120,5);
    _display.draw(score_sprite);

}

void Display::draw_battleShip(){
    sf::Sprite sprite;
    sprite = battleShip[(int)(battleShip_sprite / 4)];
    //sprite.setPosition();
}

void Display::draw_enemy(Name name){
    sf::Sprite sprite;
    sprite = enemyShip[(int)(enemyShip_sprite / 4)];
    //sprite.setPosition();
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