#ifndef enemyShip_h
#define enemyShip_h

#include <iostream>
#include "enum.h"
#include "char.h"
#include <cmath>
#include "bullet.h"
#include "SO/semaphore.h"

class EnemyShip: public Char{
    public:
        EnemyShip(Name name);
        //running/sleeping/etc.
        Mode get_mode();
        void set_mode();
        void make_shot();


        bool is_direction_available(Direction direction);

        void reset();


    private:
        Mode _mode; // N sei se vai ser utilizado
};

#endif