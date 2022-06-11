#pragma once
#include "Menu.h"


namespace Jogo
{
    class MenuPrincipal :
        public Menu
    {

    public:
        MenuPrincipal(const char* fundo = "assets/menu.png");
        ~MenuPrincipal();
        void executar(float t = 0);

    };

}

