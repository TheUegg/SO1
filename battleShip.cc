#include "battleShip.h"

BattleShip::BattleShip(Name name, Interface *interface): Char(name) {
    set_speed(1.0);
    _interface = *interface;
}


void BattleShip::reset(){ //reseta
    _interface.set_position(BATTLESHIP, 16, 16);
    //interface.set_position_px(BATTLESHIP, &, &);
}


void BattleShip::make_shot(){ //chama a funcao da interface para criar bala
    _interface.create_bullet(get_x(), get_y(), _direction);
    
}


void BattleShip::take_hit(){ //acionada quando toma bala dos inimigos
    int live = _interface.get_lives();
    _interface.lose_life(live);
    //game over
    if(live == 1){
        _interface.reset_maze();
    }
}

void BattleShip::move(Direction direction){
    if (_direction == UP){
        if(is_next_tile_available(UP))
            int x = _interface.get_position_x(BATTLESHIP);
            int y = _interface.get_position_y(BATTLESHIP);
            _interface.set_position(BATTLESHIP, x, y-1);
    }else if (_direction == LEFT){
        if(is_next_tile_available(LEFT))
            int x = _interface.get_position_x(BATTLESHIP);
            int y = _interface.get_position_y(BATTLESHIP);
            _interface.set_position(BATTLESHIP, x-1, y);
    }else if (_direction == RIGHT){
        if(is_next_tile_available(RIGHT))
            int x = _interface.get_position_x(BATTLESHIP);
            int y = _interface.get_position_y(BATTLESHIP);
            _interface.set_position(BATTLESHIP, x+1, y);
    }else if (_direction == DOWN){
        if(is_next_tile_available(DOWN))
            int x = _interface.get_position_x(BATTLESHIP);
            int y = _interface.get_position_y(BATTLESHIP);
            _interface.set_position(BATTLESHIP, x, y+1);
    }
    
}

//FAZER
bool is_next_tile_available(Direction direction, int x, int y){
    if (direction == UP and _interface._maze[x][y] == u or _interface._maze[x][y] == q or _interface._maze[x][y] == p){
        return false;
    }else if (direction == LEFT and _interface._maze[x][y] == l or _interface._maze[x][y] == q or _interface._maze[x][y] == z){
        return false;
    }else if (direction == RIGHT and _interface._maze[x][y] == r or _interface._maze[x][y] == p or _interface._maze[x][y] == m){
        return false;
    }else if (direction == DOWN and _interface._maze[x][y] == d or _interface._maze[x][y] == z or _interface._maze[x][y] == z){
        return false;
    }
    return true;
}