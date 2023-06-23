#include "enemyShip.h"

EnemyShip::EnemyShip(Name name) : Char(name){

}

bool EnemyShip::is_direction_available(Direction direction){
    return true;
}