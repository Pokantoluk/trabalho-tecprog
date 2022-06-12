/**
 * Project Untitled
 */


#ifndef _FOGO_H
#define _FOGO_H

#include "../../Obstaculo.h"


class Fogo: public Obstaculo {
public: 
    
/**
 * @param pos
 * @param caminho_textura
 */
void Fogo(Vector2F pos, const char* caminho_textura);
    
void Fogo();
    
/**
 * @param ente
 * @param intersse
 */
void void colidir(Entidade* ente, Vector2F intersse);
};

#endif //_FOGO_H