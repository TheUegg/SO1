#include "char.h"
#include "enum.h"

Char::Char(Name name){
    _name = name;
    _direction = RIGHT;
    set_speed(1);
    _x = _interface.get_position_x(Name name);
    _y = _interface.get_position_y(Name name);
    _b_x = 0.0;
    _b_y = 0.0;
    _x_px = _interface.get_position_px_x(Name name);
    _y_px = _interface.get_position_px_y(Name name);
}

int Char::get_x(){ //Retorna X da posicao
    return _x;
}

int Char::get_y(){ // Retorna Y da posicao
    return _y;
}

double Char::get_x_px(){ //Retorna X da posicao pixels
    return _x_px;
}

double Char::get_y_px(){ //Retorna Y da posicao pixels
    return _y_px;
}

void Char::set_x(int x){ //Seta posicao X
    _x = x;
}

void Char::set_y(int y){ //Seta posicao Y
    _y = y;
}

void Char::set_x_px(double x_px){ //Seta posicao X em pixels
    _x_px = x_px;
}

void Char::set_y_px(double y_px){ //Seta posicao Y em pixels
    _y_px = y_px;
}

//Cada nivel a velocidade aumenta - Apenas os Inimigos tem que fazer isso -
void Char::set_speed(double speed){
    _speed = speed * 75/ (15000 - _interface.get_level() * 1000);
}

//Logica de movimento que pode ser usada baseada no nome (ENEMY_TOP/ENEMY_BOTTOM)
void Char::set_direction(Direction direction){ // nao usada???

}

Direction Char::get_direction(){ // retorna direcao do char
    return _direction;
}

//Logica de movimentacao do personagem
int Char::move() { // nao usada
    
}

//update na posicao do personagem
void Char::update_position(){ // nao usada

}