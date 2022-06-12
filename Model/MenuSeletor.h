/**
 * Project Untitled
 */


#ifndef _MENUSELETOR_H
#define _MENUSELETOR_H

#include "Menu.h"


class MenuSeletor: public Menu {
public: 
    
/**
 * @param fundo
 */
void MenuSeletor(const char* fundo);
    
void MenuSeletor();
    
void executar();
};

#endif //_MENUSELETOR_H