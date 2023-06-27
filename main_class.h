#ifndef main_class_h
#define main_class_h

#include <iostream>
#include "SO/cpu.h"
#include "SO/traits.h"
#include "SO/thread.h"
#include "SO/semaphore.h"
#include "enum.h"
#include "battleShip.h"
#include "enemyShip.h"
#include "interface.h"
#include "display.h"
#include "char.h"

__BEGIN_API

class Main
{
public:
    Main() {}

    static void run(void * name) {
        
    // Instanciar os semaforos
    
    // Instanciar as naves inimigas, battleship, jogo, manipulador de eventos do teclado    
        battleShip = new Thread(battle_ship_behaviour);
        // enemy_bl = new EnemyShip(ENEMY_BOTTOM_LEFT);
        // enemy_br = new EnemyShip(ENEMY_BOTTOM_RIGHT);
        // enemy_tl = new EnemyShip(ENEMY_TOP_LEFT);
        // enemy_tr = new EnemyShip(ENEMY_TOP_RIGHT);
        enemy_bl = new Thread(enemy_bl_behaviour);
        enemy_br = new Thread(enemy_br_behaviour);
        enemy_tl = new Thread(enemy_tl_behaviour);
        enemy_tr = new Thread(enemy_tr_behaviour);
        

        Interface interface = new Interface(&battleShip, &enemy_bl, &enemy_br, &enemy_tl, &enemy_tr);
        Display display = new Display(&interface);

        delete battleShip;
        delete enemy_bl;
        delete enemy_br;
        delete enemy_tl;
        delete enemy_tr;
    }

    ~Main() {}

private:

    
    
    private:
        static Thread *ping_pong_threads[5];
        static Semaphore *sem;
};

__END_API

#endif
