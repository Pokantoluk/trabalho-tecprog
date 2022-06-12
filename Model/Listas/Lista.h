/**
 * Project Untitled
 */


#ifndef _LISTA_H
#define _LISTA_H

template<Class TL >
class Lista {
public: 
    
void Lista();
    
void Lista();
    
/**
 * @param info
 */
void void inserir(TL* info);
    
void void esvaziar();
    
void TL* voltar_inicio();
    
void TL* proximo();
    
/**
 * @param x
 */
void TL* operator[](int x);
    
/**
 * @param index
 */
void void remover(int index);
private: 
    Elemento<TL>* inicio;
    Elemento<TL>* fim;
    Elemento<TL>* atual;
};

#endif //_LISTA_H