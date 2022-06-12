#pragma once
#include "Obstaculo.h"

namespace Jogo
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Fogo :
                public Obstaculo
            {
            public:
                Fogo(Vector2F pos, const char* caminho_textura);
                ~Fogo();
                void colidir(Entidade* ente, Vector2F intersse);

            };
        }
    }

}