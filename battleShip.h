#ifndef battleShip_h
#define battleShip.h

#include <iostream>
#include "char.h"
#include "enum.h"

class BattleShip: public Char{
    public:
        BattleShip(Name name);
        void reset();

};

#endif