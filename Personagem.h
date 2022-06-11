#pragma once
#include "Entidade.h"

namespace Jogo
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Personagem :
                public Entidade
            {
            protected:
                int vidas;
                bool no_chao;
                float mod_vel;
                float tempo_imune;
                float cont_tempo_imune;
            public:
                Personagem(IDsEntidades::IDsEntidades id, Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr, unsigned int vidas = 1);
                ~Personagem() {}
                void machucar(int dano);
                

            };

        }
    }
}

