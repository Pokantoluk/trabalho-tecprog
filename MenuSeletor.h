#pragma once
#include "Menu.h"
namespace Jogo
{
    class MenuSeletor :
        public Menu
    {

    public:
        MenuSeletor(const char* fundo = "assets/menu.png");
        ~MenuSeletor();
        void executar(float t = 0);

    };


}
