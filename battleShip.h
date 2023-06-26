#ifndef battleShip_h
#define battleShip.h

#include <iostream>
#include "char.h"
#include "enum.h"

class BattleShip: public Char{
    public:
        BattleShip(Name name);
        //int BSshots[];
        void reset();
        //void make_shot();
        //void update_shot();
        // void take_hit();
        


};

#endif