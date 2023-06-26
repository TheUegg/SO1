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


void EnemyShip::make_shot(){ //cria um vetor de tiros onde cada tiro eh um vetor composto por {x,y,dir}
    //dir = escolhe uma direcao random
    new_shot = {Enemyship.get_x(),EnemyShip.get_y(),};
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

void EnemyShip::take_hit(){ //acionada quando toma bala
    interface.add_points();
}