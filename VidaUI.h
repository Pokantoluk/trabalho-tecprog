#pragma once
#include "ComponenteGrafico.h"
#include "Vector2D.h"


namespace Game
{
    class VidaUI :
        public ComponenteGrafico
    {
    private:
        Vector2F poss[5];
        int n_vidas;
    public:
        VidaUI(Entidades::Jogador* jog);
        ~VidaUI();
        void executar();
        
    };

}