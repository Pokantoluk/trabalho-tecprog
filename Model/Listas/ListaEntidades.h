/**
 * Project Untitled
 */


#ifndef _LISTAENTIDADES_H
#define _LISTAENTIDADES_H

class ListaEntidades {
public: 
    
void ListaEntidades();
    
void ListaEntidades();
    
/**
 * @param info
 */
void void inserir(Entidade* info);
    
/**
 * @param i
 */
void Entidade* operator[](int i);
    
/**
 * @param i
 */
void void remover(int i);
    
void void inicializar_entidades();
    
/**
 * @param t
 */
void void percorrer_executar(float t);
    
void void destruir();
    
void unsigned int get_tam();
private: 
    Lista<Entidade> lista;
    unsigned int tam;
};

#endif //_LISTAENTIDADES_H