#include "enemyShip.h"

EnemyShip::EnemyShip(Name name) : Char(name){

}

bool EnemyShip::is_direction_available(Direction direction){
    return true;
}

void EnemyShip::reset() { //reseta posicoes dos inimigos para inicial
    if (name == ENEMY_TOP_LEFT) {
        interface.set_position(ENEMY_TOP_LEFT, 3, 3);
        //interface.set_position_px(ENEMY_TOP_LEFT, &, &);
    } else if (name == ENEMY_TOP_RIGHT)
    {
        interface.set_position(ENEMY_TOP_RIGHT,3,27);
        //interface.set_position_px(ENEMY_TOP_RIGHT, &, &);
    } else if (name == ENEMY_BOTTOM_LEFT)
    {
        interface.set_position(ENEMY_BOTTOM_LEFT, 27, 3);
        //interface.set_position_px(ENEMY_BOTTOM_LEFT, &, &);

    } else if (name == ENEMY_BOTTOM_RIGHT)
    {
        interface.set_position(ENEMY_BOTTOM_RIGHT, 27, 27);
        //interface.set_position_px(ENEMY_BOTTOM_RIGHT, &, &);
    }
}