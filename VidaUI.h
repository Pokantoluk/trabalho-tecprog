#pragma once
#include "ComponenteGrafico.h"
#include "Vector2D.h"
#include "Jogador.h"


namespace Jogo
{
    class VidaUI :
        public ComponenteGrafico
    {
    
    public:
        VidaUI(Entidades::Personagens::Jogador* jog = nullptr);
        ~VidaUI();
        void executar();
        
    };

}