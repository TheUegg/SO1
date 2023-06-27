#include "interface.h"

Interface::Interface(BattleShip *player, EnemyShip *enemy_bl, EnemyShip *enemy_br, EnemyShip *enemy_tl, EnemyShip *enemy_tr){
    _player = *player;
    _enemy_bl = *enemy_bl;
    _enemy_br = *enemy_br;
    _enemy_tl = *enemy_tl;
    _enemy_tr = *enemy_tr;
    reset_maze();
}

//DEFINIR O MAZE
    Tile Interface::_maze[32][32] = {
        {q,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,p},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {l,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,r},
        {z,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,m}
    };
//

unsigned int Interface::_points = 0;

int Interface::_lives = 3;
int Interface::_level = 1;

int Interface::get_lives(){ //retorna o numero de vidas
    return _lives;
}

int Interface::get_level(){ //retorna level
    return _level;
}

int Interface::get_points(){
    return _points; //Retorna o Numero de Pontos
}

int Interface::get_position_x(Name name){ //0 eh o player, 1 2 3 4 inimigos, ordem do enum
    return _positions[name][0];
}

int Interface::get_position_y(Name name){
    return _positions[name][1];
}

int Interface::get_position_px_x(Name name){ //Retorna posicao em pixels
    return _positions_px[name][0];
}

int Interface::get_position_px_y(Name name){
    return _positions_px[name][1];
}

//typedef enum {BATTLESHIP,ENEMY_TOP_LEFT,ENEMY_TOP_RIGHT,ENEMY_BOTTOM_LEFT, ENEMY_BOTTOM_RIGHT} Name;
Direction get_direction(Name name){
    switch(name){
        case BATTLESHIP:
            return _player.get_direction();
        case ENEMY_TOP_LEFT:
            return _enemy_tl.get_direction();
        case ENEMY_TOP_RIGHT:
            return _enemy_tr.get_direction();
        case ENEMY_BOTTOM_LEFT:
            return _enemy_bl.get_direction();
        case ENEMY_BOTTOM_RIGHT:
            return _enemy_br.get_direction();
    }
}

void Interface::set_position(Name name, int i, int j){ //seta personagens no grid usando coordenadas
    _maze[get_position_x(name)][get_position_y(name)] = f;
    _positions[name][0] = i;
    _positions[name][1] = j;
    set_position_px(name); //atualiza a posicao na tela junto com a posicao no grid
    switch(name){
        case BATTLESHIP:
            _maze[get_position_x(name)][get_position_y(name)] = x;
            break;
        case ENEMY_TOP_LEFT:
            _maze[get_position_x(name)][get_position_y(name)] = c;
            break;
        case ENEMY_TOP_RIGHT:
            _maze[get_position_x(name)][get_position_y(name)] = v;
            break;
        case ENEMY_BOTTOM_LEFT:
            _maze[get_position_x(name)][get_position_y(name)] = g;
            break;
        case ENEMY_BOTTOM_RIGHT:
            _maze[get_position_x(name)][get_position_y(name)] = n;
            break;
        default:
            break;
    }
}

void Interface::set_position_px(Name name){ // seta personagens na tela usando coordenadas no grid, adicionando offset para encaixar na tela
    _positions_px[name][0] = (_positions[name][0]*20)+10;
    _positions_px[name][1] = (_positions[name][1]*20)+222;
}



void Interface::add_points(int points){ //incrementa pontuacao
    _points += 100;
}

void Interface::lose_life(int live){ // decrementa vida
    _lives--;
}

void Interface::add_level(int level){ //incrementa o nivel
    _level++;
}

void Interface::reset_level(){ //reinicia o nivel para 1
    _level = 1;
}

void Interface::reset_lives(){ //reinicia o contador de vidas para 3
    _lives = 3;
}

//retorna td pra posicao inicial no estado inicial
void Interface::reset_maze(){
    _positions[0][0] = 16;
    _positions[0][1] = 16;

    _positions[1][0] = 3;
    _positions[1][1] = 3;

    _positions[2][0] = 3;
    _positions[2][1] = 27;

    _positions[3][0] = 27;
    _positions[3][1] = 3;
    
    _positions[4][0] = 27;
    _positions[4][1] = 27;

}

void Interface::create_bullet(int x, int y, Direction dir){
    //cria uma nova bullet no array de bullets e insere um "b" no _maze na posição da bullet
    _maze[x][y] = b;
    _bullets[last_bullet] = Bullet(x, y, dir);
    last_bullet++;
}

void Interface::process_bullets(){
    for (int z = 0; z < last_bullet; z++){
        _bullets[z].move();
        int y = _bullets[z].getY();
        int x = _bullets[z].getX();
        if (_maze[x][y] == 'x'){
            _bullets[z] = _bullets[last_bullet];
            last_bullet--;
            _points += 100;
        }
        if (_maze[x][y] == 'c' or _maze[x][y] == 'g' or _maze[x][y] == 'v' or _maze[x][y] == 'n'){
            _bullets[z] = _bullets[last_bullet];
            last_bullet--;
            _points += 100;
        }
        if (_maze[x][y] == 'q' or _maze[x][y] == 'p' or _maze[x][y] == 'z' or _maze[x][y] == 'm' or _maze[x][y] == 'u' or _maze[x][y] == 'd' or _maze[x][y] == 'l' or _maze[x][y] == 'r'){
            _bullets[z] = _bullets[last_bullet];
            last_bullet--;
        }

    }
}