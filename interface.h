#ifndef interface_h
#define interface_h

#include <iostream>
#include "enum.h"

class Interface{
    public:
        int get_position_x(int x);
        int get_position_y(int x);
        int get_position_px_x(int x);
        int get_position_px_y(int x);
        Direction get_direction(int x);
        int get_points();
        int get_lives();
        int get_level();

        void set_maze();
        void set_position(int i, int x);
        void set_position_px(int i, int x);
        void set_direction();
        // serve pra reset tb
        void set_points();

        void add_points(int points);
        void add_level(int level);
        void lose_life(int live);

        void reset_maze();
        void reset_level();
        void reset_lives();

    private:

        static int _positions[5]; // 0 e o player, o resto na ordem do enum
        static int _positions_px[5]; // posicoes em pixels, 0 e o player resto segue ordem do enum
        static Direction _directions[4]; // Lista de direcoes
        static int _lives;
        static int _level;
        static unsigned int _points;
        static Tile _maze[32][32];
        
};


#endif