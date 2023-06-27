#include "enemyShip.h"
#include <stdlib.h>
#include <time.h>


EnemyShip::EnemyShip(Name name) : Char(name){
 srand(time(null));
}

EnemyShip::setInterface(Interface *interface){
    _interface = *interface;
}


bool EnemyShip::is_direction_available(Direction direction){
    return true;
}

void EnemyShip::wakeup(){
    Mode _mode = RUN;
}

void EnemyShip::reset() { //reseta posicoes dos inimigos para inicial
    switch(_name)
    {
    case ENEMY_TOP_LEFT:
        _interface.set_position(ENEMY_TOP_LEFT, 3, 3);
        //interface.set_position_px(ENEMY_TOP_LEFT, &, &);
        break;
    case ENEMY_TOP_RIGHT:
        _interface.set_position(ENEMY_TOP_RIGHT,3,27);
        //interface.set_position_px(ENEMY_TOP_RIGHT, &, &);
        break;
    case ENEMY_BOTTOM_LEFT:
        _interface.set_position(ENEMY_BOTTOM_LEFT, 27, 3);
        //interface.set_position_px(ENEMY_BOTTOM_LEFT, &, &);
        break;
    case ENEMY_BOTTOM_RIGHT:
        _interface.set_position(ENEMY_BOTTOM_RIGHT, 27, 27);
        //interface.set_position_px(ENEMY_BOTTOM_RIGHT, &, &);
        break;
    default:
        break;
    }
}


void EnemyShip::make_shot(){ //dispara e passa para interface
    _interface.create_bullet(get_x(), get_y(), _direction);
    
}



void EnemyShip::take_hit() { //acionada quando toma bala
    _interface.add_points();
    set_mode(SLEEP);
    Semaphore.p();

}

void EnemyShip::set_mode(Mode mode) { //seta modo da thread da nave inimiga
    _mode = mode;
}

Mode EnemyShip::get_mode() { //retorna o modo da nave inimiga
    return _mode;
}

void EnemyShip::move() { // faz a movimentacao do inimigo
    int dir = rand() % 4;
    Direction select = dir;
    
    switch (select)
    {
    case UP:
        _interface.set_position(_name, get_position_x(_name), get_position_y(_name) - 1);
        break;
    case LEFT:
        _interface.set_position(_name, get_position_x(_name) - 1, get_position_y(_name));
        break;
    case DOWN:
        _interface.set_position(_name, get_position_x(_name), get_position_y(_name) + 1);
        break;
    case RIGHT:
        _interface.set_position(_name, get_position_x(_name) + 1, get_position_y(_name));
        break;
    default:
        break;
    }
}

