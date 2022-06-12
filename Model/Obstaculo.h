/**
 * Project Untitled
 */


#ifndef _OBSTACULO_H
#define _OBSTACULO_H

#include "Entidades/Entidade.h"


class Obstaculo: public Entidade {
public: 
    
/**
 * @param pos
 * @param caminho_textura const char*
 */
void Obstaculo(Vector2F pos, void caminho_textura const char*);
    
void Obstaculo();
    
/**
 * @param t
 */
void void executar(float t);
    
/**
 * @param ente
 * @param intersse
 */
void virtual void colidir(Entidade* ente, Vector2F intersse);
    
void void inicializar();
    
/**
 * @param t
 */
void virtual void atualizar(float t);
    
void virtual void desenhar();
};

#endif //_OBSTACULO_H