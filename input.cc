#include "input.h"


Input::input(Interface * interface){
    _interface = *interface;
}

void movePlayer(Direction direc){
    switch (direc)
    {
    case UP:
        _interface->set_position(0, _interface->get_position_x(0), _interface->get_position_y(0)-1);
        break;
    case LEFT:
        _interface->set_position(0, _interface->get_position_x(0)-1, _interface->get_position_y(0));
        break;
    case DOWN:
        _interface->set_position(0, _interface->get_position_x(0), _interface->get_position_y(0)+1);
        break;
    case RIGHT:
        _interface->set_position(0, _interface->get_position_x(0)+1, _interface->get_position_y(0));
        break;
    default:
        break;
    }
}

void shootPlayer();

void pause();

void reset(){
    _interface->reset_level();
    _interface->reset_lives();
    _interface->reset_maze();
}

