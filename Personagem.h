#pragma once
#include "Entidade.h"

namespace Game
{
    namespace Entidades
    {
        class Personagem :
            public Entidade
        {
        protected:
            unsigned int vidas;
            bool no_chao;
        public:
            Personagem(IDsEntidades::IDsEntidades id, Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr, unsigned int vidas = 1);
            ~Personagem(){}
        };
    }
}

