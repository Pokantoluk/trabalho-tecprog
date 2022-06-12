/**
 * Project Untitled
 */


#ifndef _PERSONAGEM_H
#define _PERSONAGEM_H

#include "Entidades/Entidade.h"


class Personagem: public Entidade {
public: 
    
/**
 * @param id
 * @param pos
 * @param vel
 * @param caminho_textura
 */
void Personagem(IDsEntidades id, Vector2F pos, Vector2F vel, const char* caminho_textura);
    
void Personagem();
    
void Operation3();
    
void Operation4();
    
/**
 * @param dando
 */
void void machucar(int dando);
protected: 
    unsigned int vidas;
    bool no_chao;
};

#endif //_PERSONAGEM_H