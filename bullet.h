//define a bullet structure who runs in the matrix looking for an "e" or "b" char
//if it finds one, it will be deleted and the bullet will be deleted too

#ifndef BULLET_H
#define BULLET_H

#include "bullet.h"
#include <iostream>
#include "enum.h"
#include "interface.h"

class Bullet {
public:
    Bullet(int x, int y, int direction);
    ~Bullet();
    void move();
    int getX();
    int getY();
    int getDirection();
    // void setX(int x);
    // void setY(int y);
    void setDirection(int direction);
private:
    int x;
    int y;
    int direction;
    Tile _maze[32][32];
};

#endif