#ifndef interface_h
#define interface_h

#include <iostream>
#include "enum.h"

class Interface{
    public:
        int get_position(int x);
        int get_position_px(int x);
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

        static int _positions[4];
        static int _positions_px[4];
        static Direction _directions[4];
        static int _lives;
        static int _level;
        static unsigned int _points;
        
};


#endif