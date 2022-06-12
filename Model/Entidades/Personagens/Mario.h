/**
 * Project Untitled
 */


#ifndef _MARIO_H
#define _MARIO_H

#include "Jogador.h"


class Mario: public Jogador {
public: 
    
/**
 * @param pos
 */
void Mario(Vector2F pos);
    
void Mario();
    
void void tratar_eventos();
    
void static unsigned int get_pontuacao();
private: 
    static int pontos;
};

#endif //_MARIO_H