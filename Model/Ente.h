/**
 * Project Untitled
 */


#ifndef _ENTE_H
#define _ENTE_H

class Ente {
public: 
    
/**
 * @param posicao
 * @param caminho
 * @param id
 */
void Ente(Vector2F posicao, const char* caminho, IDsEntidades id);
    
void Ente();
    
/**
 * @param t
 */
void virtual void executar(float t);
    
void virtual void imprimir_se();
protected: 
    IDsEntidades id;
    const char* caminho;
    Vector2F posicao;
};

#endif //_ENTE_H