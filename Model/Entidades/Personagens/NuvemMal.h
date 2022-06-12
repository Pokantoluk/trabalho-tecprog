/**
 * Project Untitled
 */


#ifndef _NUVEMMAL_H
#define _NUVEMMAL_H

#include "Inimigo.h"


class NuvemMal: public Inimigo {
public: 
    void Attribute4;
    
void NuvemMal();
    
void NuvemMal();
    
/**
 * @param t
 */
void void atualizar(float t);
    
/**
 * @param ente
 * @param intersse
 */
void void colidir(Entidade* ente, Vector2F intersse);
    
void void lancar();
    
void void mover();
private: 
    void fase: Fase*;
    float cont_lancar;
    float tem_lancar;
    float temp_mover;
    float cont_mover;
};

#endif //_NUVEMMAL_H