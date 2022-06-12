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
            public:
                Bandeira(Vector2F pos = (0,0), const char* caminho_textura = nullptr);
                ~Bandeira();
                
            };
        }
    }
}

