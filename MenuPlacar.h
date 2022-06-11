#pragma once
#include "Menu.h"
namespace Jogo
{
    class MenuPlacar :
        public Menu
    {

    public:
        MenuPlacar(const char* fundo = "assets/placar.png");
        ~MenuPlacar();

        void valores();
        void executar(float t = 0);
       
    };


}
