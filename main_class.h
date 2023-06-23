#ifndef main_class_h
#define main_class_h

#include <iostream>
#include "cpu.h"
#include "traits.h"
#include "thread.h"
#include "semaphore.h"
#include "enum.h"
#include "battleShip.h"
#include "enemyShip.h"

__BEGIN_API

class Main
{
public:
    Main() {}

    static void run(void * name) {
        
    // Instanciar os semaforos

    // Instanciar as naves inimigas, battleship, jogo, manipulador de eventos do teclado    
        battleShip = new BattleShip(BattleShip);
        enemy_bl = new EnemyShip(ENEMY_BOTTOM_LEFT);
        enemy_br = new EnemyShip(ENEMY_BOTTOM_RIGHT);
        enemy_tl = new EnemyShip(ENEMY_TOP_LEFT);
        enemy_tr = new EnemyShip(ENEMY_TOP_RIGHT);



    }

    ~Main() {}

private:

    static const int ITERATIONS = 10;

    static void body(char *name, int id)
    {
        int i ;

        std::cout << name << ": inicio\n";

        sem->p();
        for (i = 0; i < ITERATIONS; i++)
        {
            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }
        sem->v();
        std::cout << name << ": fim\n";


        ping_pong_threads[id]->thread_exit(id);
    }

    private:
        static Thread *ping_pong_threads[5];
        static Semaphore *sem;
};

__END_API

#endif
