#include "enemyShip.h"
#include <stdlib.h>
#include <time.h>
#include <enum.h>

EnemyShip::EnemyShip(Name name) : Char(name){
 srand(time(null));
}

EnemyShip::setInterface(Interface *interface){
    _interface = *interface;
}

bool EnemyShip::is_direction_available(Direction direction){
    return true;
}

void EnemyShip::reset() { //reseta posicoes dos inimigos para inicial
    switch (_name)
    {
    case ENEMY_TOP_LEFT:
        _interface.set_position(ENEMY_TOP_LEFT, 3, 3);       
        break;
    case ENEMY_TOP_RIGHT:
        _interface.set_position(ENEMY_TOP_RIGHT, 3, 27);
        break;
    case ENEMY_BOTTOM_LEFT:
        _interface.set_position(ENEMY_BOTTOM_LEFT, 27, 3);
        break;
    case ENEMY_BOTTOM_RIGHT:
        _interface.set_position(ENEMY_BOTTOM_RIGHT, 27, 27);
        break;
    default:
        break;
    }
    }


void EnemyShip::make_shot(){ //cria um vetor de tiros onde cada tiro eh um vetor composto por {x,y,dir}

    new_shot = {Enemyship.get_x(),EnemyShip.get_y(), dir};
    ESshots.push_back(new_shot);
}


void EnemyShip::update_shot(){
    //int size = ESshots.size()
    if size != 0 {
        for (int i = 0; i < size; i++ ) {
            if (ESshots[i][2] == 1) {
                ESshots[i][1]++;
            } else if (BSshots[i][2] == 2) {
                ESshots[i][0]--;
            } else if (BSshots[i][2] == 3) {
                ESshots[i][1]--;
            } else {
                ESshots[i][0]++;
            }
        }
    }
}

void EnemyShip::take_hit() { //acionada quando toma bala
    _interface.add_points();
}

void EnemyShip::move() { // faz a movimentacao do inimigo
    int dir = rand() % 4;
    Direction select = dir;
    switch (select)
    {
    case UP:
        _interface.set_position(_name, get_position_x(_name), get_position_(_name) + 1);
        break;
    case LEFT:
        _interface.set_position(_name, get_position_x(_name) - 1, get_position_(_name));
        break;
    case DOWN:
        _interface.set_position(_name, get_position_x(_name), get_position_(_name) - 1);
        break;
    case RIGHT:
        _interface.set_position(_name, get_position_x(_name) + 1, get_position_(_name));
        break;
    default:
        break;
    }
}