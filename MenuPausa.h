#pragma once
#include "Menu.h"


namespace Jogo
{
    class MenuPausa :
        public Menu
    {

    public:
        MenuPausa(const char* fundo = "assets/pausa.png");
        ~MenuPausa();
        void executar(float t = 0);

    };

}

