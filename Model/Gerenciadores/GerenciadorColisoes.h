/**
 * Project Untitled
 */


#ifndef _GERENCIADORCOLISOES_H
#define _GERENCIADORCOLISOES_H

class GerenciadorColisoes {
public: 
    void Port1;
    
/**
 * @param m
 * @param e
 */
void GerenciadorColisoes(ListaEntidades* m, ListaEntidades* e);
    
void GerenciadorColisoes();
    
/**
 * @param ente
 * @param index
 * @param estatico
 */
void bool tentar_destruir(Entidade* ente, int index, bool estatico);
    
void void verificar_colisoes();
private: 
    ListaEntidades* moveis;
    ListaEntidades* estaticos;
};

#endif //_GERENCIADORCOLISOES_H