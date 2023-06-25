#ifndef enemyShip_h
#define enemyShip_h

#include <iostream>
#include "enum.h"
#include "char.h"
#include <cmath>

class EnemyShip: public Char{
    public:
        EnemyShip(Name name);
        //running/sleeping/etc.
        Mode get_mode();
        void set_mode();

        bool is_direction_available(Direction direction);

        void reset();

    private:
        Mode _mode; // N sei se vai ser utilizado
};

#endif