/**
 * Project Untitled
 */


#ifndef _MENU_H
#define _MENU_H

#include "Ente.h"


class Menu: public Ente {
public: 
    
void Menu();
    
void Menu();
    
/**
 * @param t
 */
virtual virtual void executar(float t) = 0;
    
/**
 * @param gm
 */
void set_gm(GerenciadorMenu* gm);
    
void ler_teclado();
private: 
    int pos;
    bool enter;
    Font* fonte;
    vector<unsigned int> pontos;
    GerenciadorMenu* gm;
    vector<string> opcoes;
    vector<Vector2F> coords;
    vector<Text> textos;
};

#endif //_MENU_H