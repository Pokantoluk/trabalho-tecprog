/**
 * Project Untitled
 */


#ifndef _PEDRA_H
#define _PEDRA_H

#include "../../Obstaculo.h"


class Pedra: public Obstaculo {
public: 
    
/**
 * @param pos
 * @param caminho_textura
 */
void Pedra(Vector2F pos, const char* caminho_textura);
    
void Pedra();
    
/**
 * @param ente
 * @param intersse
 */
void void colidir(Entidade* ente, Vector2F intersse);
};

#endif //_PEDRA_H