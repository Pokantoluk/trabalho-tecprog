/**
 * Project Untitled
 */


#ifndef _GOOMBA_H
#define _GOOMBA_H

#include "Inimigo.h"


class Goomba: public Inimigo {
public: 
    
/**
 * @param pos
 * @param vel
 * @param caminho_textura
 */
void Goomba(Vector2F pos, Vector2F vel, const char* caminho_textura);
    
void Goomba();
    
/**
 * @param ente
 * @param intersse
 */
void void colidir(Entidade* ente, Vector2F intersse);
};

#endif //_GOOMBA_H