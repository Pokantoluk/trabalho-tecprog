#pragma once
#include "Obstaculo.h"

namespace Game
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

                void colidir(Entidade* ente, Vector2F intersse);

            };
        }
    }

}