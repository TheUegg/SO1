#include "battleShip.h"

BattleShip::BattleShip(Name name): Char(name) {
    set_speed(1.0);
}

//reseta
void BattleShip::reset(){
    interface.set_position(BATTLESHIP, 16, 16);
    //interface.set_position_px(BATTLESHIP, &, &);
}