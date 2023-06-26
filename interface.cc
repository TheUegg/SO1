#include "interface.h"


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

int Interface::get_position_x(int x){ //0 eh o player, 1 2 3 4 inimigos, ordem do enum
    return _positions[x][0];
}

int Interface::get_position_y(int x){
    return _positions[x][1];
}

int Interface::get_position_px_x(int x){ //Retorna posicao em pixels
    return _positions_px[x][0];
}

int Interface::get_position_px_y(int x){
    return _positions_px[x][1]
}

void Interface::set_position(int x, int i, int j){ //seta personagens no grid usando coordenadas
    _positions[x] = [i,j];
    set_position_px(x); //atualiza a posição na tela junto com a posição no grid
}

void Interface::set_position_px(int x){ // seta personagens na tela usando coordenadas no grid, adicionando offset para encaixar na tela
    _positions_px[x] = [(_positions[x][0]*20)+10,(_positions[x][1]*20)+222];
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
    _positions[0] = [16, 16];
    _positions[1] = [3, 3];
    _positions[2] = [3, 27];
    _positions[3] = [27, 3];
    _positions[4] = [27, 27];

}

