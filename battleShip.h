#ifndef battleShip_h
#define battleShip.h

#include <iostream>
#include "char.h"
#include "enum.h"
#include "interface.h"

class BattleShip: public Char{
    public:
        BattleShip(Name name, Interface *interface);
        void reset();
        void make_shot();
        void take_hit();
        void move(Direction direction);
        bool is_next_tile_available(Direction direction);

    private:
        Interface _interface;

};

#endif