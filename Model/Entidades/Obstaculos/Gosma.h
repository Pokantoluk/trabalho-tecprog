/**
 * Project Untitled
 */


#ifndef _GOSMA_H
#define _GOSMA_H

#include "../../Obstaculo.h"


class Gosma: public Obstaculo {
public: 
    
/**
 * @param pos
 * @param caminho_textura
 */
void Gosma(Vector2F pos, const char* caminho_textura);
    
void Gosma();
    
/**
 * @param ente
 * @param intersse
 */
void void colidir(Entidade* ente, Vector2F intersse);
};

#endif //_GOSMA_H