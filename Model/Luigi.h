/**
 * Project Untitled
 */


#ifndef _LUIGI_H
#define _LUIGI_H

#include "Entidades/Personagens/Jogador.h"


class Luigi: public Jogador {
public: 
    
/**
 * @param pos
 */
void Luigi(Vector2F pos);
    
void Luigi();
    
void void tratar_eventos();
    
void static unsigned int get_pontuacao();
private: 
    static int pontos;
};

#endif //_LUIGI_H