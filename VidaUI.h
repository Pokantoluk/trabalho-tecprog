#pragma once
#include "ComponenteGrafico.h"
#include "Vector2D.h"
#include "Jogador.h"


namespace Game
{
    class VidaUI :
        public ComponenteGrafico
    {
    private:
        Vector2F poss[5];
    public:
        VidaUI(Entidades::Personagens::Jogador* jog = nullptr);
        ~VidaUI();
        void executar();
        
    };

}