#include "bullet.h"

Bullet::Bullet(int x, int y, int direction) {
    this->x = x;
    this->y = y;
    this->direction = direction;
}


Bullet::~Bullet() {
}


void Bullet::move() {
    switch (direction) {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    }
}

int Bullet::getX() {
    return x;
}

int Bullet::getY() {
    return y;
}

int Bullet::getDirection() {
    return direction;
}

// void Bullet::setX(int x) {
//     this->x = x;
// } 

// void Bullet::setY(int y) {
//     this->y = y;
// }

void Bullet::setDirection(int direction) {
    this->direction = direction;
}