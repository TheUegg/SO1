#ifndef enum_h
#define enum_h

typedef enum {UP_KEY, LEFT_KEY, DOWN_KEY, RIGHT_KEY, PAUSE_KEY, RESTART_KEY, EXIT_KEY} DirectionKey;
typedef enum {UP, LEFT, DOWN, RIGHT} Direction;
typedef enum {BATTLESHIP,ENEMY_TOP_LEFT,ENEMY_TOP_RIGHT,ENEMY_BOTTOM_LEFT, ENEMY_BOTTOM_RIGHT} Name;
typedef enum {} Mode;// n sei se isso vai ser utilizado
typedef enum {f,u,d,l,r,p,q,z,m} Tile;//f- free//|u- up locked|d- down locked|
//l- left locked|r- right locked|
//q- diagonal left/TOP locked| p- diagonal right/TOP locked
//z- diagonal left/BOTTOM locked| m- diagonal right/BOTTOM locked

#endif