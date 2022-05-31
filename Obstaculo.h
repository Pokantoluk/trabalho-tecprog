#pragma once
#include "Entidade.h"

namespace Game
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Obstaculo :
                public Entidade
            {
            public:
                Obstaculo(Vector2F pos = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr);
                ~Obstaculo();
                void colidir(IDsEntidades::IDsEntidades id_outro, Vector2F pos_outro, Vector2F dimension_outro);
                void inicializar(GerenciadorGrafico& gg, GerenciadorColisoes& gc);
                void atualizar(float t);
                void desenhar(GerenciadorGrafico& g);
                
            };

        }
    }
}


