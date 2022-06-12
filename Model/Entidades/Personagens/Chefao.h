/**
 * Project Untitled
 */


#ifndef _CHEFAO_H
#define _CHEFAO_H

#include "Inimigo.h"


class Chefao: public Inimigo {
public: 
    
/**
 * @param pos
 * @param vel
 * @param caminho_textura
 */
void Chefao(Vector2F pos, Vector2F vel, const char* caminho_textura);
    
void Chefao();
    
/**
 * @param ente
 * @param intersse
 */
void void colidir(Entidade* ente, Vector2F intersse);
};

#endif //_CHEFAO_H