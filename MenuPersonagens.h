#pragma once
#include "Menu.h"
namespace Jogo
{
    class MenuPersonagens :
        public Menu
    {

    public:
        MenuPersonagens(const char* fundo = "assets/menu.png");
        ~MenuPersonagens();
        void executar(float t = 0);
    };


}
