#pragma once
#include "Menu.h"

namespace Jogo
{
    class MenuGameover :
        public Menu
    {
    private:
        

    public:
        MenuGameover(const char* fundo = "assets/placar.png");
        ~MenuGameover();

        void executar(float t = 0);
        void executar_2();

    };

}