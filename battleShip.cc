#include "battleShip.h"

BattleShip::BattleShip(Name name): Char(name) {
    set_speed(1.0);
}

//reseta
void BattleShip::reset(){
    interface.set_position(BATTLESHIP, 16, 16);
    //interface.set_position_px(BATTLESHIP, &, &);
}

/*
void BattleShip::make_shot(input){ //cria um vetor de tiros onde cada tiro eh um vetor composto por {x,y,dir}
    new_shot = {BattleShip.get_x(),BattleShip.get_x(),input}
    BSshots.push_back()
}



void BattleShip::update_shot(){
    int size = BSshots.size()
    if size != 0 {
        for (int i = 0; i < size; i++ ) {
            if (BSshots[i][2] == 1) {
                BSshots[i][1]++;
            } else if (BSshots[i][2] == 2) {
                BSshots[i][0]--;
            } else if (BSshots[i][2] == 3) {
                BSshots[i][1]--;
            } else {
                BSshots[i][0]++;
            }
        }
    }
}
*/