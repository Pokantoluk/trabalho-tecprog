#pragma once
#include "Obstaculo.h"


namespace Jogo
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Bandeira :
                public Obstaculo
            {
            private:
                bool terminou_fase;
            public:
                Bandeira(Vector2F pos = (0,0), const char* caminho_textura = nullptr);
                ~Bandeira();
                void colidir(Entidade* ente, Vector2F intersse);
                const bool get_fim()const { return terminou_fase; }
            };
        }
    }
}

