#ifndef interface_h
#define interface_h

#include <iostream>
#include "enum.h"
#include "battleShip.h"
#include "enemyShip.h"
#include "bullet.h"

class Interface{
    public:
        Interface(BattleShip *player, EnemyShip *enemy_bl, EnemyShip *enemy_br, EnemyShip *enemy_tl, EnemyShip *enemy_tr);
        int get_position_x(Name name);
        int get_position_y(Name name);
        int get_position_px_x(Name name);
        int get_position_px_y(Name name);
        Direction get_direction(Name name);
        int get_points();
        int get_lives();
        int get_level();

        void set_maze();
        void set_position(Name name, int i, int j);
        void set_position_px(Name name);
        void set_direction();
        // serve pra reset tb
        void set_points();

        void add_points(int points);
        void add_level(int level);
        void lose_life(int live);

        void reset_maze();
        void reset_level();
        void reset_lives();

        void get_bullets();
        Tile get_maze();
        void create_bullet(int x, int y, Direction dir);
        Bullet _bullets[32];
        int last_bullet = 0;
        void Interface::process_bullets()
        
        void game_over();

    private:

        static int _positions[5][2]; // 0 e o player, o resto na ordem do enum
        static int _positions_px[5][2]; // posicoes em pixels, 0 e o player resto segue ordem do enum
        static Direction _directions[4]; // Lista de direcoes
        static int _lives;
        static int _level;
        static Tile _maze[32][32];
        static unsigned int _points;
        static BattleShip _player;
        static EnemyShip _enemy_bl; 
        static EnemyShip _enemy_br;
        static EnemyShip _enemy_tl;
        static EnemyShip _enemy_tr;
        
};


#endif