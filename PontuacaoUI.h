#pragma once
#include "ComponenteGrafico.h"
#include "Vector2D.h"
#include "Jogador.h"


namespace Jogo
{
    class PontuacaoUI :
        public ComponenteGrafico
    {
    private:
        sf::Text texto_pontuacao;
        sf::Font* fonte;

    public:
        PontuacaoUI();
        ~PontuacaoUI();
        void executar();

    };

}