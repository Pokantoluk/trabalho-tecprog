/**
 * Project Untitled
 */


#ifndef _GERENCIADOREVENTOS_H
#define _GERENCIADOREVENTOS_H

class GerenciadorEventos {
public: 
    static bool escrevendo;
    
void GerenciadorEventos();
    
void GerenciadorEventos();
    
void void tratar_eventos();
    
/**
 * @param janela
 */
void void set_janela(RenderWindow* janela);
    
/**
 * @param e
 */
void static void escrever_nome(const bool e);
    
void static string get_nome();
private: 
    RenderWindow* janela;
    static string nome;
};

#endif //_GERENCIADOREVENTOS_H