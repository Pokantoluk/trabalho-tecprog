/**
 * Project Untitled
 */


#ifndef _MENUPRINCIPAL_H
#define _MENUPRINCIPAL_H

#include "Menu.h"


class MenuPrincipal: public Menu {
public: 
    
/**
 * @param fundo
 */
void MenuPrincipal(const char* fundo);
    
void MenuPrincipal();
    
void executar();
};

#endif //_MENUPRINCIPAL_H