/**
 * Project Untitled
 */


#ifndef _PROJETIL_H
#define _PROJETIL_H

#include "Entidade.h"


class Projetil: public Entidade {
public: 
    
/**
 * @param pos
 * @param vel
 * @param caminho_textura
 * @param n
 */
void Projetil(Vector2F pos, Vector2F vel, const char* caminho_textura, NuvemMal* n);
    
void Projetil();
    
/**
 * @param t
 */
void void executar(float t);
    
/**
 * @param ente
 * @param intersse
 */
void void colidir(Entidade* ente, Vector2F intersse);
private: 
    NuvemMal* nuvem;
};

#endif //_PROJETIL_H