#pragma once
#include "Obstaculo.h"
namespace Jogo
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Plataforma :
                public Obstaculo
            {
            public:
                Plataforma(Vector2F pos, const char* caminho_textura);
                ~Plataforma();

                void colidir(Entidade* ente, Vector2F intersse);

            };
        }
    }

}