/**
 * Project Untitled
 */


#ifndef _INIMIGO_H
#define _INIMIGO_H

#include "../../Personagem.h"


class Inimigo: public Personagem {
public: 
    
/**
 * @param pos
 * @param vel
 * @param caminho_textura
 * @param vidas
 */
void Inimigo(Vector2F pos, Vector2F vel, const char* caminho_textura, int vidas);
    
void Inimigo();
    
/**
 * @param t
 * @param gg
 */
void void executar(float t, GerenciadorGrafico& gg);
    
/**
 * @param gg
 */
void void inicializar(GerenciadorGrafico& gg);
    
/**
 * @param t
 */
void void atualizar(float t);
    
/**
 * @param ente
 * @param intersse
 */
void virtual void colidir(Entidade* ente, Vector2F intersse);
    
void void bordas();
    
/**
 * @param ente
 */
void bool ObjetoEmCima(Entidade* ente);
};

#endif //_INIMIGO_H