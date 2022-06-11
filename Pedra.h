#pragma once
#include "Obstaculo.h"

namespace Jogo
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Pedra :
                public Obstaculo
            {
            public:
                Pedra(Vector2F pos, const char* caminho_textura);

                void colidir(Entidade* ente, Vector2F intersse);

            };
        }
    }

}