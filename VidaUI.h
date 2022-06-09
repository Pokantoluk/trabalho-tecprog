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
        int n_vidas;
    public:
        VidaUI();
        ~VidaUI();
        void executar();
        void atualizar(Entidades::Jogador* jogador);
      
    };

}