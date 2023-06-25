#include "char.h"
#include "enum.h"

Char::Char(Name name){
    _name = name;
    _direction = RIGHT;
    set_speed(1);
    _x = _interface.get_position((int)name);
    _y = _interface.get_position((int)name);
    _b_x = 0.0;
    _b_y = 0.0;
    _x_px = _interface.get_position_px((int)name);
    _y_px = _interface.get_position_px((int)name);
}

int Char::get_x(){
    return _x;
}

int Char::get_y(){
    return _y;
}

double Char::get_x_px(){
    return _x_px;
}

double Char::get_y_px(){
    return _y_px;
}

void Char::set_x(int x){
    _x = x;
}

void Char::set_y(int y){
    _y = y;
}

void Char::set_x_px(double x_px){
    _x_px = x_px;
}

void Char::set_y_px(double y_px){
    _y_px = y_px;
}

//Cada nivel a velocidade aumenta - Apenas os Inimigos tem que fazer isso -
void Char::set_speed(double speed){
    _speed = speed * 75/ (15000 - _interface.get_level() * 1000);
}

//Logica de movimento que pode ser usada baseada no nome (ENEMY_TOP/ENEMY_BOTTOM)
void Char::set_direction(Direction direction){

}

//Logica de movimentacao do personagem
int Char::move() {

}

//update na posicao do personagem
void Char::update_position(){

}