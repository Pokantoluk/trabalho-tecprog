#pragma once
#include "Obstaculo.h"

namespace Game
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Gosma :
                public Obstaculo
            {
            public:
                Gosma(Vector2F pos, const char* caminho_textura);

                void colidir(Entidade* ente, Vector2F intersse);
            };
        }
    }
}